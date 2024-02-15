---
title: 135.分发糖果
date: 2022-07-25 15:48:01
tags: [题解, LeetCode, 困难, 贪心, 数组, 模拟]
---

# 【LetMeFly】图解：135.分发糖果

力扣题目链接：[https://leetcode.cn/problems/candy/](https://leetcode.cn/problems/candy/)

<p><code>n</code> 个孩子站成一排。给你一个整数数组 <code>ratings</code> 表示每个孩子的评分。</p>

<p>你需要按照以下要求，给这些孩子分发糖果：</p>

<ul>
	<li>每个孩子至少分配到 <code>1</code> 个糖果。</li>
	<li>相邻两个孩子评分更高的孩子会获得更多的糖果。</li>
</ul>

<p>请你给每个孩子分发糖果，计算并返回需要准备的 <strong>最少糖果数目</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<strong>输入：</strong>ratings = [1,0,2]
<strong>输出：</strong>5
<strong>解释：</strong>你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果。
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>ratings = [1,2,2]
<strong>输出：</strong>4
<strong>解释：</strong>你可以分别给第一个、第二个、第三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这满足题面中的两个条件。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == ratings.length</code></li>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= ratings[i] &lt;= 2 * 10<sup>4</sup></code></li>
</ul>


    
## 方法一：找到最小

思路很简单：先找到所有的“极小点”（前一个rating和后一个rating都大于这个rating）

然后对于每一个极小点，从$1$开始分配糖果，并不断向两边延伸，直到不再递增为止。

延伸过程中，分配糖果的数量累加。

![极小点](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/5a567f411b9e4bf1ba62dd787515bdad.png#pic_center)

之后，再次遍历一遍“糖果分配数组”，如果遇到**相邻**的不符合条件的情况，就修正不呼和条件的分配：

![再次遍历](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/4b9ac48aa1e74da6bc158821763368e4.png#pic_center)

+ 时间复杂度$O(n)$，其中$n$是小朋友的数量
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> mins;
        vector<int> candies(ratings.size());
		// 找“极小点”
        for (int i = 0; i < ratings.size(); i++) {
            if ((i - 1 >= 0 && ratings[i - 1] < ratings[i]) || (i + 1 < ratings.size() && ratings[i + 1] < ratings[i])) {
                continue;
            }
            mins.push_back(i);
        }

		// 从极小点开始向两边拓展
        for (int thisMin : mins) {
            int thisCandy = 1;
            int i = thisMin;
            while (true) {
                candies[i] = thisCandy;
                thisCandy++;
                if (i - 1 >= 0 && ratings[i - 1] > ratings[i]) {
                    i--;
                }
                else {
                    break;
                }
            }
            i = thisMin;
            thisCandy = 1;
            while (true) {
                candies[i] = thisCandy;
                thisCandy++;
                if (i + 1 < ratings.size() && ratings[i + 1] > ratings[i]) {
                    i++;
                }
                else {
                    break;
                }
            }
        }
        
		// 更新相邻的不满足条件的情况
        for (int i = 1; i < candies.size(); i++) {
            if (ratings[i - 1] > ratings[i] && candies[i - 1] <= candies[i]) {
                candies[i - 1] = candies[i] + 1;
            }
            if (ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
		
		// 累加求和
        int ans = 0;
        for (int& t : candies)
            ans += t;
        return ans;
    }
};
```

图片制作不易，喜欢了就点个赞再走吧

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/25/LeetCode%200135.%E5%88%86%E5%8F%91%E7%B3%96%E6%9E%9C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125977968](https://letmefly.blog.csdn.net/article/details/125977968)
