'''
Author: LetMeFly
Date: 2022-06-02 14:14:26
LastEditors: LetMeFly
LastEditTime: 2023-06-02 21:07:42
'''
# WorkDir: BASE DIR
# CMD: python AllProblems/_获取首页题目_LeetCode.py
import requests
import datetime
# import json
from bs4 import BeautifulSoup
import time
import os

headers = {"cookie": "LEETCODE_SESSION=你的session"}
url = 'https://leetcode.cn/graphql/'


def GraphQL(query: str) -> requests.Response:
    return requests.post(url, headers=headers, json=query)


def html2markdown(html: str) -> str:
    soup = BeautifulSoup(html, 'lxml')
    #TODO: html2markdown
    return html
    


def getAllProblemLinks() -> list:
    # data = {
    #     "variables": {
    #         "categorySlug": "",
    #         "skip": 200,
    #         "limit": 100,
    #         "filters": {}
    #     },
    #     "query": """
    #     query problemsetQuestionList($categorySlug: String, $limit: Int, $skip: Int, $filters: QuestionListFilterInput) {
    #         problemsetQuestionList(
    #             categorySlug: $categorySlug
    #             limit: $limit
    #             skip: $skip
    #             filters: $filters
    #         )
    #         {
    #             hasMore
    #             total
    #             questions {
    #                 acRate
    #                 difficulty
    #                 freqBar
    #                 frontendQuestionId
    #                 isFavor
    #                 paidOnly
    #                 solutionNum
    #                 status
    #                 title
    #                 titleCn
    #                 titleSlug
    #                 topicTags {
    #                     name
    #                     nameTranslated
    #                     id
    #                     slug
    #                 }
    #                 extra {
    #                     hasVideoSolution
    #                     topCompanyTags {
    #                         imgUrl
    #                         slug
    #                         numSubscribed
    #                     }
    #                 }
    #             }
    #         }
    #     }
    #     """,
    # }

    query = {
        "variables": {
            "categorySlug": "",
            "skip": 0,
            "limit": 100,
            "filters": {}
        },
        "query": """
        query problemsetQuestionList($categorySlug: String, $limit: Int, $skip: Int, $filters: QuestionListFilterInput) {
            problemsetQuestionList(
                categorySlug: $categorySlug
                limit: $limit
                skip: $skip
                filters: $filters
            )
            {
                hasMore
                total
                questions {
                    titleSlug
                }
            }
        }
        """,
    }

    results = []
    # begin = 2200  # Change here for begin
    begin = 0
    while True:
        print(begin)
        query["variables"]["skip"] = begin
        begin += 100
        response = GraphQL(query=query)
        # print(json.dumps(response.json(), indent=4))
        for _ in response.json()["data"]["problemsetQuestionList"]["questions"]:
            # results.append("https://leetcode.cn/problems/" + _["titleSlug"])
            results.append(_["titleSlug"])
        if not response.json()["data"]["problemsetQuestionList"]["hasMore"]:
            break
    return results


"""
通过题目titleSlug获取题目内容

@Parameters:
    titleSlug - str:
        一个题目的url为：https://leetcode.cn/problems/{titleSlug}/
        例如：
            “1. 两数之和” 的
                url 为 https://leetcode.cn/problems/two-sum/
                titleSlug 为 two-sum
"""
def getOneProblemData(titleSlug: str) -> str:
    query = {
        "variables": {
            "titleSlug": titleSlug
        },
        "query": """
        query questionData($titleSlug: String!) {
            question(titleSlug: $titleSlug) {
                questionId
                questionFrontendId
                categoryTitle
                boundTopicId
                title
                titleSlug
                content
                translatedTitle
                translatedContent
                isPaidOnly
                difficulty
                likes
                dislikes
                isLiked
                similarQuestions
                contributors {
                    username
                    profileUrl
                    avatarUrl
                    __typename
                }
                langToValidPlayground
                topicTags {
                    name
                    slug
                    translatedName
                    __typename
                }
                companyTagStats
                codeSnippets {
                    lang
                    langSlug
                    code
                    __typename
                }
                stats
                hints
                solution {
                    id
                    canSeeDetail
                    __typename
                }
                status
                sampleTestCase
                metaData
                judgerAvailable
                judgeType
                mysqlSchemas
                enableRunCode
                envInfo
                book {
                    id
                    bookName
                    pressName
                    source
                    shortDescription
                    fullDescription
                    bookImgUrl
                    pressImgUrl
                    productUrl
                    __typename
                }
                isSubscribed
                isDailyQuestion
                dailyRecordStatus
                editorType
                ugcQuestionId
                style
                exampleTestcases
                jsonExampleTestcases
                __typename
            }
        }
        """
    }
    response = GraphQL(query=query)

    question = response.json()["data"]["question"]
    title = question["questionFrontendId"] + "." + question["translatedTitle"]
    difficulty = {
        "Easy": "简单",
        "Medium": "中等",
        "Hard": "困难",
    }.get(question["difficulty"])
    tags = ""
    for _ in question["topicTags"]:
        if tags:
            tags += ", "
        tags += _["translatedName"]
    content = html2markdown(question["translatedContent"])

    # print(content)

    markdown = f"""---
title: {title}
date: {datetime.datetime.strftime(datetime.datetime.now(), "%Y-%m-%d %H-%M-%S")}
tags: [题解, LeetCode, {difficulty}, {tags}]
---

# 【LetMeFly】{title}

力扣题目链接：[https://leetcode.cn/problems/{titleSlug}/](https://leetcode.cn/problems/{titleSlug}/)

{content}

    """
    # print(markdown)

    return {"markdown": markdown, "title": title}



allProblems = getAllProblemLinks()
failedProblems = []

for titleSlug in allProblems:
    try:
        data = getOneProblemData(titleSlug)
        markdown = data["markdown"]
        title = data["title"]
        if os.path.exists(f"AllProblems/{title}.md"):
            with open(f"AllProblems/{title}.md", "r", encoding="utf-8") as f:
                originalData = f.read()
                originalDataDate = originalData.split('\n')[2].split('date: ')[-1]
                markdownSplited = markdown.split('\n')
                markdownSplited[2] = f'date: {originalDataDate}'
                markdown = '\n'.join(markdownSplited)
        with open(f"AllProblems/{title}.md", "w", encoding="utf-8") as f:
            f.write(markdown)
        print(title)
        # time.sleep(1)
    except BaseException as e:
        print(e)
        failedProblems.append(titleSlug)

print(failedProblems)
