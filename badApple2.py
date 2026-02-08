#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""\
基于无人机群的 Bad Apple 黑白像素表演模拟脚本
================================================

本脚本使用固定数量的“无人机”（二维平面上的点）来近似还原 Bad Apple 的黑白像素视频：
每架无人机只有亮/灭两种状态，可以在平面上移动，但速度存在上限，并且任意两机之间
必须保持不小于给定最小间距。脚本通过 OpenCV 在电脑窗口中实时渲染模拟结果。

一、总体思路
--------------
1. 视频解码与预处理
   - 通过 `--video` 指定 Bad Apple 视频文件路径（mp4/avi 等）。
   - 使用 OpenCV `VideoCapture` 逐帧读取视频。
   - 每帧转换为灰度图，并按给定阈值二值化（亮/暗像素）。
   - 可选反色（`--invert`），以便适配不同版本的 Bad Apple 视频（反相或非纯黑白）。

2. 亮像素抽样与 K-Means 聚类
   - 从二值图中提取所有“亮”像素坐标，必要时随机下采样到 `--max_samples` 个，
     以控制 K-Means 的计算量。
   - 选择聚类数 K = min(亮像素数, `--max_clusters`, 无人机数)，并使用 OpenCV 的
     `cv2.kmeans` 在二维平面上做聚类，得到 K 个聚类中心，这些中心就是本帧的
     “目标点”。
   - 若某一帧没有亮像素，则视为本帧没有任何目标点。

3. 聚类中心稳定追踪（目标 ID 维护）
   - 为避免每帧聚类结果的中心编号发生剧烈跳变，采用最近邻匹配对相邻帧的聚类
     中心做“稳定追踪”：
     * 维护一个以整数 ID 为键、二维坐标为值的目标点字典 `targets`。
     * 对前一帧的每个目标与当前帧所有聚类中心两两计算欧氏距离，按距离从小到大
       排序后做贪心匹配：
       - 若某个旧目标与某个新中心匹配成功，则沿用旧 ID。
       - 未被匹配的新中心会分配新的 ID。
     * 未被匹配的旧目标在本帧中消失。
   - 这样可以尽量保持目标点 ID 随时间连续，便于无人机持续跟随同一目标。

4. 无人机与目标的分配策略
   - 初始化时在舞台底部区域为每架无人机随机生成一个“驻留位置”（home 位置），
     并保证任意两机之间的初始距离不小于 `--min_gap`。
   - 每帧根据当前 `targets` 为无人机分配目标：
     * 首先保留所有“仍然存在”的旧绑定（无人机之前跟随的目标 ID 若仍在 `targets`
       中，则继续跟随该目标）。
     * 剩余尚未分配目标的无人机与尚未被占用的目标点之间，计算两两距离，按最小
       距离贪心匹配，一对一分配，直至目标或无人机用完。
     * 被分配到目标的无人机处于“亮”状态；未分配目标的无人机处于“灭”状态，且
       不再跟随任何视频目标，只是缓慢返回各自的驻留位置在安全区静待。

5. 社交力模型：无人机运动控制
   - 时间步长 `dt` 由视频的 FPS 决定，`dt ≈ 1 / fps`。
   - 对每帧，每架无人机的运动由两部分组成：
     1) 指向目标（或驻留位置）的吸引：
        - 记无人机当前位置为 x，目标位置为 g，则位移方向为 (g - x)。
        - 计算到目标的距离 d，期望速度大小为 `min(max_speed, d/dt)`，保证
          在单步内既不超过最大速度 `--max_speed`，又不会“冲过头”。
        - 得到吸引速度向量 v_attr，吸引位移为 `v_attr * dt`。
     2) 对近邻无人机的斥力：
        - 基于“社交力”思想，当两机之间距离小于 `--min_gap` 时，对应产生一对
          反向的位移修正，以将二者推离：
          * 在吸引位移后的位置基础上，计算所有无人机两两之间的距离；
          * 若距离 dist < min_gap，则沿连线方向施加补偿位移，大小与
            `(min_gap - dist)` 成正比，并由 `--repulsion_strength` 调节强度；
          * 两机分别向相反方向移动相同的修正距离，从而缓解过近现象。
        - 所有相互作用的修正量叠加后得到总斥力位移。
   - 吸引位移与斥力位移叠加后得到本步的总位移，对应总速度 v_total，再对
     |v_total| 进行裁剪，不超过 `--max_speed`。
   - 更新位置后，将无人机坐标裁剪在 [0, width) × [0, height) 的舞台区域内，
     保证始终可见。

