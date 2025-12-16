'''
Author: LetMeFly
Date: 2025-11-25 11:19:58
LastEditors: LetMeFly.xyz
LastEditTime: 2025-12-16 10:55:05
'''
"""

我想自动化LeetCode的那个项目（https://github.com/LetMeFly666/LeetCode），当前最想自动化的是每日一题。有一个视图，https://github.com/users/LetMeFly666/projects/5/views/1
关于每日一题我有一个标记是从2025.4.1日开始的，这之后每天都会创建一个issue，标题格式为“[newSolution]Who can add 1 more problem of LeetCode 2873”。我想实现以下内容：
- 每天我都想创建一个issue，内容为今天的每日一题（这个后续再实现）
- 之后所有新创建的或新重命名[newSolution]Who can add 1 more problem of LeetCode xxxx 为标题的issue全部自动添加到projects/5/views/1中
- 如果有pr关联了这个issue，则标记状态为In Progress； 如果有issue带有“solving”标签，则标记状态为In Progress（去掉solving标签也要相应地标记回TODO状态

额外信息：
- 你可以使用任何方法实现，包括但不限于一个或多个workflow，或部分本地执行的gh命令或python脚本，创建好后要依靠自动执行
- 视图还包含两个字段：Date、FinishDate（issue关闭日期，如有）



1. 我这个view是公开的，需要隐藏字段ID吗，如果不隐藏会不会有一些风险
2. 我只能将yml放在.github/workflows下吗，可不可以放到.github/workflows/1problem1day文件夹下



我明白了你的良苦用心，https://github.com/LetMeFly666/LeetCode/settings/secrets/actions发现有Environment secrets和Repository secrets，旁边甚至还有variables，他们有什么区别，应该选择哪个？


但是我UI里有这个字段（并且有3种选项） 我不想重新创建一次，如何获取STATUS_FIELD_ID
Status 字段 ID
"""