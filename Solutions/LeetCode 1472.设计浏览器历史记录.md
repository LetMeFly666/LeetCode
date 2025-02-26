---
title: 1472.设计浏览器历史记录：一个数组完成模拟，单次操作均O(1)
date: 2025-02-26 13:50:40
tags: [题解, LeetCode, 中等, 栈, 设计, 数组, 链表, 数据流, 双向链表]
---

# 【LetMeFly】1472.设计浏览器历史记录：一个数组完成模拟，单次操作均O(1)

力扣题目链接：[https://leetcode.cn/problems/design-browser-history/](https://leetcode.cn/problems/design-browser-history/)

<p>你有一个只支持单个标签页的 <strong>浏览器</strong>&nbsp;，最开始你浏览的网页是&nbsp;<code>homepage</code>&nbsp;，你可以访问其他的网站&nbsp;<code>url</code>&nbsp;，也可以在浏览历史中后退&nbsp;<code>steps</code>&nbsp;步或前进&nbsp;<code>steps</code>&nbsp;步。</p>

<p>请你实现&nbsp;<code>BrowserHistory</code> 类：</p>

<ul>
	<li><code>BrowserHistory(string homepage)</code>&nbsp;，用&nbsp;<code>homepage</code>&nbsp;初始化浏览器类。</li>
	<li><code>void visit(string url)</code>&nbsp;从当前页跳转访问 <code>url</code> 对应的页面&nbsp;&nbsp;。执行此操作会把浏览历史前进的记录全部删除。</li>
	<li><code>string back(int steps)</code>&nbsp;在浏览历史中后退&nbsp;<code>steps</code>&nbsp;步。如果你只能在浏览历史中后退至多&nbsp;<code>x</code> 步且&nbsp;<code>steps &gt; x</code>&nbsp;，那么你只后退&nbsp;<code>x</code>&nbsp;步。请返回后退 <strong>至多</strong> <code>steps</code>&nbsp;步以后的&nbsp;<code>url</code>&nbsp;。</li>
	<li><code>string forward(int steps)</code>&nbsp;在浏览历史中前进&nbsp;<code>steps</code>&nbsp;步。如果你只能在浏览历史中前进至多&nbsp;<code>x</code>&nbsp;步且&nbsp;<code>steps &gt; x</code>&nbsp;，那么你只前进 <code>x</code>&nbsp;步。请返回前进&nbsp;<strong>至多</strong>&nbsp;<code>steps</code>步以后的 <code>url</code>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>
[&quot;BrowserHistory&quot;,&quot;visit&quot;,&quot;visit&quot;,&quot;visit&quot;,&quot;back&quot;,&quot;back&quot;,&quot;forward&quot;,&quot;visit&quot;,&quot;forward&quot;,&quot;back&quot;,&quot;back&quot;]
[[&quot;leetcode.com&quot;],[&quot;google.com&quot;],[&quot;facebook.com&quot;],[&quot;youtube.com&quot;],[1],[1],[1],[&quot;linkedin.com&quot;],[2],[2],[7]]
<strong>输出：</strong>
[null,null,null,null,&quot;facebook.com&quot;,&quot;google.com&quot;,&quot;facebook.com&quot;,null,&quot;linkedin.com&quot;,&quot;google.com&quot;,&quot;leetcode.com&quot;]

<strong>解释：</strong>
BrowserHistory browserHistory = new BrowserHistory(&quot;leetcode.com&quot;);
browserHistory.visit(&quot;google.com&quot;);       // 你原本在浏览 &quot;leetcode.com&quot; 。访问 &quot;google.com&quot;
browserHistory.visit(&quot;facebook.com&quot;);     // 你原本在浏览 &quot;google.com&quot; 。访问 &quot;facebook.com&quot;
browserHistory.visit(&quot;youtube.com&quot;);      // 你原本在浏览 &quot;facebook.com&quot; 。访问 &quot;youtube.com&quot;
browserHistory.back(1);                   // 你原本在浏览 &quot;youtube.com&quot; ，后退到 &quot;facebook.com&quot; 并返回 &quot;facebook.com&quot;
browserHistory.back(1);                   // 你原本在浏览 &quot;facebook.com&quot; ，后退到 &quot;google.com&quot; 并返回 &quot;google.com&quot;
browserHistory.forward(1);                // 你原本在浏览 &quot;google.com&quot; ，前进到 &quot;facebook.com&quot; 并返回 &quot;facebook.com&quot;
browserHistory.visit(&quot;linkedin.com&quot;);     // 你原本在浏览 &quot;facebook.com&quot; 。 访问 &quot;linkedin.com&quot;
browserHistory.forward(2);                // 你原本在浏览 &quot;linkedin.com&quot; ，你无法前进任何步数。
browserHistory.back(2);                   // 你原本在浏览 &quot;linkedin.com&quot; ，后退两步依次先到 &quot;facebook.com&quot; ，然后到 &quot;google.com&quot; ，并返回 &quot;google.com&quot;
browserHistory.back(7);                   // 你原本在浏览 &quot;google.com&quot;， 你只能后退一步到 &quot;leetcode.com&quot; ，并返回 &quot;leetcode.com&quot;
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= homepage.length &lt;= 20</code></li>
	<li><code>1 &lt;= url.length &lt;= 20</code></li>
	<li><code>1 &lt;= steps &lt;= 100</code></li>
	<li><code>homepage</code> 和&nbsp;<code>url</code>&nbsp;都只包含&nbsp;&#39;.&#39; 或者小写英文字母。</li>
	<li>最多调用&nbsp;<code>5000</code>&nbsp;次&nbsp;<code>visit</code>，&nbsp;<code>back</code>&nbsp;和&nbsp;<code>forward</code>&nbsp;函数。</li>
</ul>


    
## 解题方法：数组模拟

使用一个大小可变的数组模拟浏览器(标签页)历史记录。初始值只有一个元素`homepage`。

使用`now`变量记录当前页面的下标，使用`right`记录最后一个页面的下标。

同时做到：历史记录数组只增不减，要减小就左移`right`指针。这样能避免一些重复开辟和释放空间带来的性能损耗。

visit：

> 1. `now++`
>
>     如果`now`超过了历史记录数组的大小，则将当前页面push到历史记录数组中
>
>     否则，直接将`history[now]`记为当前页面
>
> 2. `right = now`。这是因为一旦访问新页面，则无法再“forward”
>
>     并不需要真的将“无法forward到的页面”从数组中移除，直接等待新访问页面将其覆盖即可

back：

> `now = max(0, now - step)`，然后直接返回`history[now]`

forward：

> `now = min(right, now + step)`，然后直接返回`history[now]`

+ 时间复杂度$O(N^2)$
+ 空间复杂度$O(N\log N)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-02-26 13:16:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-26 13:37:36
 */
class BrowserHistory {
private:
    vector<string> history;
    int now, right;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        now = right = 0;
    }
    
    void visit(string url) {
        if (++now == history.size()) {
            history.push_back(url);

        } else {
            history[now] = url;
        }
        right = now;
    }
    
    string back(int steps) {
        now = max(0, now - steps);
        return history[now];
    }
    
    string forward(int steps) {
        now = min(right, now + steps);
        return history[now];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
```

+ 执行用时分布14ms击败92.71%
+ 消耗内存分布60.61MB击败96.09%

#### Python

```python
'''
Author: LetMeFly
Date: 2025-02-26 13:38:49
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-26 13:41:11
'''
class BrowserHistory:
    def __init__(self, homepage: str):
        self.history = [homepage]
        self.now = self.right = 0

    def visit(self, url: str) -> None:
        self.now += 1
        if self.now == len(self.history):
            self.history.append(url)
        else:
            self.history[self.now] = url
        self.right = self.now

    def back(self, steps: int) -> str:
        self.now = max(0, self.now - steps)
        return self.history[self.now]

    def forward(self, steps: int) -> str:
        self.now = min(self.right, self.now + steps)
        return self.history[self.now]


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-02-26 13:41:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-26 13:45:07
 */
import java.util.List;
import java.util.ArrayList;

class BrowserHistory {
    private List<String> history;
    private int now, right;

    public BrowserHistory(String homepage) {
        history = new ArrayList<>();
        now = right = 0;
        history.add(homepage);
    }
    
    public void visit(String url) {
        if (++now == history.size()) {
            history.add(url);
        } else {
            history.set(now, url);
        }
        right = now;
    }
    
    public String back(int steps) {
        now = Math.max(0, now - steps);
        return history.get(now);
    }
    
    public String forward(int steps) {
        now = Math.min(right, now + steps);
        return history.get(now);
    }
}

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory obj = new BrowserHistory(homepage);
 * obj.visit(url);
 * String param_2 = obj.back(steps);
 * String param_3 = obj.forward(steps);
 */
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-02-26 13:45:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-26 13:49:00
 */
package main

type BrowserHistory struct {
    history []string
    now,
    right int
}


func Constructor(homepage string) BrowserHistory {
    history := make([]string, 1)
    history[0] = homepage
    return BrowserHistory{
        history: history,
        now: 0,
        right: 0,
    }
}


func (this *BrowserHistory) Visit(url string)  {
    this.now++
    if this.now == len(this.history) {
        this.history = append(this.history, url)
    } else {
        this.history[this.now] = url
    }
    this.right = this.now
}


func (this *BrowserHistory) Back(steps int) string {
    this.now = max(0, this.now - steps)
    return this.history[this.now]
}


func (this *BrowserHistory) Forward(steps int) string {
    this.now = min(this.right, this.now + steps)
    return this.history[this.now]
}


/**
 * Your BrowserHistory object will be instantiated and called as such:
 * obj := Constructor(homepage);
 * obj.Visit(url);
 * param_2 := obj.Back(steps);
 * param_3 := obj.Forward(steps);
 */
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/145877201)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/02/26/LeetCode%201472.%E8%AE%BE%E8%AE%A1%E6%B5%8F%E8%A7%88%E5%99%A8%E5%8E%86%E5%8F%B2%E8%AE%B0%E5%BD%95/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