6. 渲染与交互
   - 为每帧创建一个 size = (`--height`, `--width`) 的黑色画布。
   - 对于每架无人机，在当前位置绘制实心圆：
     * 亮状态（有目标）使用白色圆点；
     * 灭状态（无目标，仅在安全区驻留）使用深灰色圆点。
   - 可选择在左上角叠加缩小版原视频帧作为参考，比例由 `--overlay_scale` 控制。
   - 在窗口底部显示当前帧序号与目标数量等调试信息。
   - 按下键盘 Q/q 可提前退出模拟。

二、关键约束
--------------
- 无人机数量固定，由 `--num_drones` 指定。
- 无人机只有亮/灭两种状态：
  * 亮：当前被分配到某个视频目标；
  * 灭：当前未分配目标，仅在安全区附近缓慢移动或静止。
- 速度上限：每帧更新之后的真实速度模长不会超过 `--max_speed`。
- 最小间距：尝试通过斥力修正保证任意两机之间距离不小于 `--min_gap`，若出现
  轻微违反，后续帧会自动通过社交力逐渐恢复安全距离。

三、命令行参数说明（常用）
----------------------------
- `--video` (必选)：Bad Apple 视频文件路径（mp4/avi 等）。
- `--num_drones`：无人机数量，默认 300。
- `--width`, `--height`：舞台画布宽和高（像素），同时也是视频缩放后的尺寸。
- `--min_gap`：无人机之间的最小安全距离（像素）。
- `--max_speed`：无人机最大速度（像素/秒）。
- `--threshold`：灰度二值化阈值（0~255），默认 200。
- `--max_clusters`：每帧 K-Means 的最大聚类数，不会超过无人机数量。
- `--max_samples`：每帧参与聚类的亮像素最大采样数，用于控制性能。
- `--repulsion_strength`：斥力强度系数，适当增大可增强防碰撞能力。
- `--invert`：使用反向二值化，将暗像素视为“亮”像素。
- `--no_show_original`：不在画面角落叠加原始视频缩略图。

四、运行示例
--------------
以下命令假设脚本文件名为 `drone_bad_apple_sim.py`，视频文件为 `bad_apple.mp4`，
舞台尺寸为 960×720，300 架无人机，最小间距 8 像素，最大速度 200 像素/秒：

    python drone_bad_apple_sim.py --video ./bad_apple.mp4 \
        --num_drones 300 --width 960 --height 720 \
        --min_gap 8 --max_speed 200 --threshold 200

