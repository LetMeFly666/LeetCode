#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""\
基于无人机群的 Bad Apple 黑白像素表演模拟脚本
==========================================================================

本脚本使用固定数量的“无人机”（二维平面上的点）来近似还原 Bad Apple 的黑白像素视频：
每架无人机只有亮/灭两种状态，可以在平面上移动，但速度存在上限，并且任意两机之间
必须保持不小于给定最小间距。脚本通过 OpenCV 在电脑窗口中实时渲染模拟结果，并支持：

- Poisson Disk（蓝噪声）采样生成目标点，形状还原度更高；
- 自动反色 auto_invert，使得黑/白背景切换时尽量始终以“主体”为亮点；
- 近邻网格斥力（grid 模式），在大量无人机时降低 CPU 占用；
- 并发读帧管线（解码线程 + 主处理线程），提高帧处理吞吐；
- 小窗播放（window_scale），可缩放显示窗口尺寸而不影响内部舞台计算；
- 导出模拟结果为视频，并自动从输入 MP4 中提取音轨合并生成带声 MP4。

一、目标点生成：Poisson Disk（蓝噪声）采样（默认）
-------------------------------------------------

传统做法是对亮像素做 K-Means 聚类：聚类中心作为无人机“要去的点”。
这样容易出现两个问题：

- 聚类中心偏向高密度区域，导致轮廓位置的点被“拉向中间”，整体形状会被抹平；
- 相邻帧的聚类结果对局部噪声敏感，容易产生形状跳动。

Poisson Disk（蓝噪声）采样的思路是：

- 在亮像素集合内随机挑选一批点；
- 任何两个采样点之间的距离都不小于给定半径（这里采用 min_gap），
  形成“既随机又均匀”的空间分布（蓝噪声分布）；
- 采样点更均匀地覆盖亮区域，有利于保留轮廓细节，使整体形状更“可读”。

本脚本在二值图的亮像素集合上执行近似 Poisson Disk 采样：

- 先对亮像素随机下采样（上限 max_samples），作为候选集合；
- 将舞台划分为网格（cell_size ≈ min_gap / sqrt(2)），每个格子最多存一个采样点；
- 随机遍历候选像素，只检查其周围若干格子里的已选点距离；
  若都大于 min_gap 则接受，否则拒绝；
- 最多采样到 max_targets 个目标点（默认等于无人机数）。

调参建议：

- 阈值 threshold 越低，认为是“亮”的像素越多，形状越细腻，但噪声也越多；
- 每帧目标数上限 max_targets 越大，可亮的无人机越多，形状越接近原图，但整体更拥挤；
- 当 threshold 较低同时 max_targets 较大时，建议增大 repulsion_strength，
  让“社交斥力”更强，从而减少无人机之间的碰撞和重叠，保持画面整洁；
- 若想对比老的 K-Means 方案，可设置 --target_mode kmeans，并调节 --max_clusters。

二、自动反色 auto_invert：始终尽量让“主体亮、背景暗”
----------------------------------------------------

Bad Apple 常见有两种风格：

- 黑背景 + 白人物/主体；
- 白背景 + 黑人物/主体（或中途出现大面积反色切换）。

若只固定一个二值化方向，要么背景很亮、点特别多（无人机全场乱飞），
要么人物很暗、看不出轮廓。为此本脚本引入“自动反色”（默认开启）：

- 每帧先做普通二值化（亮 = 白像素），得到 binary_normal；
- 由 binary_normal 取反可得到“反色二值图”（亮 = 原本的黑色部分）；
- 同时计算普通与反色两种情况下的亮像素数量；
- 自动选择“亮像素数量较少”的那一种作为本帧的目标亮区：
  * 黑背景 + 白人物时，白像素少，自动选择普通二值化；
  * 白背景 + 黑人物时，反色后亮的就是人物，小而集中，自动选择反色。

这样在黑/白背景切换时，始终尽量以“人物/主体”为亮点进行无人机调度，
亮点数量较为平稳，形状也更容易辨认。

- auto_invert/no_auto_invert 控制是否启用自动反色（默认开启 auto_invert）；
- 若用户显式传入 --invert，则强制使用反色并覆盖自动策略；
- 禁用自动反色（--no_auto_invert）时，亮区域完全由 --invert 与 threshold 控制。

