flask写一个简单的web服务，实现一个邮件与信标id的对应功能。实现以下功能：
1. 前端用户可以输入一些文本，这些文本会传到后端并以aes加密，作为信标id并显示在前端界面上
2. 前端用户可以查看邮件（文本）与信标id的一一对应关系列表。
3. 数据存储使用简单的写入和读取json文件即可。

其中，加密算法可参考：
def encrypt_aes(plaintext: str, key: bytes) -> bytes:
    cipher = AES.new(key, AES.MODE_CBC)  # 使用CBC模式
    ct_bytes = cipher.encrypt(pad(plaintext.encode(), AES.block_size))
    return cipher.iv + ct_bytes  # 返回IV + 密文