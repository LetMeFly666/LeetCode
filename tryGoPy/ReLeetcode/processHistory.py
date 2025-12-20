'''
Author: LetMeFly + ChatGPT
Date: 2025-12-09 22:35:47
LastEditors: LetMeFly.xyz
LastEditTime: 2025-12-20 22:24:44
'''
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
一次性执行：
 1. 查找 2025-04-01 之后、label 包含 “题解”、title 包含 “Who can add 1 more problem of LeetCode” 的 issue
 2. 对缺少 “[newSolution]” 的自动 rename
 3. 将所有这些 issue 加入 Project #5，并设 Date = 对应日期、FinishDate = 完成日期
"""

"""
projectId: PVT_kwHOA2Wuss4BKNdu
{"data":{"node":{"fields":{"nodes":[{"id":"PVTF_lAHOA2Wuss4BKNduzg6JSHo","name":"Title","dataType":"TITLE"},{"id":"PVTF_lAHOA2Wuss4BKNduzg6JSHs","name":"Assignees","dataType":"ASSIGNEES"},{"id":"PVTSSF_lAHOA2Wuss4BKNduzg6JSHw","name":"Status","dataType":"SINGLE_SELECT"},{"id":"PVTF_lAHOA2Wuss4BKNduzg6JSH0","name":"Labels","dataType":"LABELS"},{"id":"PVTF_lAHOA2Wuss4BKNduzg6JSH4","name":"Linked pull requests","dataType":"LINKED_PULL_REQUESTS"},{"id":"PVTF_lAHOA2Wuss4BKNduzg6JSH8","name":"Milestone","dataType":"MILESTONE"},{"id":"PVTF_lAHOA2Wuss4BKNduzg6JSIA","name":"Repository","dataType":"REPOSITORY"},{"id":"PVTF_lAHOA2Wuss4BKNduzg6JSIE","name":"Reviewers","dataType":"REVIEWERS"},{"id":"PVTF_lAHOA2Wuss4BKNduzg6JSII","name":"Parent issue","dataType":"PARENT_ISSUE"},{"id":"PVTF_lAHOA2Wuss4BKNduzg6JnU0","name":"Date","dataType":"DATE"},{"id":"PVTF_lAHOA2Wuss4BKNduzg6be2I","name":"FinishDate","dataType":"DATE"},{"id":"PVTF_lAHOA2Wuss4BKNduzg6ddUs","name":"备注","dataType":"TEXT"},{"id":"PVTF_lAHOA2Wuss4BKNduzg6JSIM","name":"Sub-issues progress","dataType":"SUB_ISSUES_PROGRESS"}]}}}}
{"data":{"node":{"options":[{"id":"f75ad846","name":"Todo"},{"id":"47fc9ee4","name":"In Progress"},{"id":"98236657","name":"Done"}]}}}

gh api graphql -f query='
  query($project:ID!) {
    node(id:$project) {
      ... on ProjectV2 {
        fields(first:50) {
          nodes {
            ... on ProjectV2FieldCommon {
              id
              name
              dataType
            }
          }
        }
      }
    }
  }
