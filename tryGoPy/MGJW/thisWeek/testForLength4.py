'''
Author: LetMeFly
Date: 2025-04-20 13:42:49
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-20 14:07:03
'''
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
from Crypto.Random import get_random_bytes
import base64

def aes_encrypt(plaintext, mode, key, iv=None):
    if mode == AES.MODE_ECB:
        cipher = AES.new(key, AES.MODE_ECB)
    elif mode == AES.MODE_CBC:
        cipher = AES.new(key, AES.MODE_CBC, iv)
    elif mode == AES.MODE_CFB:
        cipher = AES.new(key, AES.MODE_CFB, iv)
    elif mode == AES.MODE_OFB:
        cipher = AES.new(key, AES.MODE_OFB, iv)
    else:
        return

    padded_text = pad(plaintext.encode('utf-8'), AES.block_size)
    ciphertext = cipher.encrypt(padded_text)
    return ciphertext

def compare_aes_modes(plaintext):
    key = get_random_bytes(16)  # 目标是加密结果尽可能少，所以选择AES128而不是192或256
    iv = get_random_bytes(16)

    modes = [
        ("ECB", AES.MODE_ECB),
        ("CBC", AES.MODE_CBC),
        ("CFB", AES.MODE_CFB),
        ("OFB", AES.MODE_OFB)
    ]
    
    print(plaintext)
    
    results = []
    for name, mode in modes:
        # ECB模式不需要IV
        iv_param = iv if mode != AES.MODE_ECB else None
        ciphertext = aes_encrypt(plaintext, mode, key, iv_param)
        
        ciphertext_length = len(ciphertext)
        base64_length = len(base64.b64encode(ciphertext))
        
        results.append((name, ciphertext_length, base64_length))
        
        print(f"\n{name}")
        print(f"密文长度: {ciphertext_length}")
        print(f"Base64编码后长度: {base64_length}")
        print(f"Base64密文: {base64.b64encode(ciphertext).decode('utf-8')}")


plaintext = "test test test test test test handsome li test "
print(len(plaintext))
compare_aes_modes(plaintext)