三、无人机调度与社交力模型（可中途熄灭）
----------------------------------------

1. 初始化与驻留位置
   - 初始化时在舞台底部区域为每架无人机随机生成一个“驻留位置”（home 位置），
     并通过简单拒绝采样保证任意两机之间的初始距离不小于 min_gap。

2. 目标中心稳定追踪
   - 无论使用 Poisson 采样还是 K-Means 聚类，本脚本都对相邻帧的目标点做“稳定追踪”：
     * 维护一个以整数 ID 为键、二维坐标为值的目标点字典 targets；
     * 将上一帧的目标与当前帧目标两两计算距离，按距离从小到大贪心匹配；
       - 匹配成功则沿用旧 ID；
       - 未被匹配的新目标点分配新的 ID；
     * 未被匹配的旧目标在本帧中消失。

3. 无人机与目标分配（支持中途熄灭）
   - 每帧根据当前 targets 为无人机分配目标：
     * 首先保留所有“仍然存在”的旧绑定（无人机之前跟随的目标 ID 若仍在 targets 中，
       则继续跟随该目标）；
     * 剩余未分配的无人机与未被占用的目标点之间，按就近原则做贪心匹配；
     * 被分配到目标的无人机处于“亮”状态；未分配目标的无人机处于“灭”状态，
       不再跟随任何视频目标，只是缓慢返回各自驻留位置在安全区静待。

   因此：
   - 无人机总数是固定的，但每帧“亮着”的无人机数量会随画面亮部变化而动态调整；
   - 无人机可以在表演过程中“中途熄灭”或再次被点亮；
   - 通过 max_targets、threshold 以及自动反色，可以动态控制每帧被调度的无人机规模。

4. 社交力模型与近邻网格斥力
   - 时间步长 dt 由视频 FPS 决定，dt ≈ 1 / fps；
   - 每帧对每架无人机：
     1) 指向目标（或驻留位置）的吸引：
        - 记无人机当前位置为 x，目标位置为 g，则位移方向为 (g - x)；
        - 计算到目标的距离 d，期望速度大小为 min(max_speed, d/dt)，
          既不超过最大速度 max_speed，又不过冲目标；
        - 得到吸引速度 v_attr，对应位移为 v_attr * dt。
     2) 对近邻无人机的斥力：
        - 当两机距离小于 min_gap 时，沿连线方向施加补偿位移，将它们推离；
        - 斥力强度由 repulsion_strength 控制，值越大越“排斥”。

   为降低计算量，本脚本提供两种斥力模式：

   - repulsion_mode = grid（默认）：
     * 将舞台按 cell_size ≈ min_gap 划分为网格；
     * 每架无人机登记到对应格子；
     * 只对自身所在格以及相邻 3x3 共 9 个格子中的无人机计算斥力，且只处理 j>i 的组合；
     * 对大量无人机（几百、上千）时，能显著减少 O(N^2) 距离计算，降低单核高占用。

   - repulsion_mode = naive：
     * 采用朴素 O(N^2) 全量两两检查，仅用于对比或调试。

四、并发读帧管线：解码与计算解耦
--------------------------------

原始串行方式在主线程中完成：

- 从 VideoCapture 读一帧；
- 灰度化、二值化、目标点生成、目标匹配、无人机物理更新、绘制与显示。

当每帧计算量较大时，解码与计算会互相“排队”，导致吞吐不高。

本脚本采用典型的生产者-消费者结构：

- 读帧线程（Producer）
  - 独立线程中持续从视频解码帧，并直接缩放到舞台尺寸 (width, height)；
  - 将结果放入有界队列 queue.Queue(maxsize=queue_size)。

- 主线程（Consumer）
  - 从队列中取出最新帧，执行二值化、目标生成、匹配、物理更新与绘制；
  - 只负责计算与显示，不与磁盘/解码 IO 竞争。

当 threads >= 2 时启用读帧线程（默认 2）；threads < 2 时退化为单线程串行处理。

五、小窗播放与音画同步（墙钟调度 + ffplay）
-------------------------------------------