运行后将弹出一个窗口显示无人机模拟效果，按 Q 可退出。
"""

import argparse
import sys
import time
import math
import random

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
    """简单的二维无人机模型，用于保存状态和基本属性。"""

    def __init__(self, idx, pos, home_pos):
        # 无人机编号
        self.idx = idx
        # 当前二维位置（x, y）
        self.pos = np.array(pos, dtype=np.float32)
        # 当前速度向量（vx, vy）
        self.vel = np.zeros(2, dtype=np.float32)
        # 驻留位置（无目标时返回的安全位置）
        self.home_pos = np.array(home_pos, dtype=np.float32)
        # 当前跟随的目标 ID；None 表示无目标
        self.target_id = None
        # 亮灭状态：True 表示亮（有目标），False 表示灭（无目标）
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
        "--max_clusters",
        type=int,
        default=200,
        help="每帧 K-Means 聚类的最大簇数（上限不超过无人机数量）",
    )
    parser.add_argument(
        "--max_samples",
        type=int,
        default=5000,
        help="每帧参与聚类的亮像素最大采样数",
    )
    parser.add_argument(
        "--repulsion_strength",
        type=float,
        default=1.0,
        help="无人机之间斥力强度系数（越大越“排斥”）",
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
        "--invert",
        action="store_true",
        help="使用反向二值化，将暗像素视为亮像素（适配反色视频）",
    )
    parser.add_argument(
        "--no_show_original",
        action="store_true",
        help="不在画面角落叠加原始视频缩略图",
    )

    args = parser.parse_args()
    return args


def initialize_drones(num_drones, width, height, min_gap, max_attempts=10000):
    """初始化无人机位置，使用简单拒绝采样保证最小间距。

    无人机初始及驻留位置分布在舞台底部的矩形区域内。
    """
    drones = []
    positions = []

    # 安全区设为舞台底部 30% 的区域
    y_min = height * 0.7
    y_max = height * 0.95
    x_min = width * 0.1
    x_max = width * 0.9

    for idx in range(num_drones):
        attempts = 0
        while True:
            attempts += 1
            if attempts > max_attempts:
                # 如果难以满足最小间距要求，则放宽限制随机放置
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
        d = Drone(idx, pos=(x, y), home_pos=home_pos)
        drones.append(d)

    return drones


def kmeans_cluster(points, k):
    """对亮像素点做 K-Means 聚类，返回聚类中心。

    参数
    ----
    points : np.ndarray(N, 2)
        所有亮像素的 (x, y) 坐标，类型为 float32。
    k : int
        聚类簇数。
    """
    # OpenCV K-Means 需要 float32 的输入
    data = points.astype(np.float32)

    criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 20, 0.5)
    attempts = 3
    flags = cv2.KMEANS_PP_CENTERS

    compactness, labels, centers = cv2.kmeans(
        data,
        k,
        None,
        criteria,
        attempts,
        flags,
    )
    # centers: (k, 2)
    return centers


def stable_match_targets(prev_targets, new_centers, next_id):
    """在相邻帧之间稳定匹配目标点，维护连续的目标 ID。

    参数
    ----
    prev_targets : dict[int, np.ndarray]
        上一帧的目标点字典，键为目标 ID，值为 (x, y) 坐标。
    new_centers : np.ndarray or None
        本帧 K-Means 得到的聚类中心数组（k, 2）。
    next_id : int
        可用的下一个新目标 ID。

    返回
    ----
    targets : dict[int, np.ndarray]
        本帧更新后的目标点字典。
    next_id : int
        更新后的下一个新目标 ID。
    """
    targets = {}

    if new_centers is None or len(new_centers) == 0:
        # 没有新的中心，所有旧目标消失
        return targets, next_id

    center_list = [np.array(c, dtype=np.float32) for c in new_centers]
    prev_ids = list(prev_targets.keys())

    if prev_ids:
        pairs = []
        # 计算所有旧目标与新中心之间的距离
        for i, tid in enumerate(prev_ids):
            p = prev_targets[tid]
            for j, c in enumerate(center_list):
                dist = float(np.linalg.norm(p - c))
                pairs.append((dist, i, j))

        # 按距离从小到大做贪心匹配
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

        # 未被匹配的新中心分配新的 ID
        for j, c in enumerate(center_list):
            if j in used_new:
                continue
            tid = next_id
            next_id += 1
            targets[tid] = c
    else:
        # 上一帧没有目标，直接为所有中心分配新 ID
        for c in center_list:
            tid = next_id
            next_id += 1
            targets[tid] = c

    return targets, next_id


def assign_drones_to_targets(drones, targets):
    """为无人机分配目标点，优先保持之前跟随的目标，剩余采用就近贪心匹配。

    参数
    ----
    drones : list[Drone]
        所有无人机。
    targets : dict[int, np.ndarray]
        当前帧的目标点字典。
    """
    if not targets:
        # 没有任何目标，所有无人机熄灭并清空绑定
        for d in drones:
            d.target_id = None
            d.active = False
        return

    taken_targets = set()

    # 首先保留仍然存在的旧绑定
    for d in drones:
        if d.target_id in targets:
            taken_targets.add(d.target_id)
        else:
            d.target_id = None

    free_targets = [tid for tid in targets.keys() if tid not in taken_targets]

    # 若没有空闲目标，直接更新亮灭状态
    if not free_targets:
        for d in drones:
            d.active = d.target_id is not None
        return

    free_drones = [d for d in drones if d.target_id is None]

    if not free_drones:
        for d in drones:
            d.active = True
        return

    # 对未分配的无人机与空闲目标做就近贪心匹配
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

    # 更新亮灭状态
    for d in drones:
        d.active = d.target_id is not None


def update_drones(drones, targets, width, height, dt, max_speed, min_gap, repulsion_strength):
    """基于目标吸引 + 斥力 + 速度裁剪更新无人机位置。

    参数
    ----
    drones : list[Drone]
        所有无人机。
    targets : dict[int, np.ndarray]
        当前帧的目标点字典。
    width, height : int
        舞台宽和高。
    dt : float
        时间步长（秒）。
    max_speed : float
        最大速度（像素/秒）。
    min_gap : float
        无人机最小安全间距（像素）。
    repulsion_strength : float
        斥力强度系数。
    """
    n = len(drones)
    if n == 0:
        return

    positions = np.array([d.pos for d in drones], dtype=np.float32)  # (n, 2)
    target_positions = np.zeros_like(positions)

    # 为每个无人机设置本帧的“目标位置”
    for i, d in enumerate(drones):
        if d.target_id is not None and d.target_id in targets:
            target_positions[i] = targets[d.target_id]
        else:
            # 无目标时，返回驻留位置（安全区）
            target_positions[i] = d.home_pos

    # 吸引速度：指向目标方向，速度大小不超过 max_speed，且避免单步越过目标
    diff = target_positions - positions
    distances = np.linalg.norm(diff, axis=1) + 1e-6
    directions = diff / distances[:, None]

    # 期望速度不能超过 max_speed，同时不超过 d/dt
    desired_speed = np.minimum(max_speed, distances / dt)
    v_attr = directions * desired_speed[:, None]

    # 吸引位移后的位置
    pos_after_attr = positions + v_attr * dt

    # 斥力修正：在吸引位移后的位置上检查两两距离
    rep_corrections = np.zeros_like(pos_after_attr)

    for i in range(n):
        for j in range(i + 1, n):
            delta = pos_after_attr[j] - pos_after_attr[i]
            dist = float(np.linalg.norm(delta))

            if dist < 1e-6:
                # 若两个点几乎重合，给一个随机方向避免数值问题
                angle = random.random() * 2.0 * math.pi
                delta = np.array([math.cos(angle), math.sin(angle)], dtype=np.float32)
                dist = 1e-6

            if dist < min_gap:
                # 距离过近，沿连线方向推开，两边各承担一半位移
                overlap = (min_gap - dist) * 0.5 * repulsion_strength
                direction = delta / dist
                correction = direction * overlap
                rep_corrections[i] -= correction
                rep_corrections[j] += correction

    pos_after_both = pos_after_attr + rep_corrections

    # 由总位移得到总速度，并进行裁剪
    v_total = (pos_after_both - positions) / dt
    speeds = np.linalg.norm(v_total, axis=1) + 1e-6
    factor = np.minimum(1.0, max_speed / speeds)
    v_total = v_total * factor[:, None]

    new_positions = positions + v_total * dt

    # 保证无人机仍在舞台范围内
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
        fps = 30.0  # 若视频未提供 FPS，则使用默认值

    dt = 1.0 / fps

    # 聚类数上限不能超过无人机数量
    max_clusters = min(args.max_clusters, args.num_drones)

    print("================= 模拟参数 =================")
    print(f"视频文件：{args.video}")
    print(f"视频 FPS：{fps:.2f}，时间步长 dt = {dt:.4f} 秒")
    print(f"舞台尺寸：{args.width} x {args.height}")
    print(f"无人机数量：{args.num_drones}")
    print(f"最小间距 min_gap：{args.min_gap}")
    print(f"最大速度 max_speed：{args.max_speed}")
    print(f"二值化阈值 threshold：{args.threshold}")
    print(f"最大聚类数 max_clusters：{max_clusters}")
    print(f"亮像素最大采样数 max_samples：{args.max_samples}")
    print(f"斥力强度 repulsion_strength：{args.repulsion_strength}")
    print("============================================")

    # 初始化无人机
    drones = initialize_drones(
        num_drones=args.num_drones,
        width=args.width,
        height=args.height,
        min_gap=args.min_gap,
    )

    # 目标点字典及下一个可分配 ID
    targets = {}
    next_target_id = 0

    delay_ms = int(1000.0 / fps) if fps > 0 else 33

    frame_count = 0
    last_log_time = time.time()

    window_name = "Drone Bad Apple Simulation"
    cv2.namedWindow(window_name, cv2.WINDOW_NORMAL)

    while True:
        ret, frame = cap.read()
        if not ret:
            print("视频播放结束。")
            break

        frame_count += 1

        # 将视频帧缩放到舞台尺寸，方便坐标统一
        frame = cv2.resize(
            frame,
            (args.width, args.height),
            interpolation=cv2.INTER_AREA,
        )

        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        # 灰度二值化
        if args.invert:
            _, binary = cv2.threshold(
                gray,
                args.threshold,
                255,
                cv2.THRESH_BINARY_INV,
            )
        else:
            _, binary = cv2.threshold(
                gray,
                args.threshold,
                255,
                cv2.THRESH_BINARY,
            )

        # 提取亮像素并抽样
        coords = np.column_stack(np.where(binary > 0))  # (N, 2) -> (y, x)
        centers = None

        if coords.size > 0:
            if coords.shape[0] > args.max_samples:
                idx = np.random.choice(coords.shape[0], size=args.max_samples, replace=False)
                coords = coords[idx]

            # 转换为 (x, y)
            points = np.stack((coords[:, 1], coords[:, 0]), axis=1).astype(np.float32)

            k = min(max_clusters, points.shape[0])
            if k >= 1:
                centers = kmeans_cluster(points, k)

        # 更新目标点并做稳定匹配
        targets, next_target_id = stable_match_targets(targets, centers, next_target_id)

        # 为无人机分配目标
        assign_drones_to_targets(drones, targets)

        # 更新无人机位置
        update_drones(
            drones,
            targets,
            width=args.width,
            height=args.height,
            dt=dt,
            max_speed=args.max_speed,
            min_gap=args.min_gap,
            repulsion_strength=args.repulsion_strength,
        )

        # 准备绘制画布
        canvas = np.zeros((args.height, args.width, 3), dtype=np.uint8)

        # 绘制无人机
        draw_drones(drones, canvas, args.drone_radius)

        # 叠加原视频缩略图
        if not args.no_show_original:
            overlay_original(canvas, frame, scale=args.overlay_scale)

        # 绘制调试文字
        text = f"Frame: {frame_count}  Targets: {len(targets)}  Drones: {len(drones)}"
        cv2.putText(
            canvas,
            text,
            (10, args.height - 10),
            cv2.FONT_HERSHEY_SIMPLEX,
            0.5,
            (180, 180, 180),
            1,
            cv2.LINE_AA,
        )

        cv2.imshow(window_name, canvas)

        key = cv2.waitKey(max(1, delay_ms)) & 0xFF
        if key == ord("q") or key == ord("Q"):
            print("收到 Q 键，提前退出模拟。")
            break

        # 周期性打印当前模拟 FPS
        if frame_count % 60 == 0:
            now = time.time()
            elapsed = now - last_log_time
            if elapsed > 0:
                sim_fps = 60.0 / elapsed
                print(f"已播放 {frame_count} 帧，当前模拟 FPS ≈ {sim_fps:.1f}")
            last_log_time = now

    cap.release()
    cv2.destroyAllWindows()


if __name__ == "__main__":
    main()
