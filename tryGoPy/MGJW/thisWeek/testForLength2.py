'''
Author: LetMeFly
Date: 2025-04-20 11:01:24
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-20 12:10:02
'''
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
import random


def encrypt_aes(plaintext: bytes, key: bytes) -> bytes:  # to后人：这次随机生成的直接是bytes
    cipher = AES.new(key, AES.MODE_CBC)
    ct_bytes = cipher.encrypt(pad(plaintext, AES.block_size))  # 因为plaintext是bytes类型，所以这里删掉了encode
    return cipher.iv + ct_bytes

def encryptOnce(msg: bytes):
    encrypted = encrypt_aes(msg, key)
    # print(encrypted.hex())
    print(len(msg), '->', len(encrypted.hex()))


key = bytes.fromhex('e3a9a39b3c95c109257aeb8c09cb8ad331779647c54de1a40a66d308f8e4a882')  # 演示用，实际可别公布
for originalLength in range(100):
    msg = random.randbytes(originalLength)
    encryptOnce(msg)