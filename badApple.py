import cv2
import sys
import numpy as np
import math
import time

# ======================
# 参数区（你可以调）
# ======================
GRID_W = 48          # 横向像素数
GRID_H = 36          # 纵向像素数
DRONE_COUNT = 120    # 无人机数量
FPS = 15
V_MAX = 12.0         # 最大速度（像素 / 秒）
THRESH = 100         # 二值化阈值
WINDOW_SCALE = 12    # 显示放大倍率
# ======================


class Drone:
    def __init__(self):
        self.x = np.random.uniform(0, GRID_W)
        self.y = np.random.uniform(0, GRID_H)
        self.on = False

    def can_reach(self, tx, ty, dt):
        dist = math.hypot(self.x - tx, self.y - ty)
        return dist <= V_MAX * dt

    def move_to(self, tx, ty):
        self.x = tx
        self.y = ty
        self.on = True


def load_video(path):
    cap = cv2.VideoCapture(path)
    if not cap.isOpened():
        print("❌ 无法打开视频:", path)
        sys.exit(1)
    return cap


def main(video_path):
    cap = load_video(video_path)
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

        # 灰度 + 缩放
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        small = cv2.resize(gray, (GRID_W, GRID_H))
        _, bw = cv2.threshold(small, THRESH, 255, cv2.THRESH_BINARY_INV)

        # 本帧目标像素
        targets = np.column_stack(np.where(bw > 0))  # (y, x)
        np.random.shuffle(targets)

        # 重置灯状态
        for d in drones:
            d.on = False

        # 贪心分配
        for (ty, tx) in targets:
            best = None
            best_dist = 1e9
            for d in drones:
                if d.on:
                    continue
                if d.can_reach(tx, ty, dt):
                    dist = math.hypot(d.x - tx, d.y - ty)
                    if dist < best_dist:
                        best_dist = dist
                        best = d
            if best is not None:
                best.move_to(tx, ty)

        # =====================
        # 可视化
        # =====================
        canvas = np.zeros((GRID_H, GRID_W, 3), dtype=np.uint8)

        # 目标轮廓（暗灰）
        canvas[bw > 0] = (50, 50, 50)

        # 无人机
        for d in drones:
            cx, cy = int(d.x), int(d.y)
            if 0 <= cx < GRID_W and 0 <= cy < GRID_H:
                if d.on:
                    canvas[cy, cx] = (255, 255, 255)
                else:
                    canvas[cy, cx] = (120, 120, 120)

        # 放大显示
        canvas = cv2.resize(
            canvas,
            (GRID_W * WINDOW_SCALE, GRID_H * WINDOW_SCALE),
            interpolation=cv2.INTER_NEAREST
        )

        cv2.imshow("Bad Apple Drone Simulation", canvas)

        key = cv2.waitKey(1)
        if key == 27 or key == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows()


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("用法: python badapple_drones.py bad_apple.mp4")
        sys.exit(0)

    main(sys.argv[1])
