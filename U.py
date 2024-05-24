'''
Author: LetMeFly
Date: 2024-05-24 11:34:03
LastEditors: LetMeFly
LastEditTime: 2024-05-24 21:27:53
Description: 当U盘插入时printU盘盘符
'''
import win32api
import win32con
import win32gui
import ctypes

# 定义DEV_BROADCAST_DEVICEINTERFACE结构体
class DEV_BROADCAST_DEVICEINTERFACE(ctypes.Structure):
    _fields_ = [
        ("dbcc_size", ctypes.c_ulong),
        ("dbcc_devicetype", ctypes.c_ulong),
        ("dbcc_reserved", ctypes.c_ulong),
        ("dbcc_classguid", ctypes.c_byte * 16),
        ("dbcc_name", ctypes.c_wchar * 1)
    ]

class DEV_BROADCAST_HDR(ctypes.Structure):
    _fields_ = [
        ("dbch_size", ctypes.c_ulong),
        ("dbch_devicetype", ctypes.c_ulong),
        ("dbch_reserved", ctypes.c_ulong)
    ]

class DEV_BROADCAST_VOLUME(ctypes.Structure):
    _fields_ = [
        ("dbcv_size", ctypes.c_ulong),
        ("dbcv_devicetype", ctypes.c_ulong),
        ("dbcv_reserved", ctypes.c_ulong),
        ("dbcv_unitmask", ctypes.c_ulong),
        ("dbcv_flags", ctypes.c_ushort)
    ]

class USBWatcher:
    def __init__(self):
        message_map = {
            win32con.WM_DEVICECHANGE: self.on_device_change
        }

        wc = win32gui.WNDCLASS()
        wc.lpfnWndProc = message_map
        wc.lpszClassName = 'USBWatcher'
        self.hinst = wc.hInstance = win32api.GetModuleHandle(None)
        self.classAtom = win32gui.RegisterClass(wc)
        self.hwnd = win32gui.CreateWindow(self.classAtom, 'USBWatcher', 0, 0, 0, 0, 0, 0, 0, self.hinst, None)

        self.register_device_notification()

    def register_device_notification(self):
        filter = DEV_BROADCAST_DEVICEINTERFACE()
        filter.dbcc_size = ctypes.sizeof(DEV_BROADCAST_DEVICEINTERFACE)
        filter.dbcc_devicetype = win32con.DBT_DEVTYP_DEVICEINTERFACE
        filter.dbcc_classguid = (ctypes.c_byte * 16)(*([0] * 16))  # 使用全零的GUID
        self.hdev_notify = ctypes.windll.user32.RegisterDeviceNotificationW(
            self.hwnd,
            ctypes.byref(filter),
            win32con.DEVICE_NOTIFY_WINDOW_HANDLE
        )

    def on_device_change(self, hwnd, msg, wp, lp):
        if wp == win32con.DBT_DEVICEARRIVAL:
            device = ctypes.cast(lp, ctypes.POINTER(DEV_BROADCAST_HDR))
            if device.contents.dbch_devicetype == win32con.DBT_DEVTYP_VOLUME:
                volume = ctypes.cast(lp, ctypes.POINTER(DEV_BROADCAST_VOLUME))
                drive_letter = self.get_drive_letter(volume.contents.dbcv_unitmask)
                print(f"USB drive inserted, drive letter: {drive_letter}")
        return 1

    def get_drive_letter(self, unitmask):
        for i in range(26):
            if unitmask & (1 << i):
                return chr(ord('A') + i) + ':\\'
        return None

    def run(self):
        win32gui.PumpMessages()

if __name__ == "__main__":
    watcher = USBWatcher()
    watcher.run()
