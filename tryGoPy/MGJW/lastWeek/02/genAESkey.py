'''
Author: LetMeFly
Date: 2025-03-20 21:09:41
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-20 21:09:50
'''
from Crypto.Random import get_random_bytes

# 生成256位（32字节）AES密钥
key = get_random_bytes(32)
print("AES Key:", key.hex())  # 以16进制字符串形式保存密钥
