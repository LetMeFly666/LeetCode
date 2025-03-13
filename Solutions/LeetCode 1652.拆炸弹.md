---
title: 1652.拆炸弹
date: 2024-05-05 14:09:15
tags: [题解, LeetCode, 简单, 数组, 滑动窗口]
categories: [题解, LeetCode]
---

# 【LetMeFly】1652.拆炸弹：滑动窗口——当个简单的中等题做

力扣题目链接：[https://leetcode.cn/problems/defuse-the-bomb/](https://leetcode.cn/problems/defuse-the-bomb/)

<p>你有一个炸弹需要拆除，时间紧迫！你的情报员会给你一个长度为 <code>n</code> 的 <strong>循环</strong> 数组 <code>code</code> 以及一个密钥 <code>k</code> 。</p>

<p>为了获得正确的密码，你需要替换掉每一个数字。所有数字会 <strong>同时</strong> 被替换。</p>

<ul>
	<li>如果 <code>k > 0</code> ，将第 <code>i</code> 个数字用 <strong>接下来</strong> <code>k</code> 个数字之和替换。</li>
	<li>如果 <code>k < 0</code> ，将第 <code>i</code> 个数字用 <strong>之前</strong> <code>k</code> 个数字之和替换。</li>
	<li>如果 <code>k == 0</code> ，将第 <code>i</code> 个数字用 <code>0</code> 替换。</li>
</ul>

<p>由于 <code>code</code> 是循环的， <code>code[n-1]</code> 下一个元素是 <code>code[0]</code> ，且 <code>code[0]</code> 前一个元素是 <code>code[n-1]</code> 。</p>

<p>给你 <strong>循环</strong> 数组 <code>code</code> 和整数密钥 <code>k</code> ，请你返回解密后的结果来拆除炸弹！</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>code = [5,7,1,4], k = 3
<b>输出：</b>[12,10,16,13]
<b>解释：</b>每个数字都被接下来 3 个数字之和替换。解密后的密码为 [7+1+4, 1+4+5, 4+5+7, 5+7+1]。注意到数组是循环连接的。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>code = [1,2,3,4], k = 0
<b>输出：</b>[0,0,0,0]
<b>解释：</b>当 k 为 0 时，所有数字都被 0 替换。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>code = [2,4,9,3], k = -2
<b>输出：</b>[12,5,6,13]
<b>解释：</b>解密后的密码为 [3+9, 2+3, 4+2, 9+4] 。注意到数组是循环连接的。如果 k 是负数，那么和为 <strong>之前</strong> 的数字。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == code.length</code></li>
	<li><code>1 <= n <= 100</code></li>
	<li><code>1 <= code[i] <= 100</code></li>
	<li><code>-(n - 1) <= k <= n - 1</code></li>
</ul>


    
## 解题方法：滑动窗口

![滑动窗口](https://cdn.letmefly.xyz/img/tag/huadongchuangkou.png)

<!-- ![滑动窗口](https://cdn.letmefly.xyz/img/tag/huadongchuangkou.png) -->

<!-- ![滑动窗口](https://pic.leetcode.cn/1714890751-WLqHKD-huadongchuangkou.png) -->

> 若$k=0$，则不在本次讨论范围内，直接返回全$0$数组即可。

先计算出```answer[0]```的值，使用两个变量```l```和```r```分别记录```answer[0]```的“求和范围”：

+ 若$k\gt 0$，则```answer[0]```的“求和范围”是```l = 1, r = k```
+ 否则（$k\lt 0$），```answer[0]```的“求和范围”是```l = n - (-k), r = n - 1```

现在，你有办法根据```answer[0]```的结果，快速求出```answer[1]```的结果吗？

> 当然，新的“求和范围”是```l' = (l + 1) mod n, r' = (r + 1) mod n```，
>
> 因此，只需要在```answer[0]```的基础上，减去一个```code[l]```并加上一个```code[r']```就好了。

以此类推，后面每个答案的值都能在上一个答案的基础上在$O(1)$时间内求得。这就是[滑动窗口](https://blog.letmefly.xyz/tags/%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3/)。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$，力扣返回值不计入算法空间复杂度

### AC代码

#### C++

```cpp
class Solution {
private:
    int n;
    
    inline int next(int i) {
        return (i + 1) % n;
    }

public:
    vector<int> decrypt(vector<int>& code, int k) {
        n = code.size();
        vector<int> ans(n);
        if (!k) {
            return ans;
        }
        int l, r, s = 0;  // left, right, sum
        if (k > 0) {  // [1, k]
            l = 1;
            for (r = l; r <= k; r++) {
                s += code[r];
            }
            r--;
        }
        else {  // [n - (-k), n - 1]
            r = n - 1;
            for (l = r; l >= n + k; l--) {
                s += code[l];
            }
            l++;
        }
        for (int i = 0; i < n; i++) {
            ans[i] = s;
            s -= code[l];
            l = next(l);
            r = next(r);
            s += code[r];
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def next(self, i: int) -> int:
        return (i + 1) % self.n
    
    def decrypt(self, code: List[int], k: int) -> List[int]:
        self.n = len(code)
        ans = [0] * self.n
        if not k:
            return ans
        l, r, s = 0, 0, 0
        if k > 0:
            l = 1
            for r in range(l, k + 1):
                s += code[r]
        else:
            r = self.n - 1
            for l in range(r, self.n + k - 1, -1):
                s += code[l]
        for i in range(self.n):
            ans[i] = s
            s -= code[l]
            l = self.next(l)
            r = self.next(r)
            s += code[r]
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/05/05/LeetCode%201652.%E6%8B%86%E7%82%B8%E5%BC%B9/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/138465984](https://letmefly.blog.csdn.net/article/details/138465984)
