'''
Author: LetMeFly
Date: 2025-03-03 09:44:34
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-04 16:49:14
'''
from mitmproxy import http
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


def request(flow: http.HTTPFlow) -> None:
    # 修改请求
    # if "letmefly.xyz" in flow.request.pretty_url:
    if "web.letmefly.xyz" in flow.request.pretty_url and 'text/html' in flow.response.headers.get('content-type', ''):
        # flow.request.headers["User-Agent"] = "Modified-Agent"
        flow.request.text  # 暂时未知
    pass

def response(flow: http.HTTPFlow) -> None:
    # 修改响应
    logger_url.info(flow.request.pretty_url)
    if "web.letmefly.xyz" in flow.request.pretty_url and 'text/html' in flow.response.headers.get('content-type', ''):
    # if flow.request.pretty_url == 'https://web.letmefly.xyz/':
        logger_url.info('replace HTML to LMTH')
        # logger_text.info(flow.response.text)
        flow.response.text = flow.response.text.replace("HTML", "LMTH")