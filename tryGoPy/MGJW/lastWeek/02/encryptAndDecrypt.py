'''
Author: LetMeFly
Date: 2025-03-20 21:27:16
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-20 22:39:28
'''
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad


def encrypt_aes(plaintext: str, key: bytes) -> bytes:
    cipher = AES.new(key, AES.MODE_CBC)  # 使用CBC模式
    ct_bytes = cipher.encrypt(pad(plaintext.encode(), AES.block_size))
    return cipher.iv + ct_bytes  # 返回IV + 密文


def decrypt_aes(ciphertext: bytes, key: bytes) -> str:
    iv = ciphertext[:AES.block_size]
    ct = ciphertext[AES.block_size:]  # 密文
    cipher = AES.new(key, AES.MODE_CBC, iv)
    pt = unpad(cipher.decrypt(ct), AES.block_size)
    return pt.decode()

msg = '其实今天要进攻'
key = bytes.fromhex('e3a9a39b3c95c109257aeb8c09cb8ad331779647c54de1a40a66d308f8e4a882')  # 演示用，实际可别公布
encrypted = encrypt_aes(msg, key)
print(encrypted.hex())
decrypt = decrypt_aes(encrypted, key)
print(decrypt)

