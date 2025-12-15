'''
Author: LetMeFly
Date: 2025-12-15 23:40:17
LastEditors: LetMeFly.xyz
LastEditTime: 2025-12-15 23:41:30
'''
"""
获取某月的每日一题情况
"""
import requests

def get1month(year: int, month: int) -> dict:
    url = "https://leetcode.cn/graphql/"

    payload = {
        "operationName": "dailyQuestionRecords",
        "query": """
        query dailyQuestionRecords($year: Int!, $month: Int!) {
        dailyQuestionRecords(year: $year, month: $month) {
            date
            userStatus
            question {
            questionFrontendId
            title
            titleSlug
            translatedTitle
            }
        }
        }
        """,
        "variables": {
            "year": year,
            "month": month
        }
    }

    headers = {
        "Content-Type": "application/json",
        # 如果需要登录态（比如 userStatus），一般要带 cookie
        # "Cookie": "LEETCODE_SESSION=xxx; csrftoken=xxx",
        # "x-csrftoken": "xxx",
    }

    resp = requests.post(url, json=payload, headers=headers)
    resp.raise_for_status()

    data = resp.json()
    return data


data = get1month(2025, 12)
print(data)