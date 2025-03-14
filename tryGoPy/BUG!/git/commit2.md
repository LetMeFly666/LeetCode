<!--
 * @Author: LetMeFly
 * @Date: 2025-03-14 10:32:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-14 10:35:53
-->
和commit.md类似

在VsCode的powershell终端执行了命令：

```powershell
git cm "feat: `newSolution.py`commit记录prNum的预测尽量正确 (#811)
>> 
>> 测试方式：newSolutions.py -> 手动创建新issue -> 写题解并执行脚本后续
>> 
>> 暂未运行完整`newSolution.py`流程进行测试"
```

其中`git cm`是`git commit -s -m`的alias。

结果git log的时候：

```
commit 1651a2b2733f99566db6a5c86f25f500fb777144 (HEAD -> master, origin/master)
Author: LetMeFly666 <814114971@qq.com>
Date:   Fri Mar 14 10:31:15 2025 +0800

    feat:
    ewSolution.pycommit记录prNum的预测尽量正确 (#811)

    测试方式：newSolutions.py -> 手动创建新issue -> 写题解并执行脚本后续

    暂未运行完整
    ewSolution.py流程进行测试

    Signed-off-by: LetMeFly666 <814114971@qq.com>
```

不过这似乎不是一个bug，因为powershell的<code>`n</code>似乎本来就表示“换行符LF”
