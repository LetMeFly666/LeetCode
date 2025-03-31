'''
Author: LetMeFly
Date: 2025-03-21 15:41:42
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-21 15:42:18
'''
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad


def encrypt_aes(plaintext: str, key: bytes) -> bytes:
    cipher = AES.new(key, AES.MODE_CBC)  # 使用CBC模式
    ct_bytes = cipher.encrypt(pad(plaintext.encode(), AES.block_size))
    return cipher.iv + ct_bytes  # 返回IV + 密文



msg = '其实今天要进攻'
key = bytes.fromhex('e3a9a39b3c95c109257aeb8c09cb8ad331779647c54de1a40a66d308f8e4a882')  # 演示用，实际可别公布
encrypted = encrypt_aes(msg, key)
print(encrypted.hex())

