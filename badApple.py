import cv2
import sys
import numpy as np
import math
import time
from concurrent.futures import ThreadPoolExecutor

# ======================
# 参数
# ======================
GRID_W = 48
GRID_H = 36
DRONE_COUNT = 300
FPS = 32
V_MAX = 18.0
WINDOW_SCALE = 12
THRESH = 100
SMALL_WIN_SCALE = 0.25  # 左上角小窗口缩放比例
# ======================

class Drone:
    def __init__(self):
        self.x = np.random.uniform(0, GRID_W)
        self.y = np.random.uniform(0, GRID_H)
        self.tx = self.x
        self.ty = self.y
        self.on = False

    def set_target(self, tx, ty):
        self.tx = tx
        self.ty = ty

    def update(self, dt):
        dx = self.tx - self.x
        dy = self.ty - self.y
        dist = math.hypot(dx, dy)
        if dist < 1e-3:
            self.on = True
            return
        step = V_MAX * dt
        if step >= dist:
            self.x = self.tx
            self.y = self.ty
            self.on = True
        else:
            self.x += dx / dist * step
            self.y += dy / dist * step
            self.on = False

def process_frame(frame, reverse=False):
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    small = cv2.resize(gray, (GRID_W, GRID_H))
    _, bw = cv2.threshold(small, 127, 255, cv2.THRESH_BINARY)
    # 判断是否需要反转
    if reverse:
        bw = 255 - bw
    targets = np.column_stack(np.where(bw > 0))
    np.random.shuffle(targets)
    return bw, targets

def main(video_path):
    cap = cv2.VideoCapture(video_path)
    if not cap.isOpened():
        print("❌ 无法打开视频")
        return

    drones = [Drone() for _ in range(DRONE_COUNT)]
    dt = 1.0 / FPS

    cv2.namedWindow("Bad Apple Drone Simulation", cv2.WINDOW_NORMAL)

    last_time = time.time()

    # 多线程处理帧
    executor = ThreadPoolExecutor(max_workers=2)

    while True:
        ret, frame = cap.read()
        if not ret:
            break

        now = time.time()
        sleep_time = dt - (now - last_time)
        if sleep_time > 0:
            time.sleep(sleep_time)
        last_time = time.time()

        # 判断是否反转色
        gray_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        num_black = np.sum(gray_frame < 127)
        num_white = np.sum(gray_frame >= 127)
        reverse = num_black > num_white  # 黑色占多数 → 反转

        # 异步处理帧
        future = executor.submit(process_frame, frame.copy(), reverse)
        bw, targets = future.result()

        # 设置无人机目标
        for d in drones:
            d.set_target(d.x, d.y)
            d.on = False

        used = set()
        for ty, tx in targets:
            best = None
            best_dist = 1e9
            for i, d in enumerate(drones):
                if i in used:
                    continue
                dist = math.hypot(d.x - tx, d.y - ty)
                if dist < best_dist:
                    best_dist = dist
                    best = (i, d)
            if best:
                i, d = best
                d.set_target(tx, ty)
                used.add(i)
                if len(used) >= DRONE_COUNT:
                    break

        # 更新无人机位置
        for d in drones:
            d.update(dt)

        # ================= 可视化 =================
        canvas = np.zeros((GRID_H, GRID_W, 3), dtype=np.uint8)  # 全黑底

        for d in drones:
            cx, cy = int(d.x), int(d.y)
            if 0 <= cx < GRID_W and 0 <= cy < GRID_H:
                if d.on:
                    canvas[cy, cx] = (255, 255, 255)  # 点亮
                else:
                    canvas[cy, cx] = (30, 30, 30)    # 熄灭

        canvas = cv2.resize(canvas, (GRID_W*WINDOW_SCALE, GRID_H*WINDOW_SCALE),
                            interpolation=cv2.INTER_NEAREST)

        # 左上角小窗口显示原视频
        small_win = cv2.resize(frame, (0,0), fx=SMALL_WIN_SCALE, fy=SMALL_WIN_SCALE)
        h, w, _ = small_win.shape
        canvas[0:h,0:w] = small_win

        cv2.imshow("Bad Apple Drone Simulation", canvas)
        if cv2.waitKey(1) in (27, ord('q')):
            break

    cap.release()
    cv2.destroyAllWindows()
    executor.shutdown()

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("用法: python badapple_drones.py bad_apple.mp4")
        sys.exit(0)
    main(sys.argv[1])
