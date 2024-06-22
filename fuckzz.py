'''
Author: LetMeFly
Date: 2024-06-21 23:15:05
LastEditors: LetMeFly
LastEditTime: 2024-06-22 00:54:05
'''
import pyautogui
import time
import time
from datetime import datetime, timedelta

def sleepTo(hour, minute):
    # 设定目标时间为今天的1:23
    now = datetime.now()
    target_time = now.replace(hour=hour, minute=minute, second=0, microsecond=0)

    # # 如果当前时间已经超过1:23，设定目标时间为明天的1:23
    # if now >= target_time:
    #     target_time += timedelta(days=1)

    # 计算睡眠时间（秒）
    sleep_time = (target_time - now).total_seconds()

    # 睡眠直到目标时间
    time.sleep(sleep_time)

    # 睡眠结束后继续执行的代码
    print("到达目标时间，")


def send_enter_to_wechat():
    # 获取微信窗口的位置
    wechat_window = pyautogui.getWindowsWithTitle('微信')[0]
    time.sleep(1)
    wechat_window.activate()
    time.sleep(1)
    # 将光标移到微信窗口
    pyautogui.click(wechat_window.left + 10, wechat_window.top + 10)
    # 发送回车键
    pyautogui.press('enter')

# if __name__ == "__main__":
#     time.sleep(20)
#     send_enter_to_wechat()

# sleepTo(3, 58)
sleepTo(4, 3)
send_enter_to_wechat()