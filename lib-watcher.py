#!/usr/bin/env python3
"""
北邮图书馆《埃隆·马斯克传》西土城校区在架可借状态监控脚本
每15分钟检查一次，如有西土城在架可借则通过Bark通知

其实多match了一个，检测结果是4本，但是无所谓
"""
from __future__ import annotations

import re
import sys
import time
import logging
import urllib.request
import urllib.error
import urllib.parse
from datetime import datetime

# ============ 配置 ============
BOOK_URL = "http://opac.bupt.edu.cn:8080//bookInfo_01h0483291.html"
BARK_URL = "http://localhost:xxxx/xxxxxxxx"
CHECK_INTERVAL = 15 * 60  # 15分钟（秒）
TIMEOUT = 15  # HTTP请求超时（秒）

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s [%(levelname)s] %(message)s",
    datefmt="%Y-%m-%d %H:%M:%S",
)
log = logging.getLogger(__name__)


def fetch_page(url):
    """获取页面HTML内容"""
    req = urllib.request.Request(
        url,
        headers={
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 "
                          "(KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36",
            "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8",
        },
    )
    with urllib.request.urlopen(req, timeout=TIMEOUT) as resp:
        charset = resp.headers.get_content_charset() or "utf-8"
        return resp.read().decode(charset)


def parse_collection(html):
    """
    用正则解析馆藏表格。
    匹配每个<tr>块中同时包含条码号和馆藏部门/状态的行。
    """
    results = []
    barcode_pattern = re.compile(r"2111\d{10}")
    dept_pattern = re.compile(r"((?:西土城|沙河)[：:][^<\n]+)")
    status_keywords = ["在架可借", "本馆借出", "阅览", "预约", "装订中", "编目中"]

    tr_blocks = re.findall(r"<tr[^>]*>(.*?)</tr>", html, re.DOTALL | re.IGNORECASE)
    for block in tr_blocks:
        found_barcode = barcode_pattern.search(block)
        if not found_barcode:
            continue
        barcode = found_barcode.group()

        # 提取馆藏部门
        dept_match = dept_pattern.search(block)
        dept = dept_match.group(1).strip() if dept_match else ""
        dept = re.sub(r"<[^>]+>", "", dept).strip()

        # 提取状态
        status = ""
        for kw in status_keywords:
            if kw in block:
                status = kw
                break

        if dept or status:
            results.append({
                "department": dept,
                "barcode": barcode,
                "status": status,
            })

    return results


def send_bark_notification(title, body):
    """通过Bark发送通知"""
    encoded_title = urllib.parse.quote(title, safe="")
    encoded_body = urllib.parse.quote(body, safe="")
    url = "{}/{}/{}".format(BARK_URL, encoded_title, encoded_body)
    try:
        req = urllib.request.Request(url)
        with urllib.request.urlopen(req, timeout=TIMEOUT) as resp:
            log.info("Bark通知发送成功，响应码: %d", resp.status)
            return True
    except Exception as e:
        log.error("Bark通知发送失败: %s", e)
        return False


def check_once():
    """执行一次检查，返回西土城在架可借的记录列表"""
    log.info("开始检查馆藏状态...")
    try:
        html = fetch_page(BOOK_URL)
    except Exception as e:
        log.error("获取页面失败: %s", e)
        return []

    all_items = parse_collection(html)
    log.info("共解析到 %d 条馆藏记录", len(all_items))
    for item in all_items:
        log.info("  %s | %s | %s", item["department"], item["barcode"], item["status"])

    # 筛选西土城 + 在架可借
    available = [
        item for item in all_items
        if "西土城" in item.get("department", "") and "在架可借" in item.get("status", "")
    ]
    # available = [
    #     {"department": "西土城", "status": "在架可借", "barcode": "mock123"}
    # ]
    return available


def main():
    """主循环"""
    run_once = "--once" in sys.argv

    while True:
        now = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        available = check_once()

        if available:
            log.info("发现 %d 本西土城在架可借！", len(available))
            details = "\n".join(
                "{}  条码:{}".format(r["department"], r["barcode"])
                for r in available
            )
            title = "北邮图书馆-马斯克传有书可借"
            body = "西土城校区发现{}本在架可借\n{}\n检查时间:{}".format(
                len(available), details, now
            )
            send_bark_notification(title, body)
            break
        else:
            log.info("暂无西土城在架可借，%d分钟后再查...", CHECK_INTERVAL // 60)

        if run_once:
            break

        time.sleep(CHECK_INTERVAL)


if __name__ == "__main__":
    main()
