'''
Author: LetMeFly
Date: 2024-10-17 17:28:54
LastEditors: LetMeFly
LastEditTime: 2024-10-18 16:49:08
'''
import ctypes
from ctypes import wintypes
import getpass

def login(password: str):
    advapi32 = ctypes.WinDLL('advapi32', use_last_error=True)
    kernel32 = ctypes.windll.kernel32
    LOGON32_LOGON_INTERACTIVE = 2
    LOGON32_PROVIDER_DEFAULT = 0
    token = wintypes.HANDLE()
    username = getpass.getuser()
    success = advapi32.LogonUserW(username, None, password, LOGON32_LOGON_INTERACTIVE, LOGON32_PROVIDER_DEFAULT, ctypes.byref(token))
    kernel32.CloseHandle(token)
    return success

 
if __name__ == "__main__":
    while True:
        password = getpass.getpass("Enter Password: ")
        if login(password):
            print('Login Successful.')
            break
        else:
            print('Login Failed.')