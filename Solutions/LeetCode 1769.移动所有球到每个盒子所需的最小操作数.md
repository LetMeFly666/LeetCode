---
title: 1769.移动所有球到每个盒子所需的最小操作数
date: 2022-12-02 13:18:55
tags: [题解, LeetCode, 中等, 数组, 字符串, 数学, 思维]
---

# 【LetMeFly】1769.移动所有球到每个盒子所需的最小操作数

力扣题目链接：[https://leetcode.cn/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/](https://leetcode.cn/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/)

<p>有 <code>n</code> 个盒子。给你一个长度为 <code>n</code> 的二进制字符串 <code>boxes</code> ，其中 <code>boxes[i]</code> 的值为 <code>'0'</code> 表示第 <code>i</code> 个盒子是 <strong>空</strong> 的，而 <code>boxes[i]</code> 的值为 <code>'1'</code> 表示盒子里有 <strong>一个</strong> 小球。</p>

<p>在一步操作中，你可以将 <strong>一个</strong> 小球从某个盒子移动到一个与之相邻的盒子中。第 <code>i</code> 个盒子和第 <code>j</code> 个盒子相邻需满足 <code>abs(i - j) == 1</code> 。注意，操作执行后，某些盒子中可能会存在不止一个小球。</p>

<p>返回一个长度为 <code>n</code> 的数组 <code>answer</code> ，其中 <code>answer[i]</code> 是将所有小球移动到第 <code>i</code> 个盒子所需的 <strong>最小</strong> 操作数。</p>

<p>每个 <code>answer[i]</code> 都需要根据盒子的 <strong>初始状态</strong> 进行计算。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>boxes = "110"
<strong>输出：</strong>[1,1,3]
<strong>解释：</strong>每个盒子对应的最小操作数如下：
1) 第 1 个盒子：将一个小球从第 2 个盒子移动到第 1 个盒子，需要 1 步操作。
2) 第 2 个盒子：将一个小球从第 1 个盒子移动到第 2 个盒子，需要 1 步操作。
3) 第 3 个盒子：将一个小球从第 1 个盒子移动到第 3 个盒子，需要 2 步操作。将一个小球从第 2 个盒子移动到第 3 个盒子，需要 1 步操作。共计 3 步操作。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>boxes = "001011"
<strong>输出：</strong>[11,8,5,4,3,4]</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == boxes.length</code></li>
	<li><code>1 &lt;= n &lt;= 2000</code></li>
	<li><code>boxes[i]</code> 为 <code>'0'</code> 或 <code>'1'</code></li>
</ul>


    
## 方法一：数学思维

首先遍历一遍原始数组，求出将所有小球全部移动到下标$0$的话所需要的步骤。同时，记录下来从下标$1$开始到结束，一共有多少个小球

```cpp
int right1 = 0, left1 = 0, cnt = 0;  // right1记录下标0后面有多少个1（不包含下标0） | cnt记录将所有小球都移动到下标0需要多少步 | left1 记录下标0左边有多少个1
int n = boxes.size();
for (int i = 1; i < n; i++) {
    if (boxes[i] == '1') {
        right1++, cnt += i;
    }
}
vector<int> ans(n);
ans[0] = cnt;
```



接下来我们再次遍历数组，如果某个元素的上一个元素是```1```，那么这个元素左边的1的数量就会加一，因此```left1++```

这时候，这个盒子和上一个盒子相比，**这一个盒子左边***的所有```1```需要移动的步数都```+1```，这一个盒子左边共有```left1```个```1```，因此```cnt += left1```。

这时候，这个盒子和上一个盒子相比，**上一个盒子右边**的所有```1```需要移动的步数都```-1```，上一个盒子右边共有```right1```个1，因此```cnt -= right1```。

之后，如果这个盒子初始值也是```1```的话，再在遍历下一个元素之前提前更新```right1```的值（```right1--```）

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$，力扣答案不计入算法空间复杂度

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> minOperations(string& boxes) {
        int right1 = 0, left1 = 0, cnt = 0;
        int n = boxes.size();
        for (int i = 1; i < n; i++) {
            if (boxes[i] == '1') {
                right1++, cnt += i;
            }
        }
        vector<int> ans(n);
        ans[0] = cnt;
        for (int i = 1; i < n; i++) {
            if (boxes[i - 1] == '1')
                left1++;
            cnt -= right1;
            cnt += left1;
            ans[i] = cnt;
            if (boxes[i] == '1')
                right1--;
        }
        return ans;
    }
};
```

运行结果还不错：

![result](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/c10a7627b74d42d7abb5af376be815b1.jpeg#pic_center)

<!-- https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/5ecbd922fbc34ee6976b7c6e5c3f9bc2~tplv-k3u1fbpfcp-zoom-in-crop-mark:3024:0:0:0.awebp -->

<!-- https://pic.leetcode.cn/1669960002-JcRNJd-result.jpg -->

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/12/02/LeetCode%201769.%E7%A7%BB%E5%8A%A8%E6%89%80%E6%9C%89%E7%90%83%E5%88%B0%E6%AF%8F%E4%B8%AA%E7%9B%92%E5%AD%90%E6%89%80%E9%9C%80%E7%9A%84%E6%9C%80%E5%B0%8F%E6%93%8D%E4%BD%9C%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128146735](https://letmefly.blog.csdn.net/article/details/128146735)
