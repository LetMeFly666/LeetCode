'''
Author: LetMeFly
Date: 2025-03-15 19:55:32
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-15 23:02:48
Description: 我的博客网站小爬虫 - https://github.com/LetMeFly666/LeetCode/issues/812
Description: 主要通过HTML标签取解析
Description: css中url并不解析，这不是浏览器模拟
Description: 如果不是blog.letmefly.xyz而是^(?!blog\.letmefly\.xyz$)[^.]*\.letmefly\.xyz$，则只访问一次并且不再递归
Description: 如果不是*.letmefly.xyz，则不访问（不知道它是否使用了缓存，别给我Ban了）
Description: 这些爬虫的访问并不会记入到网站统计的访问量中
URL: https://gist.github.com/LetMeFly666/6e85b177cdff0aca790aa391d3527796
'''
import requests
import sys
from bs4 import BeautifulSoup
from urllib.parse import urljoin, urlparse, urlsplit, urlunsplit


beginUrl = 'https://blog.letmefly.xyz'
toVisit = [beginUrl]
visited = set(toVisit)


"""
从 URL 中提取域名
:param url: 完整的 URL
:return: 域名（例如 "example.com"）
"""
def extractDomain(url) -> str:
    parsed_url = urlparse(url)
    domain = parsed_url.netloc
    if ':' in domain:  # 端口号
        domain = domain.split(':')[0]
    return domain


"""
清洗域名，去掉“?参数”和“#锚点”
"""
def cleanUrl(url: str) -> str:
    # 分解URL为五个部分
    parts = urlsplit(url)
    # 替换query和fragment为空字符串
    parts = parts._replace(query="", fragment="")
    # 重新组合URL
    url = urlunsplit(parts)
    if not url.endswith('/'):
        url += '/'
    return url


"""
处理一个新域名
"""
def parseNewDomain(url: str) -> None:
    if url in visited:
        return
    domain = extractDomain(url)
    if not domain.endswith('letmefly.xyz'):
        return
    toVisit.append(url)
    visited.add(url)


def get1page(url: str) -> None:
    print(f'Getting {url} ... ', end='')
    sys.stdout.flush()
    try:
        response = requests.get(url, timeout=5)
        soup = BeautifulSoup(response.text, 'lxml')
        print('Succeed')
    except:
        print('Failed')
        return
    
    domain = extractDomain(url)
    if domain.endswith('letmefly.xyz') and domain != 'blog.letmefly.xyz':
        return
    
    baseTag = soup.find('base')
    if baseTag:
        baseUrl = baseTag.get('href')
    else:
        baseUrl = url
    
    tagsToExtract = [
        ('a', 'href'),
        ('img', 'src'),
        ('link', 'href'),
        ('script', 'src'),
        ('iframe', 'src'),
        ('form', 'action')
    ]
    for tag, attr in tagsToExtract:
        for element in soup.find_all(tag):
            link = element.get(attr)
            if not link:
                continue
            absLink = urljoin(baseUrl, link)
            absLink = cleanUrl(absLink)
            parseNewDomain(absLink)
    

while toVisit:
    get1page(toVisit.pop())


# from urllib.parse import urlsplit, urlunsplit
# def remove_query_and_fragment(url):
#     # 分解URL为五个部分
#     parts = urlsplit(url)
#     # 替换query和fragment为空字符串
#     parts = parts._replace(query="", fragment="")
#     # 重新组合URL
#     return urlunsplit(parts)
# url = "http://example.com/path?name=test#section"
# clean_url = remove_query_and_fragment(url)
# print(clean_url)  # 输出：http://example.com/path
# url2 = "https://example.com/#frag"
# print(remove_query_and_fragment(url2))  # 输出：https://example.com/
# url3 = "http://example.com?query=123"
# print(remove_query_and_fragment(url3))  # 输出：http://example.com
# url4 = 'https://blog.letmefly.xyz/page/5/#board'
# print(remove_query_and_fragment(url4))

# test = urljoin('https://blog.letmefly.xyz', 'https://blog.letmefly.xyz/9999/12/31/README/')  # https://blog.letmefly.xyz/9999/12/31/README/
# print(test)