1. 小窗播放 window_scale
   - 内部“舞台”尺寸由 --width、--height 控制，所有物理计算与坐标系均以舞台尺寸为准；
   - 新增参数 --window_scale（默认 1.0，建议 0.3~1.0），用于缩放显示窗口画面：
     * 在绘制完成后，对 canvas 做一次 cv2.resize，再交给 cv2.imshow 显示；
     * 仅影响显示窗口大小，不改变内部物理计算与视频解析分辨率；
     * 适合在高分辨率舞台下“小窗播放”，避免窗口过大挡住屏幕。

2. 音画同步：墙钟时间轴
   - 若系统安装了 ffplay 且未关闭 --play_audio，本脚本会在开始时以子进程方式播放原视频音轨：

       ffplay -nodisp -autoexit -loglevel error -i input.mp4

   - 记录起始时间 t0（尽量与音轨启动时刻一致），第 k 帧的目标显示时间为：

       t_target = t0 + k / fps

   - 对每帧在完成全部计算与绘制后：

       now = time.time()
       delay = max(0, t_target - now)
       time.sleep(delay)
       cv2.waitKey(1)

   - 若计算耗时过长导致 now 已经晚于 t_target，则不再额外等待（delay 为 0），
     直接显示该帧，从而让整体时间轴尽可能跟随音轨，不刻意“追帧”。

   - 若 ffplay 不存在或用户关闭 --play_audio，则依然按上述墙钟时间轴调度画面，
     只是静音播放。

六、导出模拟结果为视频（含音轨，音轨来自输入 MP4）
---------------------------------------------------

本脚本支持将无人机模拟结果导出为 MP4 视频，并自动与原视频音轨合并：

1. 实时写出无音轨临时视频
   - 通过参数 --output_video 指定输出路径（如 ./output.mp4）；
   - 若提供该参数，脚本会创建一个临时无音轨 MP4 文件（例如 ./output_tmp_noaudio.mp4），
     使用 OpenCV VideoWriter 以 fourcc=mp4v、fps=源视频 fps、尺寸=舞台尺寸 (width, height)
     将每帧 canvas 写入该临时文件。

2. 使用 ffmpeg 复用音轨
   - 启动时检测系统是否存在 ffmpeg（通过 shutil.which("ffmpeg")）：
     * 若可用，在播放结束后自动调用一次合并命令，将临时无音轨视频与输入视频的音轨复用，
       生成最终 --output_video：

       ffmpeg -y -i output_tmp_noaudio.mp4 -i input.mp4 \
              -map 0:v:0 -map 1:a:0 -c:v copy -c:a copy -shortest output.mp4

     * 若因编解码器不兼容导致 copy 失败，会自动退化为：

       ffmpeg -y -i output_tmp_noaudio.mp4 -i input.mp4 \
              -map 0:v:0 -map 1:a:0 -c:v libx264 -pix_fmt yuv420p \
              -c:a copy -shortest output.mp4

   - 合并成功后自动删除临时无音轨文件，仅保留最终带声 MP4；
   - 音轨直接来自输入 MP4（--video 指定的文件），不需要用户额外提供 mp3。

3. 无 ffmpeg 时的行为
   - 若系统没有安装 ffmpeg，则仅保留无音轨临时视频，并在控制台提示：

     “系统未检测到 ffmpeg，已写出无音轨模拟视频；安装 ffmpeg 即可自动合并音轨。”

七、命令行参数说明（常用）
----------------------------

- --video (必选)：Bad Apple 视频文件路径（mp4/avi 等）。
- --num_drones：无人机数量，默认 300。
- --width, --height：舞台画布宽和高（像素），同时也是视频缩放后的尺寸。
- --min_gap：无人机之间的最小安全距离（像素），也用于 Poisson 采样点间距。
- --max_speed：无人机最大速度（像素/秒）。
- --threshold：灰度二值化阈值（0~255），默认 200。
- --auto_invert/--no_auto_invert：是否开启自动反色，默认开启；
  * 开启时，每帧在普通/反色二值化中自动选择亮像素较少的一侧；
  * 若显式加 --invert，则自动反色策略会被覆盖，始终按反色处理。