' -f project=PVT_kwHOA2Wuss4BKNdu
"""

import subprocess, json, sys, re, datetime, time, functools
from typing import List, Callable, TypeVar


OWNER = "LetMeFly666"
REPO = "LeetCode"
PROJECT_NUMBER = 5
SINCE = "2025-04-01T00:00:00Z"

T = TypeVar("T")

daily_order_pr_num_half = [
    854,
    882,
    883,
    1227,
    856,
    881,
    880,
    858,
    860,
    869,
    862,
    867,
    871,
    875,
    879,
    877,
    884,
    886,
    888,
    891,
    893,
    894,
    895,
    896,
    898,
    899,
    900,
    901,
    902,
    906,
    908,
    909,
    910,
    911,
    917,
    919,
    921,
    924,
    925,
    927,
    929,
    931,
    933,
    935,
    937,
    939,
    940,
    941,
    942,
    945,
    946,
    949,
    951,
    952,
    954,
    956,
    958,
    961,
    963,
    965,
    966,
    967,
    968,
    969,
    970,
    971,
    972,
    977,
    974,
    976,
    978,
    980,
    981,
    983,
    984,
    985,
    986,
    987,
    988,
    989,
    990,
    992,
    993,
    996,
    997,
    998,
    1000,
    1002,
    1003,
    1005,
    1006,
    1007,
    1008,
    1013,
    1014,
    1015,
    1016,
    1017,
    1018,
    1024,
    1020,
    1011,
    1021,
    1022,
    1026,
    1028,
    1030,
    1035,
    1034,
    1036,
    1037,
    1039,
    1041,
    1043,
    1044,
    1045,
    1046,
    1047,
    1048,
    1052,
    1055,
    1056,
    1057,
    1059,
    1061,
    1062,
    1063,
    1064,
    1065,
    1067,
    1068,
    1070,
    1072,
    1074,
    1078,
    1080,
    1082,
    1084,
    1086,
    1088,
    1089,
    1090,
    1091,
    1092,
    1096,
    1097,
    1094,
    1098,
    1100,
    1101,
    1102,
    1104,
    1105,
    1106,
    1108,
    1112,
    1110,
    1115,
    1117,
    1119,
    1118,
    1121,
    1123,
    1124,
    1125,
    1126,
    1128,
    1130,
    1132,
    1133,
    1137,
    1138,
    1135,
    1139,
    1140,
    1141,
    1142,
    1143,
    1145,
    1147,
    1149,
    1151,
    1155,
    1156,
    1157,
    1158,
    1159,
    1160,
    1153,
    1162,
    1161,
    1164,
    1166,
    1167,
    1171,
    1172,
    1169,
    1173,
    1175,
    1180,
    1181,
    1182,
    1177,
    1179,
    1183,
    1184,
    1195,
    1196,
    1197,
    1198,
    1199,
    1200,
    1201,
    1191,
    1193,
    1205,
    1208
]

daily_order_problem_num = [
    2873,
    2874,
    368,
    416,
    2999,
    3272,
    1922,
    1534,
    2179,
    2537,
    2176,
    2364,
    2563,
    781,
    2145,
    2338,
    1399,
    2799,
    2845,
    2444,
    3392,
    2302,
    2962,
    1295,
    2071,
    838,
    1007,
    1128,
    790,
    1920,
    3341,
    3342,
    3343,
    2918,
    1550,
    2094,
    3335,
    3337,
    2900,
    2901,
    75,
    1931,
    3024,
    3355,
    3356,
    3362,
    3068,
    2942,
    2131,
    1857,
    2894,
    3372,
    3373,
    2359,
    909,
    2929,
    135,
    1298,
    3403,
    1061,
    2434,
    3170,
    386,
    440,
    3442,
    3445,
    3423,
    2616,
    2566,
    1432,
    2016,
    3405,
    2966,
    2294,
    3443,
    3085,
    2138,
    2081,
    2200,
    2040,
    2311,
    2014,
    2099,
    1498,
    594,
    3330,
    3333,
    3304,
    3307,
    1394,
    1865,
    1353,
    1751,
    3439,
    3440,
    3169,
    1900,
    2410,
    1290,
    3136,
    3201,
    3202,
    2163,
    1233,
    1948,
    1957,
    1695,
    1717,
    2322,
    3487,
    3480,
    2210,
    2044,
    2411,
    2419,
    2683,
    118,
    2561,
    2106,
    904,
    3477,
    3479,
    3363,
    808,
    231,
    869,
    2438,
    2787,
    326,
    1780,
    342,
    1323,
    2711,
    679,
    2348,
    1277,
    1504,
    3195,
    3197,
    1493,
    498,
    3000,
    3459,
    3446,
    3021,
    36,
    37,
    1792,
    3025,
    3027,
    3516,
    2749,
    3495,
    1304,
    1317,
    2327,
    1733,
    2785,
    3227,
    3541,
    966,
    1935,
    2197,
    2349,
    3408,
    3484,
    3508,
    1912,
    3005,
    165,
    166,
    120,
    611,
    812,
    976,
    1039,
    2221,
    1518,
    3100,
    407,
    11,
    417,
    778,
    1488,
    2300,
    3494,
    3147,
    3186,
    3539,
    2273,
    3349,
    3350,
    2598,
    3003,
    3397,
    1625,
    2011,
    3346,
    3347,
    3461,
    2048,
    1716,
    2043,
    2125,
    3354,
    3370,
    1526,
    3289,
    3217,
    3217,
    2257,
    1578,
    3318,
    3321,
    3607,
    2528,
    1611,
    2169,
    3542,
    474,
    2654,
    3228,
    2536,
    3234,
    1513,
    1437,
    717,
    2154,
    757,
    1930,
    3190,
    1262,
    1018,
    1015,
    2435,
    3381,
    2872,
    3512,
    1590,
    2141,
    3623,
    3625,
    2211,
    3432,
    3578,
    1523,
    1925,
    3583,
    3577,
    3531,
    3433,
    3606,
    2147,
    2110
]

"""
当被修饰函数抛出异常时，休眠3s、5s之后不断休眠5s重复执行，直到执行成功。
并输出休眠时间以及重复次数
"""
def retry_forever_with_sleep() -> Callable[[Callable[..., T]], Callable[..., T]]:
    def decorator(func: Callable[..., T]) -> Callable[..., T]:
        @functools.wraps(func)
        def wrapper(*args, **kwargs) -> T:
            retry_count = 0

            while True:
                try:
                    return func(*args, **kwargs)
                except Exception as e:
                    retry_count += 1

                    if retry_count == 1:
                        sleep_time = 3
                    else:
                        sleep_time = 5

                    print(
                        f"[retry #{retry_count}] "
                        f"error={e!r}, sleep {sleep_time}s..."
                    )
                    time.sleep(sleep_time)

        return wrapper
    return decorator

@retry_forever_with_sleep()
def gh_api(path, method="GET", data=None):
    cmd = ["gh", "api", path]
    if method != "GET":
        cmd = ["gh", "api", "--method", method, path]
    if data is not None:
        cmd.extend(["-f", json.dumps(data)])
    out = subprocess.check_output(cmd, text=True, encoding="utf-8", errors="replace")
    return json.loads(out)

@retry_forever_with_sleep()
def run_gh(cmd: list[str]) -> str:
    """
    运行 gh 命令并返回 UTF-8 文本。
    自动避免 Windows 的 gbk 解码错误。
    """
    result = subprocess.run(
        cmd,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        encoding="utf-8",
        errors="replace"   # 避免 UnicodeDecodeError
    )

    if result.returncode != 0:
        raise RuntimeError(f"GH command failed:\nCMD: {cmd}\nSTDERR:\n{result.stderr}")

    return json.loads(result.stdout)

def gh_graphql(query: str, variables: dict = None):
    """
    使用 gh api graphql
    query 使用 -f query=...
    variables 使用多个 -F varName=value
    """

    cmd = ["gh", "api", "graphql", "-f", f"query={query}"]

    if variables:
        for k, v in variables.items():
            cmd += ["-F", f"{k}={v}"]

    return run_gh(cmd)

def fetch_issues():
    # fetch all issues since date (state=all)
    issues = []
    page = 1
    while True:
        resp = gh_api(f"/repos/{OWNER}/{REPO}/issues?state=all&since={SINCE}&per_page=100&page={page}")
        print(f"page {page}: fetched {len(resp)} issues")
        if not resp:
            break
        issues.extend(resp)
        page += 1
    issues, beforeClean = [], issues
    SINCE_DT = datetime.datetime.fromisoformat(
        SINCE.replace("Z", "+00:00")
    )
    for issue in beforeClean:
        created_at = datetime.datetime.fromisoformat(
            issue["created_at"].replace("Z", "+00:00")
        )
        if created_at >= SINCE_DT:
            issues.append(issue)
    return issues

def leetcode_number(title):
    m = re.search(r'LeetCode\s*(\d+)', title)
    return int(m.group(1)) if m else float('inf')


def sort_issues(original: List[dict]):
    """One issue
    {'url': 'https://api.github.com/repos/LetMeFly666/LeetCode/issues/1212', 'repository_url': 'https://api.github.com/repos/LetMeFly666/LeetCode', 'labels_url': 'https://api.github.com/repos/LetMeFly666/LeetCode/issues/1212/labels{/name}', 'comments_url': 'https://api.github.com/repos/LetMeFly666/LeetCode/issues/1212/comments', 'events_url': 'https://api.github.com/repos/LetMeFly666/LeetCode/issues/1212/events', 'html_url': 'https://github.com/LetMeFly666/LeetCode/issues/1212', 'id': 3715465183, 'node_id': 'I_kwDOHVTHT87ddX_f', 'number': 1212, 'title': '[newSolution]Who can add 1 more problem of LeetCode 3577', 'user': {'login': 'LetMeFly666', 'id': 56995506, 'node_id': 'MDQ6VXNlcjU2OTk1NTA2', 'avatar_url': 'https://avatars.githubusercontent.com/u/56995506?v=4', 'gravatar_id': '', 'url': 'https://api.github.com/users/LetMeFly666', 'html_url': 'https://github.com/LetMeFly666', 'followers_url': 'https://api.github.com/users/LetMeFly666/followers', 'following_url': 'https://api.github.com/users/LetMeFly666/following{/other_user}', 'gists_url': 'https://api.github.com/users/LetMeFly666/gists{/gist_id}', 'starred_url': 'https://api.github.com/users/LetMeFly666/starred{/owner}{/repo}', 'subscriptions_url': 'https://api.github.com/users/LetMeFly666/subscriptions', 'organizations_url': 'https://api.github.com/users/LetMeFly666/orgs', 'repos_url': 'https://api.github.com/users/LetMeFly666/repos', 'events_url': 'https://api.github.com/users/LetMeFly666/events{/privacy}', 'received_events_url': 'https://api.github.com/users/LetMeFly666/received_events', 'type': 'User', 'user_view_type': 'public', 'site_admin': False}, 'labels': [{'id': 8108104477, 'node_id': 'LA_kwDOHVTHT88AAAAB40fbHQ', 'url': 'https://api.github.com/repos/LetMeFly666/LeetCode/labels/%E9%A2%98%E8%A7%A3', 'name': '题解', 'color': '5319e7', 'default': False, 'description': 'Solution'}, {'id': 8881275129, 'node_id': 'LA_kwDOHVTHT88AAAACEV2A-Q', 'url': 'https://api.github.com/repos/LetMeFly666/LeetCode/labels/solving', 'name': 'solving', 'color': '46fab6', 'default': False, 'description': '正在解决的问题'}], 'state': 'open', 'locked': False, 'assignee': {'login': 'LetMeFly666', 'id': 56995506, 'node_id': 'MDQ6VXNlcjU2OTk1NTA2', 'avatar_url': 'https://avatars.githubusercontent.com/u/56995506?v=4', 'gravatar_id': '', 'url': 'https://api.github.com/users/LetMeFly666', 'html_url': 'https://github.com/LetMeFly666', 'followers_url': 'https://api.github.com/users/LetMeFly666/followers', 'following_url': 'https://api.github.com/users/LetMeFly666/following{/other_user}', 'gists_url': 'https://api.github.com/users/LetMeFly666/gists{/gist_id}', 'starred_url': 'https://api.github.com/users/LetMeFly666/starred{/owner}{/repo}', 'subscriptions_url': 'https://api.github.com/users/LetMeFly666/subscriptions', 'organizations_url': 'https://api.github.com/users/LetMeFly666/orgs', 'repos_url': 'https://api.github.com/users/LetMeFly666/repos', 'events_url': 'https://api.github.com/users/LetMeFly666/events{/privacy}', 'received_events_url': 'https://api.github.com/users/LetMeFly666/received_events', 'type': 'User', 'user_view_type': 'public', 'site_admin': False}, 'assignees': [{'login': 'LetMeFly666', 'id': 56995506, 'node_id': 'MDQ6VXNlcjU2OTk1NTA2', 'avatar_url': 'https://avatars.githubusercontent.com/u/56995506?v=4', 'gravatar_id': '', 'url': 'https://api.github.com/users/LetMeFly666', 'html_url': 'https://github.com/LetMeFly666', 'followers_url': 'https://api.github.com/users/LetMeFly666/followers', 'following_url': 'https://api.github.com/users/LetMeFly666/following{/other_user}', 'gists_url': 'https://api.github.com/users/LetMeFly666/gists{/gist_id}', 'starred_url': 'https://api.github.com/users/LetMeFly666/starred{/owner}{/repo}', 'subscriptions_url': 'https://api.github.com/users/LetMeFly666/subscriptions', 'organizations_url': 'https://api.github.com/users/LetMeFly666/orgs', 'repos_url': 'https://api.github.com/users/LetMeFly666/repos', 'events_url': 'https://api.github.com/users/LetMeFly666/events{/privacy}', 'received_events_url': 'https://api.github.com/users/LetMeFly666/received_events', 'type': 'User', 'user_view_type': 'public', 'site_admin': False}], 'milestone': None, 'comments': 0, 'created_at': '2025-12-10T14:35:01Z', 'updated_at': '2025-12-10T14:35:01Z', 'closed_at': None, 'author_association': 'OWNER', 'active_lock_reason': None, 'sub_issues_summary': {'total': 0, 'completed': 0, 'percent_completed': 0}, 'issue_dependencies_summary': {'blocked_by': 0, 'total_blocked_by': 0, 'blocking': 0, 'total_blocking': 0}, 'body': 'By [newSolution.py](https://github.com/LetMeFly666/LeetCode/blob/4fe0f74b9bf64c3a40ee46a2952ed2f4a4b75342/newSolution.py) using GH on Windows | [3577.统计计算机解锁顺序排列数](https://leetcode.cn/problems/count-the-number-of-computer-unlocking-permutations) ', 'closed_by': None, 'reactions': {'url': 'https://api.github.com/repos/LetMeFly666/LeetCode/issues/1212/reactions', 'total_count': 0, '+1': 0, '-1': 0, 'laugh': 0, 'hooray': 0, 'confused': 0, 'heart': 0, 'rocket': 0, 'eyes': 0}, 'timeline_url': 'https://api.github.com/repos/LetMeFly666/LeetCode/issues/1212/timeline', 'performed_via_github_app': None, 'state_reason': None}
    """
    hasIssueNumList = []
    onlyHasProblemNumList = []
    notMatchedList = []
    for issue in original:
        issueNum = issue['url'].split('issues/')[1]
        match = re.compile(r'\[(\d{2,4})\.[A-Za-z\s]*[\u3400-\u4DBF\u4E00-\u9FFF\uF900-\uFAFF]+').search(issue['body'])
        if match:
            problemNum = match.group(1)
        else:
            match = re.compile(r'of LeetCode (\d{2,4})').search(issue['title'])
            if match:
                problemNum = match.group(1)
            else:
                print('*' * 50)
                print(f'#{issueNum}')
                print(issue['body'])
                print('*' * 50)
        # print(issueNum)
        # print(problemNum)
        try:
            index = daily_order_pr_num_half.index(int(issueNum))
            hasIssueNumList.append((index, issue))
            continue
        except ValueError:
            pass
        try:
            index = daily_order_problem_num.index(int(problemNum))
            onlyHasProblemNumList.append((index, issue))
            continue
        except ValueError:
            pass
        print(f'Warning: 无法为 issue #{issueNum} 找到排序依据！')
        notMatchedList.append(issue)
    print(f"{len(hasIssueNumList)} issues matched by issue number.")
    print(f"{len(onlyHasProblemNumList)} issues matched by problem number.")
    hasIssueNumList.sort(key=lambda x: x[0])
    onlyHasProblemNumList.sort(key=lambda x: x[0])
    notMatchedList.sort(key=lambda x: int(x['url'].split('issues/')[1]))
    return [item[1] for item in hasIssueNumList + onlyHasProblemNumList + [(float('inf'), it) for it in notMatchedList]]

def find_project_field(proj_node, *, name=None):
    for f in proj_node["fields"]["nodes"]:
        if not isinstance(f, dict):
            continue
        if name and f.get("name", "").lower() != name.lower():
            continue
        return f
    print(f"Error: 未找到 {name} 字段 in project. 请确认 Project #{PROJECT_NUMBER} 存在 {name} 字段。")
    sys.exit(1)

def iso_to_date(iso: str) -> str:
    # "2025-05-02T13:41:27Z" (UTC) -> UTC-8 date "YYYY-MM-DD"
    utc_dt = datetime.datetime.strptime(iso, "%Y-%m-%dT%H:%M:%SZ").replace(tzinfo=datetime.timezone.utc)
    utc_minus_8 = utc_dt.astimezone(datetime.timezone(datetime.timedelta(hours=-8)))
    return utc_minus_8.strftime("%Y-%m-%d")


def main():
    issues = fetch_issues()
    print(f"Fetched {len(issues)} issues since {SINCE}")

    # filter
    targets = []
    for it in issues:
        if "pull_request" in it:
            continue
        labels = {lbl["name"] for lbl in it.get("labels", [])}
        if "题解" not in labels:
            continue
        title = it.get("title", "")
        if "Who can add 1 more problem of LeetCode" not in title:
            continue
        targets.append(it)

    print(f"Found {len(targets)} matching issues (题解 + title match)")
    # for target in targets:
    #     print(target.get('title'), target.get('created_at'))
    if not targets:
        print("No issues to process. Exiting.")
        return
    # 构建 daily_order 的编号顺序映射
    targets = sort_issues(targets)
    print("排序完成")

    # --------------------------- 开始添加issue到project中 ---------------------------

    # Get ProjectV2 info
    q = """
    query($owner:String!, $num:Int!) {
        user(login:$owner) {
            projectV2(number:$num) {
                id
                fields(first:20) {
                    nodes {
                        __typename
                        ... on ProjectV2FieldCommon {
                            id
                            name
                        }
                        ... on ProjectV2SingleSelectField {
                            options {
                                id
                                name
                            }
                        }
                    }
                }
            }
        }
    }
    """
    proj = gh_graphql(q, {"owner": OWNER, "num": PROJECT_NUMBER})
    proj_node = proj["data"]["user"]["projectV2"]
    project_id = proj_node["id"]

    status_field = find_project_field(proj_node, name="Status")
    date_field = find_project_field(proj_node, name="Date")
    finish_date_field = find_project_field(proj_node, name="FinishDate")

    todo_opt = None
    for o in status_field.get("options", []):
        if o["name"].lower() == "todo":
            todo_opt = o["id"]
            break
    if not todo_opt:
        print("Error: 未找到 TODO option in Status field.")
        sys.exit(1)

    print(f"Project ID: {project_id}, Status field ID: {status_field['id']}, TODO option ID: {todo_opt}")

    # GraphQL mutations
    ADD_ITEM = """
    mutation($projectId:ID!, $contentId:ID!){
      addProjectV2ItemById(input:{projectId:$projectId, contentId:$contentId}) {
        item { id }
      }
    }"""
    SET_STATUS = """
    mutation($projectId:ID!, $itemId:ID!, $fieldId:ID!, $optionId:String!){
        updateProjectV2ItemFieldValue(input:{
            projectId:$projectId,
            itemId:$itemId,
            fieldId:$fieldId,
            value:{singleSelectOptionId:$optionId}
        }) {
            clientMutationId
        }
    }
    """
    SET_DATE = """
    mutation($projectId: ID!, $itemId: ID!, $fieldId: ID!, $date: Date!) {
        updateProjectV2ItemFieldValue(
            input: {
                projectId: $projectId
                itemId: $itemId
                fieldId: $fieldId
                value: { date: $date }
            }
        ) {
            projectV2Item {
                id
            }
        }
    }
    """
    GET_ISSUE_NODE = """
    query($owner:String!,$repo:String!,$num:Int!){
      repository(owner:$owner,name:$repo){
        issue(number:$num){ id }
      }
    }
    """
    today = datetime.datetime(year=2025, month=4, day=1)
    for it in targets:
        num = it["number"]
        title = it["title"]
        print(f"Processing issue #{num}: \"{title}\"")

        # rename if needed
        if not title.startswith("[newSolution]"):
            new_title = "[newSolution]" + title
            print(f"  - Renaming to: {new_title}")
            subprocess.check_call(["gh", "issue", "edit", str(num), "--title", new_title, "--repo", f"{OWNER}/{REPO}"])
        else:
            new_title = title
            print("  - Already has [newSolution] prefix.")

        # get issue node id
        node_resp = gh_graphql(GET_ISSUE_NODE, {"owner": OWNER, "repo": REPO, "num": num})
        node_id = node_resp["data"]["repository"]["issue"]["id"]

        # add to project
        print("  - Adding to Project ...")
        add_resp = gh_graphql(ADD_ITEM, {"projectId": project_id, "contentId": node_id})
        item_id = add_resp["data"]["addProjectV2ItemById"]["item"]["id"]

        print(f"  - Setting Date = {today.strftime('%Y-%m-%d')}")
        gh_graphql(SET_DATE, {
            "projectId": project_id,
            "itemId": item_id,
            "fieldId": date_field["id"],
            "date": today.strftime("%Y-%m-%d"),
        })
        today = today + datetime.timedelta(days=1)

        if it["state"] == "closed" and it["closed_at"]:
            finish_date = iso_to_date(it["closed_at"])
            print(f"  - Setting FinishDate = {finish_date}")
            gh_graphql(SET_DATE, {
                "projectId": project_id,
                "itemId": item_id,
                "fieldId": finish_date_field["id"],
                "date": finish_date,
            })
        
        print("  ✔ Issue processed.\n")

    print("All done.")

if __name__ == "__main__":
    main()
