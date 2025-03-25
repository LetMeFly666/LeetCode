'''
Author: LetMeFly
Date: 2025-03-03 09:44:34
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-20 23:59:04
'''
from mitmproxy import http
from urllib.parse import parse_qs, urlencode
import logging
import re
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


key = bytes.fromhex('e3a9a39b3c95c109257aeb8c09cb8ad331779647c54de1a40a66d308f8e4a882')  # 演示用，实际可别公布

logger = logging.getLogger('logger_url')
formatter_url = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
for handler in logger.handlers[:]:
    if isinstance(handler, logging.StreamHandler):
        logger.removeHandler(handler)
logger.setLevel(logging.DEBUG)
filehandler_url = logging.FileHandler('url.log')
filehandler_url.setFormatter(formatter_url)
logger.addHandler(filehandler_url)
logger.info('url log init')

# https://chat.deepseek.com/a/chat/s/354e2ce6-8c46-41f3-b32b-944407aaf2f1
class AddSignatureAddon:
    def request(self, flow: http.HTTPFlow) -> None:
        if flow.request.method == "POST" and "/cgi-bin/compose_send" in flow.request.url:
            content_type = flow.request.headers.get("Content-Type", "")
            if "application/x-www-form-urlencoded" not in content_type:
                return
            # 解析原始表单数据
            try:
                parsed_data = parse_qs(flow.request.content.decode("utf-8"))
            except Exception as e:
                logger.info(f"解析表单数据失败: {e}")
                return

            # 修改content__html字段
            if "content__html" in parsed_data and parsed_data["content__html"]:
                original_content = parsed_data["content__html"][0]
                try:
                    with open('letsender', 'r', encoding='utf-8') as f:
                        hiddenMsg = f.read()
                except:
                    hiddenMsg = '计划有变'
                hiddenMsg = encrypt_aes(hiddenMsg, key).hex()
                new_content = original_content + f"*******{hiddenMsg}*******"
                parsed_data["content__html"][0] = new_content

                # 重新编码并更新请求内容
                updated_content = urlencode(parsed_data, doseq=True).encode("utf-8")
                flow.request.content = updated_content
                logger.info("成功添加签名！")
            else:
                logger.info("未找到content__html字段")
    

    def response(self, flow: http.HTTPFlow) -> None:
        if flow.request.method == 'GET' and '/cgi-bin/readmail' in flow.request.url:
            if "text/html" not in flow.response.headers.get("Content-Type", ""):
                return
            try:
                html_content = flow.response.content.decode("gb18030")
            except UnicodeDecodeError:
                logger.info('解码失败：可能不是GB18030编码')
            match = re.search(r'\*{7}(.*?)\*{7}', html_content)
            if match:
                signature = match.group(1)
                signature = decrypt_aes(signature, key)
                logger.info(f"提取到签名：{signature}")
                with open('letreceiver', 'w', encoding='utf-8') as f:
                    f.write(signature)
                html_content = re.sub(r'\*{7}.*?\*{7}', '', html_content)
            flow.response.content = html_content.encode("gb18030")
            flow.response.headers["Content-Length"] = str(len(flow.response.content))

addons = [AddSignatureAddon()]