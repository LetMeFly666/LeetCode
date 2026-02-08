#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""\
基于无人机群的 Bad Apple 黑白像素表演模拟脚本（含帧跳过同步与导出显示互斥）
=====================================================================

本脚本使用固定数量的“无人机”（二维平面上的点）来近似还原 Bad Apple 的黑白像素视频：
每架无人机只有亮/灭两种状态，可以在平面上移动，但速度存在上限，并且任意两机之间
必须保持不小于给定最小间距。脚本支持：

- Poisson Disk（蓝噪声）采样生成目标点，形状还原度更高（也可选择 K-Means 聚类）；
- 自动反色 auto_invert，使得黑/白背景切换时尽量始终以“主体”为亮点；
- 近邻网格斥力（grid 模式），在大量无人机时降低 CPU 占用；
- 并发读帧管线（解码线程 + 主处理线程），提高帧处理吞吐；
- 小窗播放（window_scale），可缩放显示窗口尺寸而不影响内部舞台计算；
- 实时播放采用“墙钟时间轴 + 帧跳过（frame skipping）”保证音画同步：
  * 解码线程为每个源帧分配单调递增的 frame_idx（从 0 开始）；
  * 主线程根据 expected_index = floor((now - t_start) * fps) 计算当前时间轴应处于的帧号；
  * 快速丢弃队列中 idx < expected_index 的过期帧，只处理“最接近当前时间轴”的帧；
  * 无人机物理更新使用 dt = (processed_index - previous_index) / fps，将跳过帧对应的时间
    合并为较大的时间步长，从而保证轨迹连续而无需逐帧补算；
- 导出模拟结果为视频，并自动从输入 MP4 中提取音轨合并生成带声 MP4。

特别说明：导出与显示互斥
-------------------------

- 若指定 --output_video，则脚本进入离线“仅导出模式”（export-only）：
  * 不创建或显示任何 OpenCV 窗口（不调用 imshow / waitKey）；
  * 强制关闭音频播放（忽略 --play_audio）；
  * 不做墙钟调度与帧跳过，而是逐帧顺序处理整个视频流；
  * 仍按源视频 FPS 写出画面，并在结束后调用 ffmpeg 复用原视频音轨生成最终输出；
- 若未指定 --output_video，则进入实时播放模式（live）：
  * 按墙钟时间轴调度画面，并在落后时通过 frame skipping 丢弃过期帧以追赶音轨；
  * 可选通过 ffplay 播放输入视频音轨，做到“所见即所听”；
  * 支持 window_scale 调整显示窗口大小。

1. 目标点生成与无人机调度概览
-------------------------------

1) 亮像素提取与目标生成

- 每帧将输入视频缩放到舞台尺寸 (width, height)，并转换为灰度图；
- 结合 threshold / auto_invert / invert 得到最终二值图 binary，其中非零像素视为“亮”；
- 从亮像素中随机下采样至不超过 max_samples 个候选点；
- 根据 target_mode 生成每帧的“目标点”集合：
  * poisson：在候选点上执行近似 Poisson Disk 采样，确保任意两个目标间距 ≥ min_gap，
    最多生成 max_targets 个目标；
  * kmeans：使用 OpenCV 的 kmeans，在候选点上聚类出 K 个中心，其中
    K = min(max_clusters, max_targets, 亮像素数)。

2) 目标 ID 稳定追踪

- 对相邻帧的目标点做最近邻贪心匹配，维护连续的整数 ID：
  * 旧目标与新目标两两计算距离，按距离从小到大匹配；
  * 匹配成功则沿用旧 ID，未匹配的新目标分配新的 ID；
  * 未匹配的旧目标在本帧消失。
- 这样可以减少目标编号的跳变，为无人机提供相对平滑的跟踪轨迹。

3) 无人机分配与“中途熄灭”

- 初始化时在舞台底部区域为每架无人机随机生成一个“驻留位置”（home 位置），并通过
  简单拒绝采样保证任意两机之间的初始距离不小于 min_gap；
- 每帧按如下策略为无人机分配目标：
  * 保留所有仍然存在的旧绑定（无人机之前跟随的目标 ID 若仍在 targets 中，则继续跟随）；
  * 剩余无人机与剩余目标点之间按就近贪心匹配，一对一分配；
  * 被分配到目标的无人机处于“亮”状态；未分配目标的无人机处于“灭”状态，
    不再跟随任何视频目标，而是缓慢回到各自 home 位置。

因此：无人机总数固定，但每帧亮着的数量会随画面亮部与 max_targets 变化而动态调整；
无人机可以在表演过程中中途熄灭或再次被点亮，这是设计行为。

4) 社交力模型与 near-neighbor 斥力

- 对每帧，每架无人机的运动由两部分组成：
  * 吸引：指向目标点（或 home），速度大小不超过 max_speed，且不会在单步中越过目标；
  * 斥力：当两机间距小于 min_gap 时，沿连线方向施加对称反向位移，将二者推离，强度由
    repulsion_strength 控制。
- 斥力计算有两种模式（通过 --repulsion_mode 选择）：
  * grid（默认）：将舞台按 cell_size≈min_gap 划分网格，仅在每架无人机所在格及其 3x3
    邻域内检查配对，显著降低 O(N^2) 计算量；
  * naive：保留全量两两检查（O(N^2)），仅作对比与调试。

5) 帧跳过同步（仅实时模式）
----------------------------

- 解码端（Producer）为每个源帧赋予单调递增的 frame_idx（从 0 开始）；
- 实时播放时记录起始时间 t_start（音频开启时与 ffplay 启动尽量对齐）；
- 任意时刻的理论帧号为：expected_index = floor((now - t_start) * fps)；
- 主线程在取帧时会丢弃队列中所有 idx < expected_index 的帧，仅保留第一个
  idx >= expected_index 的帧作为当前要处理的帧；
  * threads>=2：从读帧队列中快速弹出并丢弃过期帧；
  * threads<2：在主线程中循环 cap.read() 丢弃旧帧，直到赶上 expected_index；
