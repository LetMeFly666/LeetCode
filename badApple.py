# -*- coding: utf-8 -*-
"""
Bad Apple 黑白像素无人机群表演模拟（多线程优化版）
=====================================================================
"""

import cv2
import numpy as np
import threading
import queue
import time
import argparse

# ------------------ 参数配置 ------------------
parser = argparse.ArgumentParser()
parser.add_argument('--video', type=str, required=True, help="输入视频路径")
parser.add_argument('--width', type=int, default=80, help="无人机舞台宽度")
parser.add_argument('--height', type=int, default=60, help="无人机舞台高度")
parser.add_argument('--num_drones', type=int, default=200, help="无人机数量")
parser.add_argument('--threads', type=int, default=1, help="线程数")
parser.add_argument('--frame_skip', action='store_true', help="启用帧跳过同步")
parser.add_argument('--show', action='store_true', help="显示模拟窗口")
parser.add_argument('--output', type=str, default=None, help="输出视频路径")
args = parser.parse_args()

# ------------------ 初始化 ------------------
cap = cv2.VideoCapture(args.video)
fps = cap.get(cv2.CAP_PROP_FPS)
frame_count = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))

stage_w, stage_h = args.width, args.height
num_drones = args.num_drones

# 无人机状态初始化
drones_pos = np.random.rand(num_drones, 2) * np.array([stage_w, stage_h])
drones_vel = np.zeros((num_drones, 2), dtype=np.float32)

# 画布
canvas = np.zeros((stage_h, stage_w), dtype=np.uint8)

# ------------------ 多线程队列 ------------------
frame_queue = queue.Queue(maxsize=32)
stop_event = threading.Event()

def producer(cap, queue, stop_event, width, height):
    idx = 0
    while not stop_event.is_set():
        ret, frame = cap.read()
        if not ret:
            break
        frame_resized = cv2.resize(frame, (width, height), interpolation=cv2.INTER_AREA)
        try:
            queue.put((idx, frame_resized), timeout=0.1)
        except queue.Full:
            pass
        idx += 1
    stop_event.set()

if args.threads >= 2:
    t = threading.Thread(target=producer, args=(cap, frame_queue, stop_event, stage_w, stage_h))
    t.start()

# ------------------ 帧处理函数 ------------------
def process_frame(frame):
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    _, binary = cv2.threshold(gray, 127, 255, cv2.THRESH_BINARY)
    points = np.argwhere(binary > 0)[:, ::-1]  # (x, y)
    return points

# ------------------ 无人机更新函数 ------------------
def update_drones(drones_pos, drones_vel, targets, dt=0.2, speed_limit=1.0):
    """
    drones_pos: (N,2)
    drones_vel: (N,2)
    targets: (N,2)
    """
    direction = targets - drones_pos
    distance = np.linalg.norm(direction, axis=1, keepdims=True)
    distance[distance==0] = 1e-6  # 避免除零
    desired_vel = direction / distance * 0.5  # 速度系数
    drones_vel += (desired_vel - drones_vel) * 0.5
    speed = np.linalg.norm(drones_vel, axis=1, keepdims=True)
    factor = np.minimum(1, speed_limit / (speed + 1e-6))
    drones_vel *= factor
    drones_pos += drones_vel * dt
    return drones_pos, drones_vel

# ------------------ 绘制函数 ------------------
def draw_drones(drones_pos, stage_w, stage_h):
    canvas = np.zeros((stage_h, stage_w), dtype=np.uint8)
    for x, y in drones_pos:
        ix, iy = int(x), int(y)
        if 0 <= ix < stage_w and 0 <= iy < stage_h:
            canvas[iy, ix] = 255
    return canvas

# ------------------ 输出视频 ------------------
if args.output is not None:
    fourcc = cv2.VideoWriter_fourcc(*'XVID')
    out = cv2.VideoWriter(args.output, fourcc, fps, (stage_w, stage_h), False)
else:
    out = None

# ------------------ 主循环 ------------------
t_start = time.time()
frame_idx = 0
while True:
    # 读取帧
    if args.threads >= 2:
        try:
            frame_idx, frame = frame_queue.get(timeout=0.1)
        except queue.Empty:
            if stop_event.is_set() and frame_queue.empty():
                break
            continue
    else:
        ret, frame = cap.read()
        if not ret:
            break
        frame = cv2.resize(frame, (stage_w, stage_h), interpolation=cv2.INTER_AREA)
    
    # 帧跳过同步
    if args.frame_skip:
        now = time.time()
        expected_idx = int((now - t_start) * fps)
        if frame_idx < expected_idx:
            continue

    # 处理帧
    points = process_frame(frame)
    if len(points) < num_drones:
        # 随机补齐
        extra = np.random.rand(num_drones - len(points), 2) * np.array([stage_w, stage_h])
        targets = np.vstack([points, extra])
    else:
        indices = np.random.choice(len(points), num_drones, replace=False)
        targets = points[indices]

    # 更新无人机
    drones_pos, drones_vel = update_drones(drones_pos, drones_vel, targets)

    # 绘制
    canvas = draw_drones(drones_pos, stage_w, stage_h)

    # 显示
    if args.show:
        cv2.imshow('Drone Simulation', canvas)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    # 写视频
    if out:
        out.write(canvas)

# ------------------ 清理 ------------------
cap.release()
if out:
    out.release()
cv2.destroyAllWindows()
stop_event.set()
if args.threads >= 2:
    t.join()

# python badApple2.py --video ~/Downloads/badApple.mp4 --num_drones=400 --max_speed=500 --width=480 --height=360
# python badApple2.py --video ~/Downloads/badApple.mp4 --num_drones=1000 --max_speed=500 --width=960 --height=720
# python badApple2.py --video mini.mp4 --num_drones=1000 --max_speed=500 --width=960 --height=720 --output_video ./bad_apple_drones.mp4