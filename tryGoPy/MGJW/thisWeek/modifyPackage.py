'''
Author: LetMeFly
Date: 2025-03-03 09:44:34
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-06 17:17:01
'''
from mitmproxy import http
from urllib.parse import parse_qs, urlencode
import logging

logger_url = logging.getLogger('logger_url')
formatter_url = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
for handler in logger_url.handlers[:]:
    if isinstance(handler, logging.StreamHandler):
        logger_url.removeHandler(handler)
logger_url.setLevel(logging.DEBUG)
filehandler_url = logging.FileHandler('url.log')
filehandler_url.setFormatter(formatter_url)
logger_url.addHandler(filehandler_url)


logger_text = logging.getLogger('logger_text')
formatter_text = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
for handler in logger_text.handlers[:]:
    if isinstance(handler, logging.StreamHandler):
        logger_text.removeHandler(handler)
logger_text.setLevel(logging.DEBUG)
filehandler_text = logging.FileHandler('text.log')
filehandler_text.setFormatter(formatter_text)
logger_text.addHandler(filehandler_text)


# def request(flow: http.HTTPFlow) -> None:
#     # 修改请求
#     # if "letmefly.xyz" in flow.request.pretty_url:
#     if "web.letmefly.xyz" in flow.request.pretty_url and 'text/html' in flow.response.headers.get('content-type', ''):
#         # flow.request.headers["User-Agent"] = "Modified-Agent"
#         flow.request.text  # 暂时未知
#     pass

# def response(flow: http.HTTPFlow) -> None:
#     # 修改响应
#     logger_url.info(flow.request.pretty_url)
#     if "web.letmefly.xyz" in flow.request.pretty_url and 'text/html' in flow.response.headers.get('content-type', ''):
#     # if flow.request.pretty_url == 'https://web.letmefly.xyz/':
#         logger_url.info('replace HTML to LMTH')
#         # logger_text.info(flow.response.text)
#         flow.response.text = flow.response.text.replace("HTML", "LMTH")

# https://chat.deepseek.com/a/chat/s/354e2ce6-8c46-41f3-b32b-944407aaf2f1
class AddSignatureAddon:
    def request(self, flow: http.HTTPFlow) -> None:
        # 检查目标路径和请求方法
        if flow.request.method == "POST" and "/cgi-bin/compose_send" in flow.request.url:
            # 确保Content-Type正确
            content_type = flow.request.headers.get("Content-Type", "")
            if "application/x-www-form-urlencoded" in content_type:
                # 解析原始表单数据
                try:
                    parsed_data = parse_qs(flow.request.content.decode("utf-8"))
                except Exception as e:
                    logger_url(f"解析表单数据失败: {e}")
                    return

                # 修改content__html字段
                if "content__html" in parsed_data and parsed_data["content__html"]:
                    original_content = parsed_data["content__html"][0]
                    new_content = original_content + "*******签名*******"
                    parsed_data["content__html"][0] = new_content

                    # 重新编码并更新请求内容
                    updated_content = urlencode(parsed_data, doseq=True).encode("utf-8")
                    flow.request.content = updated_content
                    logger_url("成功添加签名！")
                else:
                    logger_url("未找到content__html字段")

addons = [AddSignatureAddon()]