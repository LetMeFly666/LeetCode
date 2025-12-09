'''
Author: LetMeFly
Date: 2025-11-25 11:19:58
LastEditors: LetMeFly.xyz
LastEditTime: 2025-12-09 23:17:49
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



是的，回答你的问题：
①是
②提供一个现成的 LeetCode 每日一题爬取方案
③已创建
④是，或者“ close: #1204”也算
⑤全部

额外补充：
- 每日自动创建每日一题是UTC+8的0:10
- issue的body内容为：“By xxx | 3583.统计特殊三元组”，其中xxx为创建脚本名称和链接，链接要链接到对应的hash地址；其中“3583.统计特殊三元组”也是个链接，要链接到这道题的地址





现在我使用的是Windows，能否将今天运行的那些修改为python脚本呢



请使用gh吧，我Windows系统上也有gh并且gh鉴权过了，不想再申请GITHUB_TOKEN了


我希望你给我返回的是今天的预处理脚本SOS，不是每天运行的脚本
这样，现在你先给我返回今天要运行的脚本，包括rename issue和添加到project





很棒，只是顺序不太正确，毕竟我创建issue时候的顺序就不太正确，这不能怪你。
我的每日一题正确顺序如下，请你在targets中按照此顺序排序，若不在此顺序列表中，则排序到最后。
返回需要修改的代码。
此外，我刚刚新增了字段Date，类型为日期，请从“ 2873 #882”开始依次填入日期字段






这样匹配有很大的匹配失败风险，以LeetCode后面的1208为依据排序




不是这个意思嗷，
daily_order = [
    "[newSolution]Who can add 1 more problem of LeetCode 2873 #882",
    "[newSolution]Who can add 1 more problem of LeetCode 2874 #883",
    ...
]

以daily_order中的顺序为依据将targets排序，但targets和daily_order中元素相同的依据为：LeetCode后的数字相同

"""