import cv2
import sys
import numpy as np
import math
import time

# ======================
# 参数
# ======================
GRID_W = 48
GRID_H = 36
DRONE_COUNT = 120
FPS = 15
V_MAX = 18.0         # 像素 / 秒
THRESH = 100
WINDOW_SCALE = 12
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


def main(video_path):
    cap = cv2.VideoCapture(video_path)
    if not cap.isOpened():
        print("❌ 无法打开视频")
        return

    drones = [Drone() for _ in range(DRONE_COUNT)]
    dt = 1.0 / FPS

    cv2.namedWindow("Bad Apple Drone Simulation", cv2.WINDOW_NORMAL)

    last_time = time.time()

    while True:
        ret, frame = cap.read()
        if not ret:
            break

        # 控制帧率
        now = time.time()
        sleep_time = dt - (now - last_time)
        if sleep_time > 0:
            time.sleep(sleep_time)
        last_time = time.time()

        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        small = cv2.resize(gray, (GRID_W, GRID_H))
        _, bw = cv2.threshold(
            small, THRESH, 255, cv2.THRESH_BINARY_INV
        )

        targets = np.column_stack(np.where(bw > 0))  # (y, x)
        np.random.shuffle(targets)

        # 重置目标
        for d in drones:
            d.set_target(d.x, d.y)
            d.on = False

        # === 目标分配（每架无人机最多一个） ===
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
        canvas = np.zeros((GRID_H, GRID_W, 3), dtype=np.uint8)

        # 背景轮廓
        canvas[bw > 0] = (40, 40, 40)

        for d in drones:
            cx, cy = int(d.x), int(d.y)
            if 0 <= cx < GRID_W and 0 <= cy < GRID_H:
                if d.on:
                    canvas[cy, cx] = (255, 255, 255)
                else:
                    canvas[cy, cx] = (150, 150, 150)

        canvas = cv2.resize(
            canvas,
            (GRID_W * WINDOW_SCALE, GRID_H * WINDOW_SCALE),
            interpolation=cv2.INTER_NEAREST
        )

        cv2.imshow("Bad Apple Drone Simulation", canvas)
        if cv2.waitKey(1) in (27, ord('q')):
            break

    cap.release()
    cv2.destroyAllWindows()


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("用法: python badapple_drones.py bad_apple.mp4")
        sys.exit(0)

    main(sys.argv[1])
