'''
Author: LetMeFly
Date: 2025-03-03 09:44:34
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-03 12:11:57
'''
from mitmproxy import http
import logging

logger_url = logging.getLogger('logger_url')
filehandler_url = logging.FileHandler('url.log')
logger_url.addHandler(filehandler_url)

logger_text = logging.getLogger('logger_text')
filehandler_text = logging.FileHandler('text.log')
logger_text.addHandler(filehandler_text)


def request(flow: http.HTTPFlow) -> None:
    # 修改请求
    if "letmefly.xyz" in flow.request.pretty_url:
        flow.request.headers["User-Agent"] = "Modified-Agent"

def response(flow: http.HTTPFlow) -> None:
    # 修改响应
    logger_url.info(flow.request.pretty_url)
    if "web.letmefly.xyz" in flow.request.pretty_url:
    # if flow.request.pretty_url == 'https://web.letmefly.xyz/':
        logger_url.info('replace HTML to LMTH')
        logger_text.info(str(flow.response.text))
        flow.response.text = flow.response.text.replace("HTML", "LMTH")