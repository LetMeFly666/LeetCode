---
title: 2960.统计已测试设备
date: 2024-05-10 16:21:27
tags: [题解, LeetCode, 简单, 数组, 模拟]
---

# 【LetMeFly】2960.统计已测试设备：看测试了多少次

力扣题目链接：[https://leetcode.cn/problems/count-tested-devices-after-test-operations/](https://leetcode.cn/problems/count-tested-devices-after-test-operations/)

<p>给你一个长度为 <code>n</code> 、下标从<strong> 0 </strong>开始的整数数组 <code>batteryPercentages</code> ，表示 <code>n</code> 个设备的电池百分比。</p>

<p>你的任务是按照顺序测试每个设备 <code>i</code>，执行以下测试操作：</p>

<ul>
	<li>如果 <code>batteryPercentages[i]</code> <strong>大于</strong> <code>0</code>：

	<ul>
		<li><strong>增加</strong> 已测试设备的计数。</li>
		<li>将下标在 <code>[i + 1, n - 1]</code> 的所有设备的电池百分比减少 <code>1</code>，确保它们的电池百分比<strong> 不会低于</strong> <code>0</code> ，即 <code>batteryPercentages[j] = max(0, batteryPercentages[j] - 1)</code>。</li>
		<li>移动到下一个设备。</li>
	</ul>
	</li>
	<li>否则，移动到下一个设备而不执行任何测试。</li>
</ul>

<p>返回一个整数，表示按顺序执行测试操作后 <strong>已测试设备</strong> 的数量。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>batteryPercentages = [1,1,2,1,3]
<strong>输出：</strong>3
<strong>解释：</strong>按顺序从设备 0 开始执行测试操作：
在设备 0 上，batteryPercentages[0] &gt; 0 ，现在有 1 个已测试设备，batteryPercentages 变为 [1,0,1,0,2] 。
在设备 1 上，batteryPercentages[1] == 0 ，移动到下一个设备而不进行测试。
在设备 2 上，batteryPercentages[2] &gt; 0 ，现在有 2 个已测试设备，batteryPercentages 变为 [1,0,1,0,1] 。
在设备 3 上，batteryPercentages[3] == 0 ，移动到下一个设备而不进行测试。
在设备 4 上，batteryPercentages[4] &gt; 0 ，现在有 3 个已测试设备，batteryPercentages 保持不变。
因此，答案是 3 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>batteryPercentages = [0,1,2]
<strong>输出：</strong>2
<strong>解释：</strong>按顺序从设备 0 开始执行测试操作：
在设备 0 上，batteryPercentages[0] == 0 ，移动到下一个设备而不进行测试。
在设备 1 上，batteryPercentages[1] &gt; 0 ，现在有 1 个已测试设备，batteryPercentages 变为 [0,1,1] 。
在设备 2 上，batteryPercentages[2] &gt; 0 ，现在有 2 个已测试设备，batteryPercentages 保持不变。
因此，答案是 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == batteryPercentages.length &lt;= 100 </code></li>
	<li><code>0 &lt;= batteryPercentages[i] &lt;= 100</code></li>
</ul>


    
## 解题方法：模拟

使用一个变量```ans```来记录测试的总次数。测试发生一次，后面所有的电池都要掉一格电。但是不用真的模拟让他们都掉电。

遍历电池数组，看当前电量是否大于测试次数。若大于则将发生测试，否则什么都不会发生。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int ans = 0;
        for (int t : batteryPercentages) {
            if (t - ans > 0) {
                ans++;
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
    def countTestedDevices(self, batteryPercentages: List[int]) -> int:
        ans = 0
        for t in batteryPercentages:
            if t > ans:
                ans += 1
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/05/10/LeetCode%202960.%E7%BB%9F%E8%AE%A1%E5%B7%B2%E6%B5%8B%E8%AF%95%E8%AE%BE%E5%A4%87/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/138672383](https://letmefly.blog.csdn.net/article/details/138672383)
