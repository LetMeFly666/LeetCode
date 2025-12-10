'''
Author: LetMeFly + ChatGPT
Date: 2025-12-09 22:35:47
LastEditors: LetMeFly.xyz
LastEditTime: 2025-12-10 18:55:02
'''
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
一次性执行：
 1. 查找 2025-04-07 之后、label 包含 “题解”、title 包含 “Who can add 1 more problem of LeetCode” 的 issue
 2. 对缺少 “[newSolution]” 的自动 rename
 3. 将所有这些 issue 加入 Project #5，并设 Status = TODO
"""

import subprocess, json, sys, re

OWNER = "LetMeFly666"
REPO = "LeetCode"
PROJECT_NUMBER = 5
SINCE = "2025-04-07T00:00:00Z"

daily_order = [
    "[newSolution]Who can add 1 more problem of LeetCode 2873 #882",
    "[newSolution]Who can add 1 more problem of LeetCode 2874 #883",
    "[newSolution]Who can add 1 more problem of LeetCode 368(Codes) #881",
    "[newSolution]Who can add 1 more problem of LeetCode 416 #880",
    "Who can add 1 more problem of LeetCode 2999 #869",
    "Who can add 1 more problem of LeetCode 3272 #867",
    "Who can add 1 more problem of LeetCode 1922 #871",
    "Who can add 1 more problem of LeetCode 1534 #875",
    "[newSolution]Who can add 1 more problem of LeetCode 2179 #879",
    "Who can add 1 more problem of LeetCode 2537 #877",
    "[newSolution]Who can add 1 more problem of LeetCode 2176 #884",
    "[newSolution]Who can add 1 more problem of LeetCode 2364 #886",
    "Who can add 1 more problem of LeetCode 2563 #888",
    "[newSolution]Who can add 1 more problem of LeetCode 781 #891",
    "[newSolution]Who can add 1 more problem of LeetCode 2145 #893",
    "[newSolution]Who can add 1 more problem of LeetCode 2338 #894",
    "Who can add 1 more problem of LeetCode 1399 #895",
    "[newSolution]Who can add 1 more problem of LeetCode 2799 #896",
    "[newSolution]Who can add 1 more problem of LeetCode 2845 #898",
    "[newSolution]Who can add 1 more problem of LeetCode 2444 #899",
    "[newSolution]Who can add 1 more problem of LeetCode 3392 #900",
    "[newSolution]Who can add 1 more problem of LeetCode 2302 #901",
    "[newSolution]Who can add 1 more problem of LeetCode 2962 #902",
    "[newSolution]Who can add 1 more problem of LeetCode 1295 #906",
    "[newSolution]Who can add 1 more problem of LeetCode 2071 #908",
    "[newSolution]Who can add 1 more problem of LeetCode 838 #909",
    "[newSolution]Who can add 1 more problem of LeetCode 1007 #910",
    "[newSolution]Who can add 1 more problem of LeetCode 1128 #911",
    "[newSolution]Who can add 1 more problem of LeetCode 790 #917",
    "[newSolution]Who can add 1 more problem of LeetCode 1920 #919",
    "[newSolution]Who can add 1 more problem of LeetCode 3341 #921",
    "[newSolution]Who can add 1 more problem of LeetCode 3342 #924",
    "[newSolution]Who can add 1 more problem of LeetCode 3343 #925",
    "[newSolution]Who can add 1 more problem of LeetCode 2918 #927",
    "[newSolution]Who can add 1 more problem of LeetCode 1550 #929",
    "[newSolution]Who can add 1 more problem of LeetCode 2094 #931",
    "[newSolution]Who can add 1 more problem of LeetCode 3335 #933",
    "[newSolution]Who can add 1 more problem of LeetCode 3337 #935",
    "[newSolution]Who can add 1 more problem of LeetCode 2900 #937",
    "[newSolution]Who can add 1 more problem of LeetCode 2901 #939",
    "[newSolution]Who can add 1 more problem of LeetCode 75 #940",
    "[newSolution]Who can add 1 more problem of LeetCode 1931 #941",
    "[newSolution]Who can add 1 more problem of LeetCode 3024 #942",
    "[newSolution]Who can add 1 more problem of LeetCode 3355 #945",
    "[newSolution]Who can add 1 more problem of LeetCode 3356 #946",
    "[newSolution]Who can add 1 more problem of LeetCode 3362 #949",
    "[newSolution]Who can add 1 more problem of LeetCode 3068 #951",
    "[newSolution]Who can add 1 more problem of LeetCode 2942 #952",
    "[newSolution]Who can add 1 more problem of LeetCode 2131 #954",
    "[newSolution]Who can add 1 more problem of LeetCode 1857 #956",
    "[newSolution]Who can add 1 more problem of LeetCode 2894 #958",
    "[newSolution]Who can add 1 more problem of LeetCode 3372 #961",
    "[newSolution]Who can add 1 more problem of LeetCode 3373 #963",
    "[newSolution]Who can add 1 more problem of LeetCode 2359 #965",
    "[newSolution]Who can add 1 more problem of LeetCode 909 #966",
    "[newSolution]Who can add 1 more problem of LeetCode 2929 #967",
    "[newSolution]Who can add 1 more problem of LeetCode 135 #968",
    "[newSolution]Who can add 1 more problem of LeetCode 1298 #969",
    "[newSolution]Who can add 1 more problem of LeetCode 3403 #970",
    "[newSolution]Who can add 1 more problem of LeetCode 1061 #971",
    "[newSolution]Who can add 1 more problem of LeetCode 2434 #972",
    "[newSolution]Who can add 1 more problem of LeetCode 3170 #977",
    "[newSolution]Who can add 1 more problem of LeetCode 386 #974",
    "[newSolution]Who can add 1 more problem of LeetCode 440 #976",
    "[newSolution]Who can add 1 more problem of LeetCode 3442 #978",
    "[newSolution]Who can add 1 more problem of LeetCode 3445 #980",
    "[newSolution]Who can add 1 more problem of LeetCode 3423 #981",
    "[newSolution]Who can add 1 more problem of LeetCode 2616 #983",
    "[newSolution]Who can add 1 more problem of LeetCode 2566 #984",
    "[newSolution]Who can add 1 more problem of LeetCode 1432 #985",
    "[newSolution]Who can add 1 more problem of LeetCode 2016 #986",
    "[newSolution]Who can add 1 more problem of LeetCode 3405 #987",
    "[newSolution]Who can add 1 more problem of LeetCode 2966 #988",
    "[newSolution]Who can add 1 more problem of LeetCode 2294 #989",
    "[newSolution]Who can add 1 more problem of LeetCode 3443 #990",
    "[newSolution]Who can add 1 more problem of LeetCode 3085 #992",
    "[newSolution]Who can add 1 more problem of LeetCode 2138 #995",
    "[newSolution]Who can add 1 more problem of LeetCode 2081 #996",
    "[newSolution]Who can add 1 more problem of LeetCode 2200 #997",
    "[newSolution]Who can add 1 more problem of LeetCode 2040 #998",
    "[newSolution]Who can add 1 more problem of LeetCode 2311 #1000",
    "[newSolution]Who can add 1 more problem of LeetCode 2014 #1002",
    "[newSolution]Who can add 1 more problem of LeetCode 2099 #1004",
    "[newSolution]Who can add 1 more problem of LeetCode 1498 #1005",
    "[newSolution]Who can add 1 more problem of LeetCode 594 #1006",
    "[newSolution]Who can add 1 more problem of LeetCode 3330 #1007",
    "[newSolution]Who can add 1 more problem of LeetCode 3333 #1008",
    "[newSolution]Who can add 1 more problem of LeetCode 3304 #1013",
    "[newSolution]Who can add 1 more problem of LeetCode 3307 #1014",
    "[newSolution]Who can add 1 more problem of LeetCode 1394 #1015",
    "[newSolution]Who can add 1 more problem of LeetCode 1865 #1016",
    "[newSolution]Who can add 1 more problem of LeetCode 1353 #1017",
    "[newSolution]Who can add 1 more problem of LeetCode 1751 #1018",
    "[newSolution]Who can add 1 more problem of LeetCode 3439 #1024",
    "[newSolution]Who can add 1 more problem of LeetCode 3440 #1020",
    "[newSolution]Who can add 1 more problem of LeetCode 3169 #1011",
    "[newSolution]Who can add 1 more problem of LeetCode 1900 #1021",
    "[newSolution]Who can add 1 more problem of LeetCode 2410 #1022",
    "[newSolution]Who can add 1 more problem of LeetCode 1290 #1026",
    "[newSolution]Who can add 1 more problem of LeetCode 3136 #1028",
    "[newSolution]Who can add 1 more problem of LeetCode 3201 #1030",
    "[newSolution]Who can add 1 more problem of LeetCode 3202 #1035",
    "[newSolution]Who can add 1 more problem of LeetCode 2163 #1034",
    "[newSolution]Who can add 1 more problem of LeetCode 1233 #1036",
    "[newSolution]Who can add 1 more problem of LeetCode 1948 #1037",
    "[newSolution]Who can add 1 more problem of LeetCode 1957 #1039",
    "[newSolution]Who can add 1 more problem of LeetCode 1695 #1041",
    "[newSolution]Who can add 1 more problem of LeetCode 1717 #1043",
    "[newSolution]Who can add 1 more problem of LeetCode 2322 #1044",
    "[newSolution]Who can add 1 more problem of LeetCode 3487 #1045",
    "[newSolution]Who can add 1 more problem of LeetCode 3480 #1046",
    "[newSolution]Who can add 1 more problem of LeetCode 2210 #1047",
    "[newSolution]Who can add 1 more problem of LeetCode 2044 #1048",
    "[newSolution]Who can add 1 more problem of LeetCode 2411 #1052",
    "[newSolution]Who can add 1 more problem of LeetCode 2419 #1055",
    "[newSolution]Who can add 1 more problem of LeetCode 2683 #1056",
    "[newSolution]Who can add 1 more problem of LeetCode 118 (by hand without using NewSolution.py） #1057",
    "[newSolution]Who can add 1 more problem of LeetCode 2561 #1059",
    "[newSolution]Who can add 1 more problem of LeetCode 2106 #1061",
    "[newSolution]Who can add 1 more problem of LeetCode 904 #1062",
    "[newSolution]Who can add 1 more problem of LeetCode 3477 #1063",
    "[newSolution]Who can add 1 more problem of LeetCode 3479 #1064",
    "[newSolution]Who can add 1 more problem of LeetCode 3363 #1065",
    "[newSolution]Who can add 1 more problem of LeetCode 808 #1067",
    "[newSolution]Who can add 1 more problem of LeetCode 231 #1068",
    "[newSolution]Who can add 1 more problem of LeetCode 869 #1070",
    "[newSolution]Who can add 1 more problem of LeetCode 2438 #1072",
    "[newSolution]Who can add 1 more problem of LeetCode 2787 #1074",
    "[newSolution]Who can add 1 more problem of LeetCode 326 #1078",
    "[newSolution]Who can add 1 more problem of LeetCode 1780 #1080",
    "Who can add 1 more problem of 706 #342",
    "[newSolution]Who can add 1 more problem of LeetCode 1323 #1084",
    "Who can add 1 more problem of LeetCode 2711 #837",
    "[newSolution]Who can add 1 more problem of LeetCode 679 #1088",
    "[newSolution]Who can add 1 more problem of LeetCode 2348 #1089",
    "[newSolution]Who can add 1 more problem of LeetCode 1277 #1090",
    "[newSolution]Who can add 1 more problem of LeetCode 1504 #1091",
    "[newSolution]Who can add 1 more problem of LeetCode 3195 #1092",
    "[newSolution]Who can add 1 more problem of LeetCode 3197 #1096",
    "[newSolution]Who can add 1 more problem of LeetCode 1493 #1097",
    "[newSolution]Who can add 1 more problem of LeetCode 498 #1094",
    "[newSolution]Who can add 1 more problem of LeetCode 3000 #1098",
    "[newSolution]Who can add 1 more problem of LeetCode 3459 #1100",
    "[newSolution]Who can add 1 more problem of LeetCode 3446 #1101",
    "[newSolution]Who can add 1 more problem of LeetCode 3021 #1102",
    "[newSolution]Who can add 1 more problem of LeetCode 36 #1104",
    "[newSolution]Who can add 1 more problem of LeetCode 37 #1105",
    "[newSolution]Who can add 1 more problem of LeetCode 1792 #1106",
    "[newSolution]Who can add 1 more problem of LeetCode 3025 #1108",
    "[newSolution]Who can add 1 more problem of LeetCode 3027 #1112",
    "[newSolution]Who can add 1 more problem of LeetCode 3516 #1110",
    "[newSolution]Who can add 1 more problem of LeetCode 2749 #1115",
    "[newSolution]Who can add 1 more problem of LeetCode 3495 #1117",
    "[newSolution]Who can add 1 more problem of LeetCode 1304 #1119",
    "[newSolution]Who can add 1 more problem of LeetCode 1317 + git amend批量修改email #1118",
    "[newSolution]Who can add 1 more problem of LeetCode 2327 #1121",
    "[newSolution]Who can add 1 more problem of LeetCode 1733 #1123",
    "[newSolution]Who can add 1 more problem of LeetCode 2785 #1124",
    "[newSolution]Who can add 1 more problem of LeetCode 3227 #1125",
    "[newSolution]Who can add 1 more problem of LeetCode 3541 + 题库更新 #1126",
    "[newSolution]Who can add 1 more problem of LeetCode 966+文章《记一次服务器迁移》 #1128",
    "[newSolution]Who can add 1 more problem of LeetCode 1935 #1130",
    "[newSolution]Who can add 1 more problem of LeetCode 2197 #1132",
    "[newSolution]Who can add 1 more problem of LeetCode 2349 #1133",
    "[newSolution]Who can add 1 more problem of LeetCode 3408 #1137",
    "[newSolution]Who can add 1 more problem of LeetCode 3484 #1138",
    "[newSolution]Who can add 1 more problem of LeetCode 3508 #1135",
    "[newSolution]Who can add 1 more problem of LeetCode 1912 #1139",
    "[newSolution]Who can add 1 more problem of LeetCode 3005 #1140",
    "[newSolution]Who can add 1 more problem of LeetCode 165 #1141",
    "[newSolution]Who can add 1 more problem of LeetCode 166 #1142",
    "[newSolution]Who can add 1 more problem of LeetCode 120 #1143",
    "[newSolution]Who can add 1 more problem of LeetCode 611 #1145",
    "[newSolution][newSolution+article]Who can add 1 more problem of LeetCode 812 + an article about MacOS Clang using bits/stdc++.h #1147",
    "[newSolution]Who can add 1 more problem of LeetCode 976 #1149",
    "[newSolution]Who can add 1 more problem of LeetCode 1039 #1151",
    "[newSolution]Who can add 1 more problem of LeetCode 2221 #1155",
    "[newSolution]Who can add 1 more problem of LeetCode 1518 #1156",
    "[newSolution]Who can add 1 more problem of LeetCode 3100 #1157",
    "[newSolution]Who can add 1 more problem of LeetCode 407 #1158",
    "[newSolution]Who can add 1 more problem of LeetCode 11 #1159",
    "[newSolution]Who can add 1 more problem of LeetCode 417 #1160",
    "[newSolution]Who can add 1 more problem of LeetCode 778 #1153",
    "[newSolution]Who can add 1 more problem of LeetCode 1488 #1162",
    "[newSolution]Who can add 1 more problem of LeetCode 2300 + 《日积月累——crontab mailto high cpu usage》 #1161",
    "[newSolution]Who can add 1 more problem of LeetCode 3494 #1164",
    "[newSolution]Who can add 1 more problem of LeetCode 3147 #1166",
    "[newSolution]Who can add 1 more problem of LeetCode 3186 #1167",
    "[newSolution]Who can add 1 more problem of LeetCode 3539 #1171",
    "[newSolution]Who can add 1 more problem of LeetCode 2273 #1172",
    "[newSolution]Who can add 1 more problem of LeetCode 3349 #1169",
    "[newSolution]Who can add 1 more problem of LeetCode 3350 #1173",
    "[newSolution]Who can add 1 more problem of LeetCode 2598 #1175",
    "[newSolution]Who can add 1 more problem of LeetCode 3003 #1180",
    "[newSolution]Who can add 1 more problem of LeetCode 3397 #1181",
    "[newSolution]Who can add 1 more problem of LeetCode 1625 #1182",
    "[newSolution]Who can add 1 more problem of LeetCode 2011 #1177",
    "[newSolution]Who can add 1 more problem of LeetCode 3346 #1179",
    "[newSolution]Who can add 1 more problem of LeetCode 3347 #1183",
    "[newSolution]Who can add 1 more problem of LeetCode 3461 #1184",
    "[newSolution]Who can add 1 more problem of LeetCode 2048 #1195",
    "[newSolution]Who can add 1 more problem of LeetCode 1716 #1196",
    "[newSolution]Who can add 1 more problem of LeetCode 2043 #1197",
    "[newSolution]Who can add 1 more problem of LeetCode 2125 #1198",
    "[newSolution]Who can add 1 more problem of LeetCode 3354 #1199",
    "[newSolution]Who can add 1 more problem of LeetCode 3370 #1200",
    "[newSolution]Who can add 1 more problem of LeetCode 1526 #1201",
    "[newSolution]Who can add 1 more problem of LeetCode 3289 #1191",
    "[newSolution]Who can add 1 more problem of LeetCode 3217 #1193",
    "[newSolution]Who can add 1 more problem of LeetCode 3217 #1205",
    "[newSolution]Who can add 1 more problem of LeetCode 2257 #1208",
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
    1925
]

def gh_api(path, method="GET", data=None):
    cmd = ["gh", "api", path]
    if method != "GET":
        cmd = ["gh", "api", "--method", method, path]
    if data is not None:
        cmd.extend(["-f", json.dumps(data)])
    out = subprocess.check_output(cmd, text=True, encoding="utf-8", errors="replace")
    return json.loads(out)

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
    return issues

def leetcode_number(title):
    m = re.search(r'LeetCode\s*(\d+)', title)
    return int(m.group(1)) if m else float('inf')


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
    order_map = {leetcode_number(title): idx for idx, title in enumerate(daily_order)}
    # TODO: HERE  not right  不是把daily_order排序

    # 排序 targets
    targets.sort(key=lambda t: order_map.get(leetcode_number(t["title"]), float('inf')))

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

    status_field = None
    for f in proj_node["fields"]["nodes"]:
        if f["name"].lower() == "status":
            status_field = f
            break
    if status_field is None:
        print("Error: 未找到 Status 字段 in project. 请确认 Project #5 存在 Status 字段。")
        sys.exit(1)

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
    GET_ISSUE_NODE = """
    query($owner:String!,$repo:String!,$num:Int!){
      repository(owner:$owner,name:$repo){
        issue(number:$num){ id }
      }
    }
    """

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

        # set status to TODO
        print("  - Setting Status = TODO")
        gh_graphql(SET_STATUS, {
            "projectId": project_id,
            "itemId": item_id,
            "fieldId": status_field["id"],
            "optionId": todo_opt,
        })

        print("  ✔ Issue processed.\n")

    print("All done.")

if __name__ == "__main__":
    main()
