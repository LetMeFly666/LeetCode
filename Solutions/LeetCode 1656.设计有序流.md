---
title: 1656.设计有序流：阅读理解
date: 2022-08-16 08:46:16
tags: [题解, LeetCode, 简单, 设计, 数组, 哈希表, 数据流]
---

# 【LetMeFly】1656.设计有序流：阅读理解

力扣题目链接：[https://leetcode.cn/problems/design-an-ordered-stream/](https://leetcode.cn/problems/design-an-ordered-stream/)

<p>有 <code>n</code> 个 <code>(id, value)</code> 对，其中 <code>id</code> 是 <code>1</code> 到 <code>n</code> 之间的一个整数，<code>value</code> 是一个字符串。不存在 <code>id</code> 相同的两个 <code>(id, value)</code> 对。</p>

<p>设计一个流，以 <strong>任意</strong> 顺序获取 <code>n</code> 个 <code>(id, value)</code> 对，并在多次调用时 <strong>按 <code>id</code> 递增的顺序</strong> 返回一些值。</p>

<p>实现 <code>OrderedStream</code> 类：</p>

<ul>
	<li><code>OrderedStream(int n)</code> 构造一个能接收 <code>n</code> 个值的流，并将当前指针 <code>ptr</code> 设为 <code>1</code> 。</li>
	<li><code>String[] insert(int id, String value)</code> 向流中存储新的 <code>(id, value)</code> 对。存储后：
	<ul>
		<li>如果流存储有 <code>id = ptr</code> 的 <code>(id, value)</code> 对，则找出从 <code>id = ptr</code> 开始的 <strong>最长 id 连续递增序列</strong> ，并 <strong>按顺序</strong> 返回与这些 id 关联的值的列表。然后，将 <code>ptr</code> 更新为最后那个  <code>id + 1</code> 。</li>
		<li>
		<p>否则，返回一个空列表。</p>
		</li>
	</ul>
	</li>
</ul>

<p> </p>

<p><strong>示例：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/11/15/q1.gif" style="width: 682px; height: 240px;" /></strong></p>

<pre>
<strong>输入</strong>
["OrderedStream", "insert", "insert", "insert", "insert", "insert"]
[[5], [3, "ccccc"], [1, "aaaaa"], [2, "bbbbb"], [5, "eeeee"], [4, "ddddd"]]
<strong>输出</strong>
[null, [], ["aaaaa"], ["bbbbb", "ccccc"], [], ["ddddd", "eeeee"]]

<strong>解释</strong>
OrderedStream os= new OrderedStream(5);
os.insert(3, "ccccc"); // 插入 (3, "ccccc")，返回 []
os.insert(1, "aaaaa"); // 插入 (1, "aaaaa")，返回 ["aaaaa"]
os.insert(2, "bbbbb"); // 插入 (2, "bbbbb")，返回 ["bbbbb", "ccccc"]
os.insert(5, "eeeee"); // 插入 (5, "eeeee")，返回 []
os.insert(4, "ddddd"); // 插入 (4, "ddddd")，返回 ["ddddd", "eeeee"]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 1000</code></li>
	<li><code>1 <= id <= n</code></li>
	<li><code>value.length == 5</code></li>
	<li><code>value</code> 仅由小写字母组成</li>
	<li>每次调用 <code>insert</code> 都会使用一个唯一的 <code>id</code></li>
	<li>恰好调用 <code>n</code> 次 <code>insert</code></li>
</ul>


    
## 方法一：构造

类初始化时，开辟一个大小为$n+1$的空间，并将$ptr$赋值为$1$

之后每次插入元素时，先将元素放入数组中的对应位置，然后当指针在合法范围内且当前位置不为空时，将这个元素添加到答案中。

+ 时间复杂度：
   + 初始化的时间复杂度为$O(n)$，因为要开辟大小为$n$的空间
   + 之后每次调用的平均复杂度为$O(1)$，因为所有的$n$次调用共访问了数组$1$或$2$次
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2022-08-16 08:40:19
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-16 08:42:36
 */
class OrderedStream {
private:
    vector<string> v;
    int nowLoc;
public:
    OrderedStream(int n) : nowLoc(1) {
        v = vector<string>(n + 1);
    }
    
    vector<string> insert(int idKey, string value) {
        v[idKey] = value;
        vector<string> ans;
        while (nowLoc < v.size() && v[nowLoc].size()) {
            ans.push_back(v[nowLoc++]);
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-02-24 09:09:17
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-24 09:11:29
'''
from typing import List

class OrderedStream:

    def __init__(self, n: int):
        self.n = n
        self.ptr = 1
        self.v = [None] * (n + 1)

    def insert(self, idKey: int, value: str) -> List[str]:
        self.v[idKey] = value
        if idKey != self.ptr:
            return []
        ans = []
        while self.ptr <= self.n and self.v[self.ptr]:
            ans.append(self.v[self.ptr])
            self.ptr += 1
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-02-24 09:09:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-24 09:25:19
 */
import java.util.List;
import java.util.ArrayList;

class OrderedStream {
    private int n;
    private int ptr;
    private final String[] v;

    public OrderedStream(int n) {
        this.n = n;
        ptr = 1;
        v = new String[n + 1];
    }
    
    public List<String> insert(int idKey, String value) {
        v[idKey] = value;
        if (idKey != ptr) {
            return new ArrayList<>();
        }
        List<String> ans = new ArrayList<>();
        while (ptr <= n && v[ptr] != null) {
            ans.add(v[ptr]);
            ptr++;
        }
        return ans;
    }
}
```

#### Golang：也可使用指针直接引用切片

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-02-24 09:09:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-24 09:35:40
 */
package main

type OrderedStream struct {
    n,
    ptr int
    v []string
}


func Constructor(n int) OrderedStream {
    return OrderedStream{
        n: n,
        ptr: 1,
        v: make([]string, n + 1),
    }
}


func (this *OrderedStream) Insert(idKey int, value string) []string {
    this.v[idKey] = value
    start := this.ptr
    for this.ptr <= this.n && len(this.v[this.ptr]) > 0 {
        this.ptr++
    }
    return this.v[start:this.ptr]
}
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/08/16/LeetCode%201656.%E8%AE%BE%E8%AE%A1%E6%9C%89%E5%BA%8F%E6%B5%81/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126358485](https://letmefly.blog.csdn.net/article/details/126358485)
