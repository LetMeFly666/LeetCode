---
title: 3200.三角形的最大高度
date: 2024-10-15 23:57:56
tags: [题解, LeetCode, 简单, 数组, 枚举]
categories: [题解, LeetCode]
---

# 【LetMeFly】3200.三角形的最大高度：枚举

力扣题目链接：[https://leetcode.cn/problems/maximum-height-of-a-triangle/](https://leetcode.cn/problems/maximum-height-of-a-triangle/)

<p>给你两个整数 <code>red</code> 和 <code>blue</code>，分别表示红色球和蓝色球的数量。你需要使用这些球来组成一个三角形，满足第 1 行有 1 个球，第 2 行有 2 个球，第 3 行有 3 个球，依此类推。</p>

<p>每一行的球必须是 <strong>相同 </strong>颜色，且相邻行的颜色必须<strong> 不同</strong>。</p>

<p>返回可以实现的三角形的 <strong>最大 </strong>高度。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">red = 2, blue = 4</span></p>

<p><strong>输出：</strong> 3</p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/06/16/brb.png" style="width: 300px; height: 240px; padding: 10px;" /></p>

<p>上图显示了唯一可能的排列方式。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">red = 2, blue = 1</span></p>

<p><strong>输出：</strong> <span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/06/16/br.png" style="width: 150px; height: 135px; padding: 10px;" /><br />
上图显示了唯一可能的排列方式。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">red = 1, blue = 1</span></p>

<p><strong>输出：</strong> <span class="example-io">1</span></p>
</div>

<p><strong class="example">示例 4：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">red = 10, blue = 1</span></p>

<p><strong>输出：</strong> <span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/06/16/br.png" style="width: 150px; height: 135px; padding: 10px;" /><br />
上图显示了唯一可能的排列方式。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= red, blue &lt;= 100</code></li>
</ul>


    
## 解题方法：枚举

使用一个大小为2的数组记录layer层所需两种颜色分别多少个。

使用layer从1层开始模拟，每次两种颜色分别加上layer。如果球数不足，则停止枚举layer。

+ 时间复杂度$O(\min(\sqrt{red}, \sqrt{blud}))$，因为$1+2+3+...+k=\frac{n(n+1)}{2}$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int cnt[2] = {0, 0};
        int layer = 1;
        while (true) {
            cnt[layer % 2] += layer++;
            if (!((cnt[0] <= red && cnt[1] <= blue) || (cnt[0] <= blue && cnt[1] <= red))) {
                return layer - 2;
            }
        }
    }
};
```

#### Python

```python
class Solution:
    def maxHeightOfTriangle(self, red: int, blue: int) -> int:
        cnt = [0, 0]
        for layer in range(1, 1000000):
            cnt[layer % 2] += layer
            if not ((cnt[0] <= red and cnt[1] <= blue) or (cnt[0] <= blue and cnt[1] <= red)):
                return layer - 1
        return -1  # Fake Return
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/10/15/LeetCode%203200.%E4%B8%89%E8%A7%92%E5%BD%A2%E7%9A%84%E6%9C%80%E5%A4%A7%E9%AB%98%E5%BA%A6/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/142967272](https://letmefly.blog.csdn.net/article/details/142967272)
