'''
Author: LetMeFly
Date: 2025-03-28 00:33:18
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-28 00:34:28
'''
from Crypto.Cipher import AES
from Crypto.Util.Padding import unpad
from binascii import unhexlify

def decrypt_aes(ciphertext: bytes, key: bytes) -> str:
    iv = ciphertext[:AES.block_size]
    ct = ciphertext[AES.block_size:]  # 密文
    cipher = AES.new(key, AES.MODE_CBC, iv)
    pt = unpad(cipher.decrypt(ct), AES.block_size)
    return pt.decode()

encrypted = '1a8c06cbcd61e779f815d36369ce04b9c105f94d58dca2eb65bf08ef4af993cdc38b9e4e456e56a9fe8fd1e1a3212e78'
encrypted = unhexlify(encrypted)
key = bytes.fromhex('e3a9a39b3c95c109257aeb8c09cb8ad331779647c54de1a40a66d308f8e4a882')  # 演示用
decrypt = decrypt_aes(encrypted, key)
print(decrypt)