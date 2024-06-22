'''
Author: LetMeFly
Date: 2024-06-21 23:15:05
LastEditors: LetMeFly
LastEditTime: 2024-06-21 23:22:03
'''
import pyautogui
import time

def send_enter_to_wechat():
    # 获取微信窗口的位置
    wechat_window = pyautogui.getWindowsWithTitle('微信')[0]
    wechat_window.activate()
    # 将光标移到微信窗口
    pyautogui.click(wechat_window.left + 10, wechat_window.top + 10)
    # 发送回车键
    pyautogui.press('enter')

if __name__ == "__main__":
    time.sleep(20)
    send_enter_to_wechat()
