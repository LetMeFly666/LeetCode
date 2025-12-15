'''
Author: LetMeFly
Date: 2025-11-25 11:19:58
LastEditors: LetMeFly.xyz
LastEditTime: 2025-12-15 13:20:34
'''
"""

我想自动化LeetCode的那个项目（https://github.com/LetMeFly666/LeetCode），当前最想自动化的是每日一题。
关于每日一题我有一个标记是从2025.4.7日开始的，这之后每天都会创建一个issue，标题格式为“[newSolution]Who can add 1 more problem of LeetCode 2873”或者部分不带“[newSolution]”的“Who can add 1 more problem of LeetCode 2873”。我想实现以下内容：
- 将不带“[newSolution]”的相关issue加上这个标题（注意是4.7日及之后，注意是Who can add 1 more problem of xx的issue），希望可以先列举并等我确认后再执行rename
- 统一重命名之后，将4.7日之后到今天为止的所有相关issue添加到https://github.com/users/LetMeFly666/projects/5/views/1
- 之后每天我都想创建一个issue，内容为今天的每日一题（这可能涉及到爬虫，如果你没有较好的或现有的爬虫方案，可以先留下接口等我后续分析和实现）
- 之后所有[newSolution]Who can add 1 more problem of LeetCode xxxx 为标题的issue全部自动添加到projects/5/views/1中
- 如果有pr关联了这个issue，则标记状态为In Progress； 如果有issue带有“solving”标签，则标记状态为In Progress（去掉solving标签也要相应地标记回TODO状态

额外信息：
- 整个内容可以以任何自动化方式实现，例如归一化issueName也可以单独写一个脚本在本地运行一次
- 4.7日之前也有类似issue，暂且不在本次统计范围内
- 你可以使用任何方法实现，包括但不限于一个或多个workflow，或部分本地执行的gh命令或python脚本，但本地执行的只能今天执行一次，创建好后要依靠自动执行
- 所有符合条件的issue都带有“题解”label



为什么是
SET_FINISH_DATE = 
mutation($projectId:ID!, $itemId:ID!, $fieldId:ID!, $date:String!) {
  updateProjectV2ItemFieldValue(
    input:{
      projectId:$projectId,
      itemId:$itemId,
      fieldId:$fieldId,
      value:{ date:$date }
    }
  ) {
    __typename
  }
}
和
if issue["state"] == "closed" and issue["closed_at"]:
    finish_date = iso_to_date(issue["closed_at"])

    gh_graphql(SET_FINISH_DATE, {
        "projectId": project_id,
        "itemId": item_id,
        "fieldId": finish_date_field["id"],
        "date": finish_date,
    })

    print(f"  - FinishDate set to {finish_date}")
而不是：
SET_FINISH_DATE = 
mutation($projectId:ID!, $itemId:ID!, $fieldId:ID!, $date:String!, $finishDate:String!) {
  updateProjectV2ItemFieldValue(
    input:{
      projectId:$projectId,
      itemId:$itemId,
      fieldId:$fieldId,
      value:{ date:$date, finishDate:$finishDate }
    }
  ) {
    __typename
  }
}
和
if issue["state"] == "closed" and issue["closed_at"]:
    finish_date = iso_to_date(issue["closed_at"])

    gh_graphql(SET_FINISH_DATE, {
        "projectId": project_id,
        "itemId": item_id,
        "fieldId": finish_date_field["id"],
        "date": today.strftime("%Y-%m-%d"),,
        "finishDate": finish_date,
    })

    print(f"  - FinishDate set to {finish_date}")



"""