- 无人机物理更新的时间步长使用

    dt = (processed_index - previous_index) / fps

  将被跳过帧对应的时间一并融入当前步长，保证轨迹连续而无需逐帧补算。

2. 并发读帧与音画同步
-----------------------

- 当 threads >= 2 时，启用解码线程 + 有界队列（queue_size 控制深度）：
  * Producer 线程持续解码并缩放成舞台尺寸，将 (frame_idx, frame) 放入队列；
  * 主线程根据 expected_index 从队列中取帧并做帧跳过；
- 当 threads < 2 时，退化为单线程模式，主线程直接从 VideoCapture 读取并按 expected_index
  丢弃过期帧；
- 若系统安装了 ffplay 且 play_audio 未被禁用，则在开始时通过

    ffplay -nodisp -autoexit -loglevel error -i input.mp4

  播放输入视频音轨；
- 实时播放的渲染时间与源时间轴对齐：

    t_target = t_start + processed_index / fps

  对每帧在绘制完成后，根据 (t_target - now) 做短暂 sleep（若为负则不等待），并通过
  cv2.waitKey(1) 响应键盘事件（例如按 Q 退出）。

3. 导出模式（export-only）
--------------------------

- 通过 --output_video 指定输出 MP4 时，进入仅导出模式：
  * 不创建或显示任何窗口；
  * 自动禁用音频播放（忽略 --play_audio）；
  * 不使用墙钟时间轴与帧跳过，严格按源视频帧序逐帧计算与写出；
- 使用 OpenCV VideoWriter 先生成一个无音轨临时 MP4（fourcc=mp4v，fps=源 fps，尺寸为舞台
  宽高）；
- 若系统安装了 ffmpeg，则在结束后自动调用 ffmpeg 将临时无音轨视频与输入 MP4 的音轨
  复用生成最终输出：

  1) 先尝试直接复用编码参数（copy）：

     ffmpeg -y -i tmp_noaudio.mp4 -i input.mp4 \
            -map 0:v:0 -map 1:a:0 -c:v copy -c:a copy -shortest output.mp4

  2) 若失败，则退化为重新编码视频轨：

     ffmpeg -y -i tmp_noaudio.mp4 -i input.mp4 \
            -map 0:v:0 -map 1:a:0 -c:v libx264 -pix_fmt yuv420p \
            -c:a copy -shortest output.mp4

- 合并成功后删除临时无音轨文件；若系统无 ffmpeg，则仅保留无音轨临时视频并给出提示。

4. 命令行参数（常用）
---------------------

- --video (必选)：Bad Apple 视频文件路径（mp4/avi 等）。
- --num_drones：无人机数量，默认 300。
- --width, --height：舞台画布宽和高（像素），同时也是视频缩放后的尺寸。
- --min_gap：无人机之间的最小安全距离（像素），也用于 Poisson 采样点间距。
- --max_speed：无人机最大速度（像素/秒）。
- --threshold：灰度二值化阈值（0~255），默认 200。
- --auto_invert / --no_auto_invert：是否开启自动反色（默认开启）。
- --invert：强制使用反向二值化，将暗像素视为亮像素（优先级高于 auto_invert）。
- --target_mode：目标点生成模式，可选 poisson 或 kmeans，默认 poisson。
- --max_targets：每帧最多目标点数量，默认等于 num_drones。
- --max_clusters：在 kmeans 模式下每帧最大聚类数。
- --max_samples：候选亮像素最大样本数，用于控制性能。
- --repulsion_strength：斥力强度系数，适当增大可增强防碰撞能力。
- --repulsion_mode：斥力计算模式，grid 为近邻网格（默认），naive 为全量两两检查。
- --queue_size：多线程读帧队列长度（帧数上限），默认 16。
- --threads：线程数，>=2 时启用解码线程，<2 时退化为单线程。
- --drone_radius：绘制无人机时的圆半径（像素）。
- --overlay_scale：左上角原视频缩略图相对于舞台宽度的缩放比例。
- --window_scale：显示窗口缩放比例，仅影响显示，不改变舞台尺寸（默认 1.0）。
- --play_audio / --no_play_audio：是否通过 ffplay 播放输入视频音轨（实时模式有效）。
- --output_video：导出带音轨的 MP4 输出路径；指定后自动进入仅导出模式（无窗口、无音频）。
- --no_show_original：不在画面角落叠加原始视频缩略图。

5. 运行示例
------------

1) 实时小窗播放 + 音画同步（不导出）：

    python drone_bad_apple_sim.py --video ./bad_apple.mp4 \
        --num_drones 300 --width 960 --height 720 \
        --min_gap 8 --max_speed 200 --threshold 200 \
        --threads 2 --queue_size 32 --target_mode poisson \
        --window_scale 0.5

2) 仅导出带音轨 MP4（无窗口显示）：

    python drone_bad_apple_sim.py --video ./bad_apple.mp4 \
        --num_drones 300 --width 960 --height 720 \
        --min_gap 8 --max_speed 200 --threshold 200 \
        --threads 2 --queue_size 32 --target_mode poisson \
        --output_video ./bad_apple_drones.mp4

