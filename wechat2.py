import pyautogui
import time
import win32gui

def send_enter_to_window(window_title):
    hwnd = win32gui.FindWindow(None, window_title)
    if hwnd:
        print(hwnd)
        win32gui.SetForegroundWindow(hwnd)
        pyautogui.press('enter')
    else:
        print('window not found')

if __name__ == "__main__":
    window_title = "微信"  # 替换为目标窗口的标题
    time.sleep(20)
    send_enter_to_window(window_title)