- --invert：强制使用反向二值化，将暗像素视为亮像素（适配反色视频）。
- --target_mode：目标点生成模式，可选 poisson 或 kmeans，默认 poisson。
- --max_targets：每帧最多目标点数量，默认等于 num_drones。
- --max_clusters：在 kmeans 模式下每帧 K-Means 的最大聚类数。
- --max_samples：每帧参与采样/聚类的亮像素最大候选数，用于控制性能。
- --repulsion_strength：斥力强度系数，适当增大可增强防碰撞能力。
- --repulsion_mode：斥力计算模式，grid 为近邻网格模式（默认），naive 为全量两两检查。
- --queue_size：多线程读帧队列长度（帧数上限），默认 16。
- --threads：线程数，>=2 时启用独立读帧线程，<2 时退化为单线程。
- --drone_radius：绘制无人机时的圆半径（像素）。
- --overlay_scale：左上角原视频缩略图相对于舞台宽度的缩放比例。
- --window_scale：显示窗口缩放比例，仅影响显示，不改变舞台尺寸，建议 0.3~1.0。
- --play_audio/--no_play_audio：是否通过 ffplay 播放输入视频音轨，默认开启 --play_audio。
- --output_video：将模拟结果导出为带音轨的 MP4 文件路径（如 ./output.mp4）。
- --no_show_original：不在画面角落叠加原始视频缩略图。

八、运行示例
--------------

1. 仅实时小窗播放（带音频）：

    python drone_bad_apple_sim.py --video ./bad_apple.mp4 \
        --num_drones 300 --width 960 --height 720 \
        --min_gap 8 --max_speed 200 --threshold 200 \
        --threads 2 --queue_size 32 --target_mode poisson \
        --window_scale 0.5

2. 实时播放并导出带音轨 MP4：

    python drone_bad_apple_sim.py --video ./bad_apple.mp4 \
        --num_drones 300 --width 960 --height 720 \
        --min_gap 8 --max_speed 200 --threshold 200 \
        --threads 2 --queue_size 32 --target_mode poisson \
        --window_scale 0.6 --output_video ./bad_apple_drones.mp4

运行后将弹出一个窗口显示无人机模拟效果，按 Q 可提前退出。
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
        help="显示窗口缩放比例（不影响内部舞台计算尺寸，建议 0.3~1.0）",
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

    # 若 min_gap 非正，退化为简单随机采样
    if min_gap <= 1e-3:
        m = min(max_points, n_points)
        idx = np.random.choice(n_points, size=m, replace=False)
        return points[idx].astype(np.float32)

    cell_size = float(min_gap) / math.sqrt(2.0)
    grid_w = max(1, int(math.ceil(width / cell_size)))
    grid_h = max(1, int(math.ceil(height / cell_size)))

    # 网格中存储 samples 列表的索引，-1 表示为空
    grid = [[-1] * grid_w for _ in range(grid_h)]
    samples = []

    order = np.random.permutation(n_points)
    min_gap2 = float(min_gap) * float(min_gap)

    for idx in order:
        p = points[idx]
        gx = int(p[0] / cell_size)
        gy = int(p[1] / cell_size)

        if gx < 0:
            gx = 0
        elif gx >= grid_w:
            gx = grid_w - 1
        if gy < 0:
            gy = 0
        elif gy >= grid_h:
            gy = grid_h - 1

        ok = True
        # 检查周围若干格（这里取 5x5 邻域）
        for ny in range(max(0, gy - 2), min(grid_h, gy + 3)):
            row = grid[ny]
            for nx in range(max(0, gx - 2), min(grid_w, gx + 3)):
                s_index = row[nx]
                if s_index == -1:
                    continue
                sp = samples[s_index]
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

    # 若因过于严格导致一个点都没采到，则退化为少量随机点
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

    # 转换为 (x, y)
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
    else:  # kmeans
        k = min(max_clusters, max_targets, points.shape[0])
        if k <= 0:
            return None
        return kmeans_cluster(points, k)