运行时按 Q 可提前结束实时播放。
"""

import argparse
import sys
import time
import math
import random
import threading
import queue
import os
import shutil
import subprocess

try:
    import numpy as np
except ImportError:
    print("本脚本依赖 numpy，请先安装：pip install numpy")
    sys.exit(1)

try:
    import cv2
except ImportError:
    print("本脚本依赖 OpenCV (opencv-python)，请先安装：pip install opencv-python")
    sys.exit(1)


class Drone:
    """简单的二维无人机模型。"""

    def __init__(self, idx, pos, home_pos):
        self.idx = idx
        self.pos = np.array(pos, dtype=np.float32)
        self.vel = np.zeros(2, dtype=np.float32)
        self.home_pos = np.array(home_pos, dtype=np.float32)
        self.target_id = None
        self.active = False


def parse_args():
    """解析命令行参数。"""
    parser = argparse.ArgumentParser(
        description="固定数量无人机模拟 Bad Apple 黑白像素表演",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter,
    )

    parser.add_argument(
        "--video",
        type=str,
        required=False,
        help="Bad Apple 视频文件路径（mp4/avi 等）",
    )
    parser.add_argument(
        "--num_drones",
        type=int,
        default=300,
        help="无人机数量",
    )
    parser.add_argument(
        "--width",
        type=int,
        default=960,
        help="舞台宽度（像素）",
    )
    parser.add_argument(
        "--height",
        type=int,
        default=720,
        help="舞台高度（像素）",
    )
    parser.add_argument(
        "--min_gap",
        type=float,
        default=8.0,
        help="无人机之间的最小安全间距（像素）",
    )
    parser.add_argument(
        "--max_speed",
        type=float,
        default=200.0,
        help="无人机最大速度（像素/秒）",
    )
    parser.add_argument(
        "--threshold",
        type=int,
        default=200,
        help="灰度二值化阈值（0-255）",
    )

    parser.add_argument(
        "--auto_invert",
        dest="auto_invert",
        action="store_true",
        help="启用自动反色：每帧在普通/反色二值化中选择亮像素较少的一侧",
    )
    parser.add_argument(
        "--no_auto_invert",
        dest="auto_invert",
        action="store_false",
        help="关闭自动反色，仅按 --invert 和阈值进行二值化",
    )
    parser.set_defaults(auto_invert=True)

    parser.add_argument(
        "--invert",
        action="store_true",
        help="强制使用反向二值化，将暗像素视为亮像素（适配反色视频）",
    )

    parser.add_argument(
        "--target_mode",
        type=str,
        choices=["poisson", "kmeans"],
        default="poisson",
        help="亮像素目标点生成模式：poisson 为 Poisson Disk 采样，kmeans 为 K-Means 聚类",
    )
    parser.add_argument(
        "--max_targets",
        type=int,
        default=None,
        help="每帧最多目标点数量（默认等于无人机数）",
    )
    parser.add_argument(
        "--max_clusters",
        type=int,
        default=200,
        help="在 kmeans 模式下每帧 K-Means 聚类的最大簇数（上限不超过 max_targets）",
    )
    parser.add_argument(
        "--max_samples",
        type=int,
        default=5000,
        help="每帧参与采样/聚类的亮像素最大候选数",
    )

    parser.add_argument(
        "--repulsion_strength",
        type=float,
        default=1.0,
        help="无人机之间斥力强度系数（越大越“排斥”）",
    )
    parser.add_argument(
        "--repulsion_mode",
        type=str,
        choices=["grid", "naive"],
        default="grid",
        help="斥力计算模式：grid 为近邻网格模式（默认），naive 为全量两两检查",
    )

    parser.add_argument(
        "--queue_size",
        type=int,
        default=16,
        help="多线程读帧队列最大长度（帧数）",
    )
    parser.add_argument(
        "--threads",
        type=int,
        default=2,
        help="线程数（>=2 时启用独立读帧线程；<2 时退化为单线程）",
    )

    parser.add_argument(
        "--drone_radius",
        type=int,
        default=3,
        help="无人机绘制时的圆半径（像素）",
    )
    parser.add_argument(
        "--overlay_scale",
        type=float,
        default=0.25,
        help="左上角原视频缩略图相对于舞台宽度的缩放比例",
    )
    parser.add_argument(
        "--window_scale",
        type=float,
        default=1.0,
        help="显示窗口缩放比例（仅影响显示，不改变舞台尺寸）",
    )

    parser.add_argument(
        "--play_audio",
        dest="play_audio",
        action="store_true",
        help="通过 ffplay 播放输入视频音轨用于音画同步（默认开启，如需关闭用 --no_play_audio）",
    )
    parser.add_argument(
        "--no_play_audio",
        dest="play_audio",
        action="store_false",
        help="关闭音频播放，仅显示无人机画面",
    )
    parser.set_defaults(play_audio=True)

    parser.add_argument(
        "--output_video",
        type=str,
        default=None,
        help="将模拟结果导出为带音轨的 MP4 文件路径（如 ./output.mp4）",
    )
    parser.add_argument(
        "--no_show_original",
        action="store_true",
        help="不在画面角落叠加原始视频缩略图",
    )

    args = parser.parse_args()
    return args


def initialize_drones(num_drones, width, height, min_gap, max_attempts=10000):
    """初始化无人机位置，使用简单拒绝采样保证最小间距。"""
    drones = []
    positions = []

    y_min = height * 0.7
    y_max = height * 0.95
    x_min = width * 0.1
    x_max = width * 0.9

    for idx in range(num_drones):
        attempts = 0
        while True:
            attempts += 1
            if attempts > max_attempts:
                x = random.uniform(0, width - 1)
                y = random.uniform(0, height - 1)
                break

            x = random.uniform(x_min, x_max)
            y = random.uniform(y_min, y_max)

            ok = True
            for px, py in positions:
                dx = x - px
                dy = y - py
                if dx * dx + dy * dy < min_gap * min_gap:
                    ok = False
                    break
            if ok:
                break

        positions.append((x, y))
        home_pos = (x, y)
        drones.append(Drone(idx, pos=(x, y), home_pos=home_pos))

    return drones


def kmeans_cluster(points, k):
    """对亮像素点做 K-Means 聚类，返回聚类中心。"""
    data = points.astype(np.float32)
    criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 20, 0.5)
    attempts = 3
    flags = cv2.KMEANS_PP_CENTERS
    _compactness, _labels, centers = cv2.kmeans(
        data,
        k,
        None,
        criteria,
        attempts,
        flags,
    )
    return centers


def poisson_disk_sampling(points, width, height, min_gap, max_points):
    """对候选亮像素点执行近似 Poisson Disk 采样，返回采样点坐标。"""
    n_points = points.shape[0]
    if n_points == 0 or max_points <= 0:
        return np.zeros((0, 2), dtype=np.float32)

    if min_gap <= 1e-3:
        m = min(max_points, n_points)
        idx = np.random.choice(n_points, size=m, replace=False)
        return points[idx].astype(np.float32)

    cell_size = float(min_gap) / math.sqrt(2.0)
    grid_w = max(1, int(math.ceil(width / cell_size)))
    grid_h = max(1, int(math.ceil(height / cell_size)))

    grid = [[-1] * grid_w for _ in range(grid_h)]
    samples = []

    order = np.random.permutation(n_points)
    min_gap2 = float(min_gap) * float(min_gap)

    for idx in order:
        p = points[idx]
        gx = int(p[0] / cell_size)
        gy = int(p[1] / cell_size)
        gx = min(max(gx, 0), grid_w - 1)
        gy = min(max(gy, 0), grid_h - 1)

        ok = True
        for ny in range(max(0, gy - 2), min(grid_h, gy + 3)):
            row = grid[ny]
            for nx in range(max(0, gx - 2), min(grid_w, gx + 3)):
                s_idx = row[nx]
                if s_idx == -1:
                    continue
                sp = samples[s_idx]
                dx = p[0] - sp[0]
                dy = p[1] - sp[1]
                if dx * dx + dy * dy < min_gap2:
                    ok = False
                    break
            if not ok:
                break
        if not ok:
            continue

        grid[gy][gx] = len(samples)
        samples.append(p)
        if len(samples) >= max_points:
            break

    if samples:
        return np.stack(samples, axis=0).astype(np.float32)

    m = min(max_points, n_points)
    idx = np.random.choice(n_points, size=m, replace=False)
    return points[idx].astype(np.float32)


def extract_bright_points(binary, max_samples):
    """从二值图中提取亮像素并随机下采样，返回 (x, y) 点集。"""
    coords = np.column_stack(np.where(binary > 0))  # (N, 2) -> (y, x)
    if coords.size == 0:
        return None
    if coords.shape[0] > max_samples:
        idx = np.random.choice(coords.shape[0], size=max_samples, replace=False)
        coords = coords[idx]
    points = np.stack((coords[:, 1], coords[:, 0]), axis=1).astype(np.float32)
    return points


def generate_targets(points, mode, max_targets, max_clusters, width, height, min_gap):
    """根据亮像素点生成目标点集合，支持 Poisson 采样与 K-Means。"""
    if points is None or len(points) == 0 or max_targets <= 0:
        return None
    max_targets = int(max_targets)
    if max_targets <= 0:
        return None

    if mode == "poisson":
        max_points = min(max_targets, points.shape[0])
        if max_points <= 0:
            return None
        centers = poisson_disk_sampling(points, width, height, min_gap, max_points)
        return centers if centers.shape[0] > 0 else None
    else:
        k = min(max_clusters, max_targets, points.shape[0])
        if k <= 0:
            return None
        return kmeans_cluster(points, k)


def stable_match_targets(prev_targets, new_centers, next_id):
    """在相邻帧之间稳定匹配目标点，维护连续的目标 ID。"""
    targets = {}

    if new_centers is None or len(new_centers) == 0:
        return targets, next_id

    center_list = [np.array(c, dtype=np.float32) for c in new_centers]
    prev_ids = list(prev_targets.keys())

    if prev_ids:
        pairs = []
        for i, tid in enumerate(prev_ids):
            p = prev_targets[tid]
            for j, c in enumerate(center_list):
                dist = float(np.linalg.norm(p - c))
                pairs.append((dist, i, j))
        pairs.sort(key=lambda x: x[0])
        used_prev = set()
        used_new = set()
        for dist, i, j in pairs:
            if i in used_prev or j in used_new:
                continue
            tid = prev_ids[i]
            targets[tid] = center_list[j]
            used_prev.add(i)
            used_new.add(j)
        for j, c in enumerate(center_list):
            if j in used_new:
                continue
            tid = next_id
            next_id += 1
            targets[tid] = c
    else:
        for c in center_list:
            tid = next_id
            next_id += 1
            targets[tid] = c

    return targets, next_id


def assign_drones_to_targets(drones, targets):
    """为无人机分配目标点，优先保持旧绑定，剩余就近贪心匹配。"""
    if not targets:
        for d in drones:
            d.target_id = None
            d.active = False
        return

    taken_targets = set()
    for d in drones:
        if d.target_id in targets:
            taken_targets.add(d.target_id)
        else:
            d.target_id = None

    free_targets = [tid for tid in targets.keys() if tid not in taken_targets]
    if not free_targets:
        for d in drones:
            d.active = d.target_id is not None
        return

    free_drones = [d for d in drones if d.target_id is None]
    if not free_drones:
        for d in drones:
            d.active = True
        return

    pairs = []
    for i, d in enumerate(free_drones):
        for j, tid in enumerate(free_targets):
            center = targets[tid]
            dist = float(np.linalg.norm(d.pos - center))
            pairs.append((dist, i, j))
    pairs.sort(key=lambda x: x[0])

    used_d = set()
    used_t = set()
    for dist, i, j in pairs:
        if i in used_d or j in used_t:
            continue
        d = free_drones[i]
        tid = free_targets[j]
        d.target_id = tid
        used_d.add(i)
        used_t.add(j)

    for d in drones:
        d.active = d.target_id is not None


def _apply_repulsion_naive(pos_after_attr, min_gap, repulsion_strength):
    """O(N^2) 朴素斥力实现。"""
    n = pos_after_attr.shape[0]
    rep_corrections = np.zeros_like(pos_after_attr)
    if n <= 1 or repulsion_strength <= 0.0 or min_gap <= 0.0:
        return rep_corrections

    min_gap = float(min_gap)
    min_gap2 = min_gap * min_gap

    for i in range(n):
        for j in range(i + 1, n):
            delta = pos_after_attr[j] - pos_after_attr[i]
            dx = float(delta[0])
            dy = float(delta[1])
            dist2 = dx * dx + dy * dy

            if dist2 < 1e-12:
                angle = random.random() * 2.0 * math.pi
                direction = np.array([math.cos(angle), math.sin(angle)], dtype=np.float32)
                dist = 1e-6
            elif dist2 < min_gap2:
                dist = math.sqrt(dist2)
                direction = delta / dist
            else:
                continue

            if dist < min_gap:
                overlap = (min_gap - dist) * 0.5 * repulsion_strength
                correction = direction * overlap
                rep_corrections[i] -= correction
                rep_corrections[j] += correction

    return rep_corrections


def _apply_repulsion_grid(pos_after_attr, min_gap, repulsion_strength):
    """基于近邻网格的斥力实现，仅在局部 3x3 网格内计算 j>i 的配对。"""
    n = pos_after_attr.shape[0]
    rep_corrections = np.zeros_like(pos_after_attr)
    if n <= 1 or repulsion_strength <= 0.0 or min_gap <= 0.0:
        return rep_corrections

    min_gap = float(min_gap)
    cell_size = max(min_gap, 1.0)
    inv_cell = 1.0 / cell_size
    min_gap2 = min_gap * min_gap

    grid = {}
    for i in range(n):
        x, y = pos_after_attr[i]
        gx = int(x * inv_cell)
        gy = int(y * inv_cell)
        grid.setdefault((gx, gy), []).append(i)

    for i in range(n):
        xi, yi = pos_after_attr[i]
        gx = int(xi * inv_cell)
        gy = int(yi * inv_cell)
        for oy in (-1, 0, 1):
            for ox in (-1, 0, 1):
                cell = (gx + ox, gy + oy)
                if cell not in grid:
                    continue
                for j in grid[cell]:
                    if j <= i:
                        continue
                    delta = pos_after_attr[j] - pos_after_attr[i]
                    dx = float(delta[0])
                    dy = float(delta[1])
                    dist2 = dx * dx + dy * dy

                    if dist2 < 1e-12:
                        angle = random.random() * 2.0 * math.pi
                        direction = np.array(
                            [math.cos(angle), math.sin(angle)], dtype=np.float32
                        )
                        dist = 1e-6
                    elif dist2 < min_gap2:
                        dist = math.sqrt(dist2)
                        direction = delta / dist
                    else:
                        continue

                    if dist < min_gap:
                        overlap = (min_gap - dist) * 0.5 * repulsion_strength
                        correction = direction * overlap
                        rep_corrections[i] -= correction
                        rep_corrections[j] += correction

    return rep_corrections


def update_drones(
    drones,
    targets,
    width,
    height,
    dt,
    max_speed,
    min_gap,
    repulsion_strength,
    repulsion_mode="grid",
):
    """基于目标吸引 + 斥力 + 速度裁剪更新无人机位置。"""
    n = len(drones)
    if n == 0 or dt <= 0.0:
        return

    positions = np.array([d.pos for d in drones], dtype=np.float32)
    target_positions = np.zeros_like(positions)

    for i, d in enumerate(drones):
        if d.target_id is not None and d.target_id in targets:
            target_positions[i] = targets[d.target_id]
        else:
            target_positions[i] = d.home_pos

    diff = target_positions - positions
    distances = np.linalg.norm(diff, axis=1) + 1e-6
    directions = diff / distances[:, None]

    desired_speed = np.minimum(max_speed, distances / dt)
    v_attr = directions * desired_speed[:, None]

    pos_after_attr = positions + v_attr * dt

    if repulsion_mode == "naive":
        rep_corrections = _apply_repulsion_naive(pos_after_attr, min_gap, repulsion_strength)
    else:
        rep_corrections = _apply_repulsion_grid(pos_after_attr, min_gap, repulsion_strength)

    pos_after_both = pos_after_attr + rep_corrections

    v_total = (pos_after_both - positions) / dt
    speeds = np.linalg.norm(v_total, axis=1) + 1e-6
    factor = np.minimum(1.0, max_speed / speeds)
    v_total = v_total * factor[:, None]

    new_positions = positions + v_total * dt
    new_positions[:, 0] = np.clip(new_positions[:, 0], 0.0, width - 1.0)
    new_positions[:, 1] = np.clip(new_positions[:, 1], 0.0, height - 1.0)

    for i, d in enumerate(drones):
        d.pos = new_positions[i]
        d.vel = v_total[i]


def draw_drones(drones, canvas, drone_radius):
    """在画布上绘制所有无人机。"""
    for d in drones:
        color = (255, 255, 255) if d.active else (80, 80, 80)
        cx = int(round(float(d.pos[0])))
        cy = int(round(float(d.pos[1])))
        cv2.circle(
            canvas,
            (cx, cy),
            drone_radius,
            color,
            thickness=-1,
            lineType=cv2.LINE_AA,
        )


def overlay_original(canvas, frame, scale=0.25, margin=8):
    """在画布左上角叠加缩小版原始视频帧。"""
    h, w = canvas.shape[:2]
    fh, fw = frame.shape[:2]
    if fh <= 0 or fw <= 0:
        return
    new_w = int(w * scale)
    if new_w < 1:
        return
    new_h = int(fh * (new_w / fw))
    if new_h < 1 or new_h + margin >= h or new_w + margin >= w:
        return
    thumb = cv2.resize(frame, (new_w, new_h), interpolation=cv2.INTER_AREA)
    canvas[margin : margin + new_h, margin : margin + new_w] = thumb


def mux_video_with_audio(tmp_video_path, input_video_path, output_video_path, ffmpeg_path):
    """使用 ffmpeg 将无音轨视频与原始音轨复用为最终输出视频。"""
    cmd_copy = [
        ffmpeg_path,
        "-y",
        "-i",
        tmp_video_path,
        "-i",
        input_video_path,
        "-map",
        "0:v:0",
        "-map",
        "1:a:0",
        "-c:v",
        "copy",
        "-c:a",
        "copy",
        "-shortest",
        output_video_path,
    ]
    try:
        result = subprocess.run(
            cmd_copy,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            check=False,
        )
    except Exception as e:
        print(f"调用 ffmpeg 复制编解码参数失败：{e}")
        result = None

    if result is not None and result.returncode == 0:
        return True

    print("ffmpeg 直接 copy 编码失败，尝试使用 libx264 重新编码视频轨……")

    cmd_reencode = [
        ffmpeg_path,
        "-y",
        "-i",
        tmp_video_path,
        "-i",
        input_video_path,
        "-map",
        "0:v:0",
        "-map",
        "1:a:0",
        "-c:v",
        "libx264",
        "-pix_fmt",
        "yuv420p",
        "-c:a",
        "copy",
        "-shortest",
        output_video_path,
    ]
    try:
        result2 = subprocess.run(
            cmd_reencode,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            check=False,
        )
    except Exception as e:
        print(f"调用 ffmpeg 重新编码失败：{e}")
        return False

    return result2.returncode == 0


def main():
    args = parse_args()

    if not args.video:
        print("请通过 --video 指定 Bad Apple 视频文件路径，例如：")
        print("  python drone_bad_apple_sim.py --video ./bad_apple.mp4")
        sys.exit(1)

    cap = cv2.VideoCapture(args.video)
    if not cap.isOpened():
        print(f"无法打开视频文件：{args.video}")
        sys.exit(1)

    fps = cap.get(cv2.CAP_PROP_FPS)
    if fps is None or fps <= 1e-3 or math.isnan(fps):
        fps = 30.0
    frame_count_total = cap.get(cv2.CAP_PROP_FRAME_COUNT)
    if frame_count_total is None:
        frame_count_total = 0.0

    dt_base = 1.0 / fps

    if args.max_targets is None or args.max_targets <= 0:
        max_targets = args.num_drones
    else:
        max_targets = args.max_targets

    max_clusters = min(args.max_clusters, max_targets if max_targets > 0 else args.num_drones)

    use_threading = args.threads is not None and args.threads >= 2
    queue_size = max(1, int(args.queue_size))

    ffmpeg_path = shutil.which("ffmpeg")
    ffplay_path = shutil.which("ffplay")

    export_only = bool(args.output_video)
    if export_only:
        # 导出模式：强制关闭音频播放
        args.play_audio = False

    # 初始化视频写出
    write_video = False
    video_writer = None
    tmp_video_path = None
    if args.output_video:
        base, ext = os.path.splitext(args.output_video)
        if not ext:
            ext = ".mp4"
        tmp_video_path = f"{base}_tmp_noaudio{ext}"
        fourcc = cv2.VideoWriter_fourcc(*"mp4v")
        video_writer = cv2.VideoWriter(
            tmp_video_path,
            fourcc,
            fps,
            (args.width, args.height),
        )
        if not video_writer.isOpened():
            print(f"无法打开视频写出文件：{tmp_video_path}，将跳过导出视频。")
            video_writer.release()
            video_writer = None
            tmp_video_path = None
        else:
            write_video = True

    display_mode = "export-only" if export_only else "live"
    frame_skip_enabled = not export_only

    print("================= 模拟参数 =================")
    print(f"视频文件：{args.video}")
    if frame_count_total > 0 and not math.isnan(frame_count_total):
        print(f"视频帧数（约）：{int(frame_count_total)}")
    else:
        print("视频帧数（约）：未知")
    print(f"视频 FPS：{fps:.2f}，基础步长 dt = {dt_base:.4f} 秒")
    print(f"舞台尺寸：{args.width} x {args.height}")
    print(f"无人机数量：{args.num_drones}")
    print(f"最小间距 min_gap：{args.min_gap}")
    print(f"最大速度 max_speed：{args.max_speed}")
    print(f"二值化阈值 threshold：{args.threshold}")
    print(f"目标生成模式 target_mode：{args.target_mode}")
    print(f"每帧目标数上限 max_targets：{max_targets}")
    print(f"kmeans 最大聚类数 max_clusters：{max_clusters}")
    print(f"亮像素最大候选数 max_samples：{args.max_samples}")
    print(f"斥力强度 repulsion_strength：{args.repulsion_strength}")
    print(f"斥力模式 repulsion_mode：{args.repulsion_mode}")
    print(
        "自动反色 auto_invert：{}（显式 invert={}）".format(
            "开启" if args.auto_invert else "关闭", "是" if args.invert else "否"
        )
    )
    print(
        f"显示模式 display_mode：{display_mode}；帧跳过同步："
        f"{'启用(墙钟时间轴+frame skipping)' if frame_skip_enabled else '关闭（离线逐帧处理）'}"
    )
    print(
        "读帧线程：{} (threads={}, queue_size={})".format(
            "启用" if use_threading else "未启用", args.threads, queue_size
        )
    )
    print(
        f"ffmpeg 可用性：{'可用' if ffmpeg_path else '不可用'}；"
        f" ffplay 可用性：{'可用' if ffplay_path else '不可用'}"
    )
    print(
        f"播放音频 play_audio："
        f"{'开启' if (not export_only and args.play_audio and ffplay_path) else '关闭'}；"
        f" 输出视频：{args.output_video if args.output_video else '无'}"
    )
    print(f"窗口缩放 window_scale：{args.window_scale}")
    if write_video and tmp_video_path:
        print(f"无音轨临时视频路径：{tmp_video_path}")
    print("============================================")

    drones = initialize_drones(
        num_drones=args.num_drones,
        width=args.width,
        height=args.height,
        min_gap=args.min_gap,
    )

    targets = {}
    next_target_id = 0

    frame_count = 0
    last_log_time = time.time()
    last_bright_pixels = 0
    last_target_count = 0
    previous_index = None

    window_name = "Drone Bad Apple Simulation"
    if not export_only:
        cv2.namedWindow(window_name, cv2.WINDOW_NORMAL)

    # 统一的读帧函数：返回 (frame_idx, frame_resized)
    if use_threading:
        frame_queue = queue.Queue(maxsize=queue_size)

        def producer():
            frame_idx = 0
            while True:
                ret, frame = cap.read()
                if not ret:
                    break
                frame_resized = cv2.resize(
                    frame,
                    (args.width, args.height),
                    interpolation=cv2.INTER_AREA,
                )
                frame_queue.put((frame_idx, frame_resized))
                frame_idx += 1
            cap.release()
            frame_queue.put((None, None))

        producer_thread = threading.Thread(target=producer, daemon=True)
        producer_thread.start()

        def get_raw_frame():
            return frame_queue.get()

    else:
        next_frame_index = 0

        def get_raw_frame():  # type: ignore[misc]
            nonlocal next_frame_index
            ret, frame = cap.read()
            if not ret:
                return None, None
            frame_resized = cv2.resize(
                frame,
                (args.width, args.height),
                interpolation=cv2.INTER_AREA,
            )
            idx = next_frame_index
            next_frame_index += 1
            return idx, frame_resized

    def get_frame_live(expected_index: int):
        """根据 expected_index 从流中取帧并丢弃过期帧。"""
        while True:
            idx, frame = get_raw_frame()
            if idx is None or frame is None:
                return None, None
            if idx < expected_index:
                # 丢弃过期帧
                continue
            return idx, frame

    total_pixels = args.width * args.height

    # 音频与时间轴
    audio_proc = None
    t_start = None
    if (not export_only) and args.play_audio and ffplay_path:
        try:
            audio_cmd = [
                ffplay_path,
                "-nodisp",
                "-autoexit",
                "-loglevel",
                "error",
                "-i",
                args.video,
            ]
            audio_proc = subprocess.Popen(audio_cmd)
            t_start = time.time()
            print("已启动 ffplay 音轨播放进程以同步音频。")
        except Exception as e:
            print(f"启动 ffplay 播放音频失败，将静音播放。错误：{e}")
            audio_proc = None
    elif (not export_only) and args.play_audio and not ffplay_path:
        print("检测到 play_audio 开启，但系统未找到 ffplay，将静音播放。")

    # 主循环
    if export_only:
        # 导出模式：无显示、无音频、无墙钟调度与帧跳过
        while True:
            idx, frame = get_raw_frame()
            if frame is None:
                print("视频处理结束（导出模式）。")
                break

            frame_count += 1
            processed_index = 0 if idx is None else int(idx)

            if previous_index is None:
                dt = dt_base
            else:
                step = processed_index - previous_index
                if step <= 0:
                    step = 1
                dt = step / fps
            previous_index = processed_index

            gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

            # 灰度二值化 + 自动反色逻辑
            _, binary_normal = cv2.threshold(
                gray,
                args.threshold,
                255,
                cv2.THRESH_BINARY,
            )
            bright_normal = int(cv2.countNonZero(binary_normal))
            bright_inv = int(total_pixels - bright_normal)

            if args.invert:
                binary = cv2.bitwise_not(binary_normal)
                bright_count = bright_inv
            else:
                if args.auto_invert:
                    if bright_normal <= bright_inv:
                        binary = binary_normal
                        bright_count = bright_normal
                    else:
                        binary = cv2.bitwise_not(binary_normal)
                        bright_count = bright_inv
                else:
                    binary = binary_normal
                    bright_count = bright_normal

            points = extract_bright_points(binary, args.max_samples)
            centers = generate_targets(
                points,
                mode=args.target_mode,
                max_targets=max_targets,
                max_clusters=max_clusters,
                width=args.width,
                height=args.height,
                min_gap=args.min_gap,
            )

            targets, next_target_id = stable_match_targets(targets, centers, next_target_id)
            assign_drones_to_targets(drones, targets)

            update_drones(
                drones,
                targets,
                width=args.width,
                height=args.height,
                dt=dt,
                max_speed=args.max_speed,
                min_gap=args.min_gap,
                repulsion_strength=args.repulsion_strength,
                repulsion_mode=args.repulsion_mode,
            )

            last_bright_pixels = bright_count
            last_target_count = len(targets)

            canvas = np.zeros((args.height, args.width, 3), dtype=np.uint8)
            draw_drones(drones, canvas, args.drone_radius)

            if not args.no_show_original:
                overlay_original(canvas, frame, scale=args.overlay_scale)

            if write_video and video_writer is not None:
                video_writer.write(canvas)

            if frame_count % 300 == 0:
                print(
                    f"导出进度：已处理 {frame_count} 帧，"
                    f"当前亮像素={last_bright_pixels}，目标数={last_target_count}"
                )
    else:
        # 实时模式：墙钟时间轴 + 帧跳过 + 小窗显示
        if t_start is None:
            t_start = time.time()

        while True:
            now_for_expected = time.time()
            expected_index = int(max(0, math.floor((now_for_expected - t_start) * fps)))

            idx, frame = get_frame_live(expected_index)
            if frame is None:
                print("视频播放结束。")
                break

            frame_count += 1
            processed_index = 0 if idx is None else int(idx)

            if previous_index is None:
                dt = dt_base
            else:
                step = processed_index - previous_index
                if step <= 0:
                    step = 1
                dt = step / fps
            previous_index = processed_index

            gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

            _, binary_normal = cv2.threshold(
                gray,
                args.threshold,
                255,
                cv2.THRESH_BINARY,
            )
            bright_normal = int(cv2.countNonZero(binary_normal))
            bright_inv = int(total_pixels - bright_normal)

            if args.invert:
                binary = cv2.bitwise_not(binary_normal)
                bright_count = bright_inv
            else:
                if args.auto_invert:
                    if bright_normal <= bright_inv:
                        binary = binary_normal
                        bright_count = bright_normal
                    else:
                        binary = cv2.bitwise_not(binary_normal)
                        bright_count = bright_inv
                else:
                    binary = binary_normal
                    bright_count = bright_normal

            points = extract_bright_points(binary, args.max_samples)
            centers = generate_targets(
                points,
                mode=args.target_mode,
                max_targets=max_targets,
                max_clusters=max_clusters,
                width=args.width,
                height=args.height,
                min_gap=args.min_gap,
            )

            targets, next_target_id = stable_match_targets(targets, centers, next_target_id)
            assign_drones_to_targets(drones, targets)

            update_drones(
                drones,
                targets,
                width=args.width,
                height=args.height,
                dt=dt,
                max_speed=args.max_speed,
                min_gap=args.min_gap,
                repulsion_strength=args.repulsion_strength,
                repulsion_mode=args.repulsion_mode,
            )

            last_bright_pixels = bright_count
            last_target_count = len(targets)

            canvas = np.zeros((args.height, args.width, 3), dtype=np.uint8)
            draw_drones(drones, canvas, args.drone_radius)

            if not args.no_show_original:
                overlay_original(canvas, frame, scale=args.overlay_scale)

            if write_video and video_writer is not None:
                video_writer.write(canvas)

            # 墙钟时间轴调度：基于源帧索引 processed_index
            target_time = t_start + processed_index / fps
            now = time.time()
            delay = target_time - now
            if delay > 0:
                time.sleep(delay)

            # 小窗显示
            display_canvas = canvas
            scale = args.window_scale
            if scale is not None and scale > 0 and abs(scale - 1.0) > 1e-3:
                scale = max(0.1, float(scale))
                disp_w = max(1, int(args.width * scale))
                disp_h = max(1, int(args.height * scale))
                interp = cv2.INTER_AREA if scale < 1.0 else cv2.INTER_LINEAR
                display_canvas = cv2.resize(canvas, (disp_w, disp_h), interpolation=interp)

            text = (
                f"FrameIdx: {processed_index}  Targets: {len(targets)}  "
                f"Drones: {len(drones)}"
            )
            cv2.putText(
                display_canvas,
                text,
                (10, display_canvas.shape[0] - 10),
                cv2.FONT_HERSHEY_SIMPLEX,
                0.5,
                (180, 180, 180),
                1,
                cv2.LINE_AA,
            )

            cv2.imshow(window_name, display_canvas)
            key = cv2.waitKey(1) & 0xFF
            if key == ord("q") or key == ord("Q"):
                print("收到 Q 键，提前退出模拟。")
                break

            if frame_count % 60 == 0:
                now = time.time()
                elapsed = now - last_log_time
                if elapsed > 0:
                    sim_fps = 60.0 / elapsed
                    print(
                        f"已播放 {frame_count} 帧，当前模拟 FPS ≈ {sim_fps:.1f}，"
                        f"亮像素={last_bright_pixels}，目标数={last_target_count}"
                    )
                last_log_time = now

    if not use_threading:
        cap.release()

    if audio_proc is not None:
        try:
            audio_proc.terminate()
        except Exception:
            pass
        try:
            audio_proc.wait(timeout=2.0)
        except Exception:
            pass

    if write_video and video_writer is not None and tmp_video_path is not None:
        video_writer.release()
        if ffmpeg_path:
            print("开始使用 ffmpeg 将模拟视频与原始音轨合并……")
            ok = mux_video_with_audio(tmp_video_path, args.video, args.output_video, ffmpeg_path)
            if ok:
                print(f"带音轨输出视频已生成：{args.output_video}")
                try:
                    os.remove(tmp_video_path)
                    print(f"已删除临时无音轨文件：{tmp_video_path}")
                except OSError:
                    print(f"删除临时文件失败，请手动删除：{tmp_video_path}")
            else:
                print(
                    "ffmpeg 合并音轨失败，已保留无音轨临时视频："
                    f"{tmp_video_path}\n可检查 ffmpeg 安装或参数后重新运行脚本，"
                    "或手动使用 ffmpeg 合并。"
                )
        else:
            print(
                f"系统未检测到 ffmpeg，已将无音轨模拟视频写入：{tmp_video_path}\n"
                "安装 ffmpeg 即可自动合并音轨（脚本会在运行结束后自动尝试复用音轨）。"
            )

    cv2.destroyAllWindows()

    # 完成提示
    print("音画同步与导出显示互斥修复完成")


if __name__ == "__main__":
    main()
