---
title: 722.删除注释
date: 2023-08-03 08:15:53
tags: [题解, LeetCode, 中等, 数组, 字符串, 大模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】722.删除注释

力扣题目链接：[https://leetcode.cn/problems/remove-comments/](https://leetcode.cn/problems/remove-comments/)

<p>给一个 C++ 程序，删除程序中的注释。这个程序<code>source</code>是一个数组，其中<code>source[i]</code>表示第&nbsp;<code>i</code>&nbsp;行源码。&nbsp;这表示每行源码由<font color="#c7254e"><font face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="font-size:12.6px"><span style="background-color:#f9f2f4"> <code>'\n'&nbsp;</code></span></span></font></font>分隔。</p>

<p>在 C++ 中有两种注释风格，行内注释和块注释。</p>

<ul>
	<li>字符串<code>//</code> 表示行注释，表示<code>//</code>和其右侧的其余字符应该被忽略。</li>
	<li>字符串<code>/*</code> 表示一个块注释，它表示直到下一个（非重叠）出现的<code>*/</code>之间的所有字符都应该被忽略。（阅读顺序为从左到右）非重叠是指，字符串<code>/*/</code>并没有结束块注释，因为注释的结尾与开头相重叠。</li>
</ul>

<p>第一个有效注释优先于其他注释。</p>

<ul>
	<li>如果字符串<code>//</code>出现在块注释中会被忽略。</li>
	<li>同样，如果字符串<code>/*</code>出现在行或块注释中也会被忽略。</li>
</ul>

<p>如果一行在删除注释之后变为空字符串，那么<strong>不要</strong>输出该行。即，答案列表中的每个字符串都是非空的。</p>

<p>样例中<strong>没有</strong>控制字符，单引号或双引号字符。</p>

<ul>
	<li>比如，<code>source = "string s = "/* Not a comment. */";"</code> 不会出现在测试样例里。</li>
</ul>

<p>此外，没有其他内容（如定义或宏）会干扰注释。</p>

<p>我们保证每一个块注释最终都会被闭合， 所以在行或块注释之外的<code>/*</code>总是开始新的注释。</p>

<p>最后，隐式换行符<strong>可以</strong>通过块注释删除。 有关详细信息，请参阅下面的示例。</p>

<p>从源代码中删除注释后，需要以相同的格式返回源代码。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre>
<strong>输入:</strong> source = ["/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"]
<strong>输出:</strong> ["int main()","{ ","  ","int a, b, c;","a = b + c;","}"]
<strong>解释:</strong> 示例代码可以编排成这样:
/*Test program */
int main()
{ 
  // variable declaration 
int a, b, c;
/* This is a test
   multiline  
   comment for 
   testing */
a = b + c;
}
第 1 行和第 6-9 行的字符串 /* 表示块注释。第 4 行的字符串 // 表示行注释。
编排后: 
int main()
{ 
  
int a, b, c;
a = b + c;
}</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> source = ["a/*comment", "line", "more_comment*/b"]
<strong>输出:</strong> ["ab"]
<strong>解释:</strong> 原始的 source 字符串是 "a/*comment<strong>\n</strong>line<strong>\n</strong>more_comment*/b", 其中我们用粗体显示了换行符。删除注释后，隐含的换行符被删除，留下字符串 "ab" 用换行符分隔成数组时就是 ["ab"].
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= source.length &lt;= 100</code></li>
	<li><code>0 &lt;= source[i].length &lt;= 80</code></li>
	<li><code>source[i]</code>&nbsp;由可打印的 <strong>ASCII</strong> 字符组成。</li>
	<li>每个块注释都会被闭合。</li>
	<li>给定的源码中不会有单引号、双引号或其他控制字符。</li>
</ul>
<span style="display:block"><span style="height:0px"><span style="position:absolute"><span style="top:0px"><span style="left:-9999px"><span style="opacity:0"><span style="overflow:hidden">&nbsp;</span></span></span></span></span></span>​​​​​​</span>

    
## 方法一：状态记录

使用几个变量来记录当前状态：

+ ```findingEnd = false```，用来记录是否处于块注释中。
+ ```thisLine = ''```，用来记录这一行去掉注释后的结果。
+ ```ans = []```，用来存放答案。

遍历每一行：
   + 遍历这一行的每个元素：
      + 如果处于块注释中 且 遇到了```*/```：更新findingEnd = false
      + 否则：
         + 如果遇到了```/*```：更新findingEnd = true
         + 如果遇到了```//```：跳过处理这一行
         + 否则：当前元素添加到thisLine中
   + 这一行处理结束后，若不是处于块注释中，则：
      + ```ans.append(thisLine)```
      + ```thisLine.clear()```

最终返回ans即可

+ 时间复杂度$O(\sum c)$，其中$\sum c$是代码中字符个数。
+ 空间复杂度$O(\sum c)$，空间复杂度主要来自$thisLine$，极端情况下每一行仅注释掉一个换行符，则thisLine的长度将达到代码长度的级别。

TODO: 本题的另外两种解法：

1. [状态机（类似LL1）](https://leetcode.cn/problems/remove-comments/solutions/2365861/shan-chu-zhu-shi-by-leetcode-solution-lb9x/comments/2082824)
2. 正则表达式：[Python](https://leetcode.cn/problems/remove-comments/solutions/2365861/shan-chu-zhu-shi-by-leetcode-solution-lb9x/comments/2082754)、[C++](https://leetcode.cn/problems/remove-comments/solutions/2365861/shan-chu-zhu-shi-by-leetcode-solution-lb9x/comments/2082880)

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        bool findingEnd = false;
        string thisLine;
        for (string& s : source) {
            for (int i = 0; i < s.size(); i++) {
                if (findingEnd) {
                    if (s[i] == '*' && i + 1 < s.size() && s[i + 1] == '/') {
                        findingEnd = false;
                        i++;
                    }
                }
                else {
                    if (s[i] == '/' && i + 1 < s.size() && s[i + 1] == '*') {
                        findingEnd = true;
                        i++;
                    }
                    else if (s[i] == '/' && i + 1 < s.size() && s[i + 1] == '/') {
                        break;
                    }
                    else {
                        thisLine += s[i];
                    }
                }
            }
            if (!findingEnd) {
                if (thisLine.size()) {
                    ans.push_back(thisLine);
                    thisLine.clear();
                }
            }
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def removeComments(self, source: List[str]) -> List[str]:
        ans = []
        findingEnd = False
        thisLine = ''
        for s in source:
            i = 0
            while i < len(s):
                if findingEnd:
                    if s[i] == '*' and i + 1 < len(s) and s[i + 1] == '/':
                        findingEnd = False
                        i += 1
                else:
                    if s[i] == '/' and i + 1 < len(s) and s[i + 1] == '*':
                        findingEnd = True
                        i += 1
                    elif s[i] == '/' and i + 1 < len(s) and s[i + 1] == '/':
                        break
                    else:
                        thisLine += s[i]
                i += 1
            if not findingEnd and len(thisLine):
                ans.append(thisLine)
                thisLine = ''
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/08/03/LeetCode%200722.%E5%88%A0%E9%99%A4%E6%B3%A8%E9%87%8A/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132075300](https://letmefly.blog.csdn.net/article/details/132075300)
