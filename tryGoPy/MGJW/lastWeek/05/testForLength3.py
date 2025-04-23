'''
Author: LetMeFly
Date: 2025-04-20 12:57:49
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-20 12:57:51
'''
import base64

# AES加密后的原始字节
ciphertext = b'\x4d\x61\x6e\x79\x20\x73\x74\x72\x69\x6e\x67\x73'

# 转换为Base64
base64_str = base64.b64encode(ciphertext).decode('ascii')
print(base64_str)  # 输出: TWlueSBzdHJpbmdz