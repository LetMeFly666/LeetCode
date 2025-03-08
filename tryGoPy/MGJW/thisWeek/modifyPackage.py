'''
Author: LetMeFly
Date: 2025-03-03 09:44:34
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-08 11:35:26
'''
from mitmproxy import http
from urllib.parse import parse_qs, urlencode
import logging
import re

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


# logger_text = logging.getLogger('logger_text')
# formatter_text = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
# for handler in logger_text.handlers[:]:
#     if isinstance(handler, logging.StreamHandler):
#         logger_text.removeHandler(handler)
# logger_text.setLevel(logging.DEBUG)
# filehandler_text = logging.FileHandler('text.log')
# filehandler_text.setFormatter(formatter_text)
# logger_text.addHandler(filehandler_text)


# def request(flow: http.HTTPFlow) -> None:
#     # 修改请求
#     # if "letmefly.xyz" in flow.request.pretty_url:
#     if "web.letmefly.xyz" in flow.request.pretty_url and 'text/html' in flow.response.headers.get('content-type', ''):
#         # flow.request.headers["User-Agent"] = "Modified-Agent"
#         flow.request.text  # 暂时未知
#     pass

# def response(flow: http.HTTPFlow) -> None:
#     # 修改响应
#     logger.info(flow.request.pretty_url)
#     if "web.letmefly.xyz" in flow.request.pretty_url and 'text/html' in flow.response.headers.get('content-type', ''):
#     # if flow.request.pretty_url == 'https://web.letmefly.xyz/':
#         logger.info('replace HTML to LMTH')
#         # logger_text.info(flow.response.text)
#         flow.response.text = flow.response.text.replace("HTML", "LMTH")

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
            # soup = BeautifulSoup(html_content, "lxml")
            # content_div = soup.find("div", {"id": "mailContentContainer"})
            # logger.info(f'{content_div}')
            # if not content_div:
            #     return
            # text_nodes = content_div.find_all(text=True, recursive=True)
            # for node in text_nodes:
            #     # 匹配签名模式（支持动态内容）
            #     match = re.search(r'\*{7}(.*?)\*{7}', node.string)
            #     if match:
            #         signature = match.group(1)
            #         print(f"提取到签名：{signature}")
            #         clean_text = re.sub(r'\*{7}.*?\*{7}', '', node.string)
            #         node.replace_with(clean_text)
            # # 不知道为啥，BS解析后直接把头部的编码给改了
            # meta_tag = soup.find("meta", attrs={"http-equiv": "Content-Type"})
            # if meta_tag:
            #     meta_tag["content"] = "text/html; charset=gb18030"
            match = re.search(r'\*{7}(.*?)\*{7}', html_content)
            if match:
                signature = match.group(1)
                logger.info(f"提取到签名：{signature}")
                with open('letreceiver', 'w', encoding='utf-8') as f:
                    f.write(signature)
                html_content = re.sub(r'\*{7}.*?\*{7}', '', html_content)
            flow.response.content = html_content.encode("gb18030")
            flow.response.headers["Content-Length"] = str(len(flow.response.content))

addons = [AddSignatureAddon()]