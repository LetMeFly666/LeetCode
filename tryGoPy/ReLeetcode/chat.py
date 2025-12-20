'''
Author: LetMeFly
Date: 2025-11-25 11:19:58
LastEditors: LetMeFly.xyz
LastEditTime: 2025-12-20 22:24:50
'''
"""

我想自动化LeetCode的那个项目（https://github.com/LetMeFly666/LeetCode），当前最想自动化的是每日一题。有一个视图，https://github.com/users/LetMeFly666/projects/5/views/1
关于每日一题我有一个标记是从2025.4.1日开始的，这之后每天都会创建一个issue，标题格式为“[newSolution]Who can add 1 more problem of LeetCode 2873”。我想实现以下内容：
- 每天我都想创建一个issue，内容为今天的每日一题（这个后续再实现）
- 之后所有新创建的或新重命名[newSolution]Who can add 1 more problem of LeetCode xxxx 为标题的issue全部自动添加到projects/5/views/1中
- 如果有pr关联了这个issue，则标记状态为In Progress； 如果有issue带有“solving”标签，则标记状态为In Progress（去掉solving标签也要相应地标记回TODO状态





太酷啦！终于成功添加到project中了~
但是设置status为todo的时候报错了
Set Status = TODO
gh: Field 'updateProjectV2ItemFieldValue' is missing required arguments: input
Field 'updateProjectV2ItemFieldValue' doesn't accept argument 'itemId'
Field 'updateProjectV2ItemFieldValue' doesn't accept argument 'fieldId'
Field 'updateProjectV2ItemFieldValue' doesn't accept argument 'value'
Variable $item is declared by anonymous mutation but not used
Variable $field is declared by anonymous mutation but not used
Variable $value is declared by anonymous mutation but not used
{"errors":[{"path":["mutation","updateProjectV2ItemFieldValue"],"extensions":{"code":"missingRequiredArguments","className":"Field","name":"updateProjectV2ItemFieldValue","arguments":"input"},"locations":[{"line":3,"column":5}],"message":"Field 'updateProjectV2ItemFieldValue' is missing required arguments: input"},{"path":["mutation","updateProjectV2ItemFieldValue","itemId"],"extensions":{"code":"argumentNotAccepted","name":"updateProjectV2ItemFieldValue","typeName":"Field","argumentName":"itemId"},"locations":[{"line":4,"column":7}],"message":"Field 'updateProjectV2ItemFieldValue' doesn't accept argument 'itemId'"},{"path":["mutation","updateProjectV2ItemFieldValue","fieldId"],"extensions":{"code":"argumentNotAccepted","name":"updateProjectV2ItemFieldValue","typeName":"Field","argumentName":"fieldId"},"locations":[{"line":5,"column":7}],"message":"Field 'updateProjectV2ItemFieldValue' doesn't accept argument 'fieldId'"},{"path":["mutation","updateProjectV2ItemFieldValue","value"],"extensions":{"code":"argumentNotAccepted","name":"updateProjectV2ItemFieldValue","typeName":"Field","argumentName":"value"},"locations":[{"line":6,"column":7}],"message":"Field 'updateProjectV2ItemFieldValue' doesn't accept argument 'value'"},{"path":["mutation"],"extensions":{"code":"variableNotUsed","variableName":"item"},"locations":[{"line":2,"column":3}],"message":"Variable $item is declared by anonymous mutation but not used"},{"path":["mutation"],"extensions":{"code":"variableNotUsed","variableName":"field"},"locations":[{"line":2,"column":3}],"message":"Variable $field is declared by anonymous mutation but not used"},{"path":["mutation"],"extensions":{"code":"variableNotUsed","variableName":"value"},"locations":[{"line":2,"column":3}],"message":"Variable $value is declared by anonymous mutation but not used"}]}
Error: Process completed with exit code 1.
不过设置status为todo的问题我在project的简单workflows中设置了，不需要在.github/workflows中设置为todo和done了
其他几个workflows也不要修改为todo和done了，但是这些功能还要实现

- 如果有pr关联了这个issue，则标记状态为In Progress； 如果有issue带有“solving”标签，则标记状态为In Progress（去掉solving标签也要相应地标记回TODO状态
- issue开启日期和完成日期要在project中更新
- 每日一题issue的自动生成，时间前面说过了（UTC+8的0点）
  - 获取地址为https://leetcode.cn/graphql/  POST {"query":"\n    query dailyQuestionRecords($year: Int!, $month: Int!) {\n  dailyQuestionRecords(year: $year, month: $month) {\n    date\n    userStatus\n    question {\n      questionFrontendId\n      title\n      titleSlug\n      translatedTitle\n    }\n  }\n}\n    ","variables":{"year":2025,"month":11},"operationName":"dailyQuestionRecords"}
  - 响应如下：{"data":{"dailyQuestionRecords":[{"date":"2025-11-30","userStatus":"FINISH","question":{"questionFrontendId":"1590","title":"Make Sum Divisible by P","titleSlug":"make-sum-divisible-by-p","translatedTitle":"\u4f7f\u6570\u7ec4\u548c\u80fd\u88ab P \u6574\u9664"}},{"date":"2025-11-29","userStatus":"FINISH","question":{"questionFrontendId":"3512","title":"Minimum Operations to Make Array Sum Divisible by K","titleSlug":"minimum-operations-to-make-array-sum-divisible-by-k","translatedTitle":"\u4f7f\u6570\u7ec4\u548c\u80fd\u88ab K \u6574\u9664\u7684\u6700\u5c11\u64cd\u4f5c\u6b21\u6570"}}]}}
  - 你应该生成的issue标题为：[newSolution]Who can add 1 more problem of LeetCode 1590，body为：By Github Actions | [1590.使数组和能被 P 整除](https://leetcode.cn/problems/make-sum-divisible-by-p/) | 2025-11-30，label为“题解”，Assignees为LetMeFly666
  - 这个要支持workflow_dispatch

请你仔细深度思考，不要着急，给我生成所有所需workflows代码吧






1. add.yml没有在project中设置Date字段
1. 不要使用硬编码，继续使用ONE_PROBLEM_ONE_DAY_PROJECT_ID
1. issue中的label叫solving，project中的status才叫in progress
1. Project 里的 workflow只能在issue加入时设置为todo，issue完成时设置为done，有issue链接时设置为in progress，但是project中的workflow无法依据issue中是否存在solving标签修改状态为in progress或者视情况而定的todo/done



你理解错了，还需更改如下：
1. add.yml不要设置state，但是要通过gh命令设置project中的Date字段
2. label.yml需要依据issue中是否存在solving标签修改project中的状态为in progress或者视情况而定的todo/done
3. 合并add.yml和date.yml的opened状态，add.yml负责所有add时应该进行的操作
4. 没有专门的date.yml，而是要把date.yml中closed状态拆分为close.yml，负责issue关闭时的操作。记得只有被关闭issue在这个project中才操作project防止报错




好的，你的理解时正确的，请详细总结一个prompt，以便以后我要和ChatGPT对话时，可以直接粘贴你总结的prompt一次性告诉他所有的背景。




好的，请精简下，并给我可直接复制的markdown源码





我使用如下命令
gh api graphql -f query='
>> query($field:ID!) {
>>   node(id:$field) {
>>     ... on ProjectV2SingleSelectField {
>>       options { id name }
>>     }
>>   }
>> }' -F field="$STATUS_FIELD_ID"
可以得到如下结果：
{                                            ;C
  "data": {
    "node": {
      "options": [
        {
          "id": "f75ad846",
          "name": "Todo"
        },
        {
          "id": "47fc9ee4",
          "name": "In Progress"
        },
        {
          "id": "98236657",
          "name": "Done"
        }
      ]
    }
  }
}
我有一个变量status是Todo、In Progress、Done三种值中的一种，
请你帮我写一个简单的脚本将对应的id复制给option_id变量



很棒！我这个option_id有可能是纯数字，有可能是字符串。
字符串时，gh 应该这样写：
gh api graphql -f query='
  mutation($project:ID!, $item:ID!, $field:ID!, $option:String!) {
      updateProjectV2ItemFieldValue(input:{
      projectId:$project
      itemId:$item
      fieldId:$field
      value:{ singleSelectOptionId:$option }
      }) {
      projectV2Item { id }
      }
  }
  ' \
  -F project="$PROJECT_ID" \
  -F item="$item_id" \
  -F field="$STATUS_FIELD_ID" \
  -F option="$option_id"
  纯数字时，$option:String!应该改为$option:ID!
  怎样实现比较优雅

  

powershell设置临时变量名

$PROJECT_ID="PVT_kwHOA2Wuss4BKNdu"
$item_id="PVTI_lAHOA2Wuss4BKNduzgi1LOI"
$STATUS_FIELD_ID="PVTSSF_lAHOA2Wuss4BKNduzg6JSHw"
$option_id="98236657"


PROJECT_ID="PVT_kwHOA2Wuss4BKNdu"
item_id="PVTI_lAHOA2Wuss4BKNduzgi1LOI"
STATUS_FIELD_ID="PVTSSF_lAHOA2Wuss4BKNduzg6JSHw"
option_id="98236657"  # Done
option_id="f75ad846"  # TODO
option_id="47fc9ee4"  # In Progress


好了，现在我有option_id了，并且环境变量中有$PROJECT_ID、$item_id、$STATUS_FIELD_ID、$option_id，如何将这个item设置为对应option？


你给的脚本在以下两个状态没有问题可以正常运行
option_id="f75ad846"  # TODO
option_id="47fc9ee4"  # In Progress
但是在以下状态会报错
option_id="98236657"  # Done
{
  "errors": [
    {
      "extensions": {
        "value": 98236657,
        "problems": [
          {
            "path": [],
            "explanation": "Could not coerce value 98236657 to String"
          }
        ]
      },
      "locations": [
        {
          "line": 2,
          "column": 47
        }
      ],
      "message": "Variable $option of type String! was provided invalid value"
    }
  ]
}
gh: Variable $option of type String! was provided invalid value




gh api graphql -f query='
mutation($project:ID!, $item:ID!, $field:ID!, $option:String!) {
  updateProjectV2ItemFieldValue(input:{
    projectId: $project
    itemId: $item
    fieldId: $field
    value: { singleSelectOptionId: $option }
  }) {
    projectV2Item { id }
  }
}' -F project="$PROJECT_ID" -F item="$item_id" -F field="$STATUS_FIELD_ID" -F option="98236657"


不行啊，不论是option='"98236657"'还是option="\"98236657\""，都会报错"updateProjectV2ItemFieldValue": null
如果mutation中$option:String!并且-F option="98236657"，则会报错"explanation": "Could not coerce value 98236657 to String"
如果mutation中$option:ID!并且-F option="98236657"，则会报错Type mismatch on variable $option and argument singleSelectOptionId (ID! / String)



我有几个环境变量：
PROJECT_ID="PVT_kwHOA2Wuss4BKNdu"
item_id="PVTI_lAHOA2Wuss4BKNduzgi1LOI"
STATUS_FIELD_ID="PVTSSF_lAHOA2Wuss4BKNduzg6JSHw"
option_id="98236657"  # Done
我希望使用github gh将对应的field设置为Done



gh api \
  --method PATCH \
  -H "Accept: application/vnd.github+json" \
  -H "X-GitHub-Api-Version: 2022-11-28" \
  "https://api.github.com/projects/v2/items/$item_id/fields/$STATUS_FIELD_ID" \
  -f value="{\"single_select_option_id\": \"$option_id\"}"



gh api graphql -f query='
  mutation UpdateProjectItemStatus($projectId: ID!, $itemId: ID!, $fieldId: ID!, $optionId: String!) {
    updateProjectV2ItemFieldValue(
      input: {
        projectId: $projectId
        itemId: $itemId
        fieldId: $fieldId
        value: { singleSelectOptionId: $optionId }
      }
    ) {
      projectV2Item {
        id
        fieldValues(first: 10) {
          nodes {
            ... on ProjectV2ItemFieldSingleSelectValue {
              id
              name
              optionId
            }
          }
        }
      }
    }
  }
' -f projectId="$PROJECT_ID" -f itemId="$item_id" -f fieldId="$STATUS_FIELD_ID" -f optionId="$option_id"
"""