def stable_match_targets(prev_targets, new_centers, next_id):
    """在相邻帧之间稳定匹配目标点，维护连续的目标 ID。"""
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
    """为无人机分配目标点，优先保持之前跟随的目标，剩余采用就近贪心匹配。"""
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
                # 若两个点几乎重合，给一个随机方向避免数值问题
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
    cell_size = max(min_gap, 1.0)  # 单元格大小约为 min_gap
    inv_cell = 1.0 / cell_size
    min_gap2 = min_gap * min_gap

    # 构建网格：cell -> [indices]
    grid = {}
    for i in range(n):
        x, y = pos_after_attr[i]
        gx = int(x * inv_cell)
        gy = int(y * inv_cell)
        grid.setdefault((gx, gy), []).append(i)

    # 对每个点，只检查邻域 3x3 网格中的 j>i
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

    # 斥力修正
    if repulsion_mode == "naive":
        rep_corrections = _apply_repulsion_naive(pos_after_attr, min_gap, repulsion_strength)
    else:
        rep_corrections = _apply_repulsion_grid(pos_after_attr, min_gap, repulsion_strength)

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


def mux_video_with_audio(tmp_video_path, input_video_path, output_video_path, ffmpeg_path):
    """使用 ffmpeg 将无音轨视频与原始音轨复用为最终输出视频。

    返回 True 表示合并成功，False 表示失败（此时保留临时无音轨文件）。
    """
    # 尝试直接 copy 编解码参数
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
        fps = 30.0  # 若视频未提供 FPS，则使用默认值

    frame_count_total = cap.get(cv2.CAP_PROP_FRAME_COUNT)
    if frame_count_total is None:
        frame_count_total = 0.0

    dt = 1.0 / fps

    # 每帧目标数上限：默认等于无人机数
    if args.max_targets is None or args.max_targets <= 0:
        max_targets = args.num_drones
    else:
        max_targets = args.max_targets

    # kmeans 模式下的有效最大聚类数
    max_clusters = min(args.max_clusters, max_targets if max_targets > 0 else args.num_drones)

    use_threading = args.threads is not None and args.threads >= 2
    queue_size = max(1, int(args.queue_size))

    # 检测 ffmpeg / ffplay
    ffmpeg_path = shutil.which("ffmpeg")
    ffplay_path = shutil.which("ffplay")

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

    print("================= 模拟参数 =================")
    print(f"视频文件：{args.video}")
    if frame_count_total > 0 and not math.isnan(frame_count_total):
        print(f"视频帧数（约）：{int(frame_count_total)}")
    else:
        print("视频帧数（约）：未知")
    print(f"视频 FPS：{fps:.2f}，时间步长 dt = {dt:.4f} 秒")
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
        "读帧线程：{} (threads={}, queue_size={})".format(
            "启用" if use_threading else "未启用", args.threads, queue_size
        )
    )
    print(
        f"ffmpeg 可用性：{'可用' if ffmpeg_path else '不可用'}；"
        f" ffplay 可用性：{'可用' if ffplay_path else '不可用'}"
    )
    print(
        f"播放音频 play_audio：{'开启' if args.play_audio and ffplay_path else '关闭'}；"
        f" 输出视频：{args.output_video if args.output_video else '无'}"
    )
    print(f"窗口缩放 window_scale：{args.window_scale}")
    if write_video and tmp_video_path:
        print(f"无音轨临时视频路径：{tmp_video_path}")
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

    frame_count = 0
    last_log_time = time.time()
    last_bright_pixels = 0
    last_target_count = 0

    window_name = "Drone Bad Apple Simulation"
    cv2.namedWindow(window_name, cv2.WINDOW_NORMAL)

    # 设置读帧管线
    if use_threading:
        frame_queue = queue.Queue(maxsize=queue_size)

        def producer():
            """读帧线程：负责从 cap 读取并缩放到舞台尺寸。"""
            while True:
                ret, frame = cap.read()
                if not ret:
                    break
                frame_resized = cv2.resize(
                    frame,
                    (args.width, args.height),
                    interpolation=cv2.INTER_AREA,
                )
                frame_queue.put(frame_resized)
            cap.release()
            frame_queue.put(None)

        producer_thread = threading.Thread(target=producer, daemon=True)
        producer_thread.start()

        def get_frame():
            return frame_queue.get()

    else:

        def get_frame():
            ret, frame = cap.read()
            if not ret:
                return None
            frame_resized = cv2.resize(
                frame,
                (args.width, args.height),
                interpolation=cv2.INTER_AREA,
            )
            return frame_resized

    total_pixels = args.width * args.height

    # 启动音频播放（若可用）
    audio_proc = None
    t_start = None
    if args.play_audio and ffplay_path:
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
    elif args.play_audio and not ffplay_path:
        print("检测到 play_audio 开启，但系统未找到 ffplay，将静音播放。")

    while True:
        frame = get_frame()
        if frame is None:
            print("视频播放结束。")
            break

        frame_count += 1
        frame_index = frame_count - 1  # 用于墙钟时间轴

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
            # 用户显式指定反色，覆盖自动策略
            binary = cv2.bitwise_not(binary_normal)
            bright_count = bright_inv
        else:
            if args.auto_invert:
                # 选择亮像素数量较少的一方
                if bright_normal <= bright_inv:
                    binary = binary_normal
                    bright_count = bright_normal
                else:
                    binary = cv2.bitwise_not(binary_normal)
                    bright_count = bright_inv
            else:
                # 固定使用普通二值化
                binary = binary_normal
                bright_count = bright_normal

        # 提取亮像素候选点
        points = extract_bright_points(binary, args.max_samples)

        # 根据目标模式生成目标中心
        centers = generate_targets(
            points,
            mode=args.target_mode,
            max_targets=max_targets,
            max_clusters=max_clusters,
            width=args.width,
            height=args.height,
            min_gap=args.min_gap,
        )

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
            repulsion_mode=args.repulsion_mode,
        )

        # 当前帧统计
        last_bright_pixels = bright_count
        last_target_count = len(targets)

        # 准备绘制画布
        canvas = np.zeros((args.height, args.width, 3), dtype=np.uint8)

        # 绘制无人机
        draw_drones(drones, canvas, args.drone_radius)

        # 叠加原视频缩略图
        if not args.no_show_original:
            overlay_original(canvas, frame, scale=args.overlay_scale)

        # 写入无音轨临时视频
        if write_video and video_writer is not None:
            video_writer.write(canvas)

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

        # 墙钟时间轴调度，保证与音轨时间尽量同步
        if t_start is None:
            t_start = time.time()
        target_time = t_start + frame_index / fps
        now = time.time()
        delay = target_time - now
        if delay > 0:
            time.sleep(delay)

        # 小窗显示：根据 window_scale 缩放显示画面
        display_canvas = canvas
        scale = args.window_scale
        if scale is not None and scale > 0 and abs(scale - 1.0) > 1e-3:
            scale = max(0.1, float(scale))
            disp_w = max(1, int(args.width * scale))
            disp_h = max(1, int(args.height * scale))
            interp = cv2.INTER_AREA if scale < 1.0 else cv2.INTER_LINEAR
            display_canvas = cv2.resize(canvas, (disp_w, disp_h), interpolation=interp)

        cv2.imshow(window_name, display_canvas)

        key = cv2.waitKey(1) & 0xFF
        if key == ord("q") or key == ord("Q"):
            print("收到 Q 键，提前退出模拟。")
            break

        # 周期性打印当前模拟 FPS 与亮像素 / 目标数量
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

    # 停止音频进程
    if audio_proc is not None:
        try:
            audio_proc.terminate()
        except Exception:
            pass
        try:
            audio_proc.wait(timeout=2.0)
        except Exception:
            pass

    # 处理视频导出与音轨合并
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
                    "ffmpeg 合并音轨失败，已保留无音轨临时视频：" f"{tmp_video_path}\n"
                    "可检查 ffmpeg 安装或参数后重新运行脚本，或手动使用 ffmpeg 合并。"
                )
        else:
            print(
                f"系统未检测到 ffmpeg，已将无音轨模拟视频写入：{tmp_video_path}\n"
                "安装 ffmpeg 即可自动合并音轨（脚本会在运行结束后自动尝试复用音轨）。"
            )

    cv2.destroyAllWindows()

    # 任务完成提示
    print("脚本新增小窗与视频导出（含音轨）完成")


if __name__ == "__main__":
    main()
