---
title: 面试题05.02.二进制数转字符串
date: 2023-03-02 09:41:33
tags: [题解, LeetCode, 中等, 二进制, 进制转换, 模拟]
---

# 【LetMeFly】面试题 05.02.二进制数转字符串

力扣题目链接：[https://leetcode.cn/problems/bianry-number-to-string-lcci/](https://leetcode.cn/problems/bianry-number-to-string-lcci/)

<p>二进制数转字符串。给定一个介于0和1之间的实数（如0.72），类型为double，打印它的二进制表达式。如果该数字无法精确地用32位以内的二进制表示，则打印“ERROR”。</p>

<p><strong>示例1:</strong></p>

<pre>
<strong> 输入</strong>：0.625
<strong> 输出</strong>："0.101"
</pre>

<p><strong>示例2:</strong></p>

<pre>
<strong> 输入</strong>：0.1
<strong> 输出</strong>："ERROR"
<strong> 提示</strong>：0.1无法被二进制准确表示
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>32位包括输出中的 <code>"0."</code> 这两位。</li>
	<li>题目保证输入用例的小数位数最多只有 <code>6</code> 位</li>
</ul>

## 方法一：模拟：乘2取余

这道题比较“便民”的是，二进制长度超过32则输出ERROR。因此我们就不需要判断是否为“无限小数”了。

每次将num乘以2，如果num的个位是1，则将```1```添加到答案末尾（$num -= 1$）；否则将```0```添加到答案末尾。

如此往复，直到num为0（转换完成）或答案的长度到达32（强制结束转换，转换失败）

+ 时间复杂度$O(C)$，其中$C$是转换为二进制后的字符串长度。$C\leq 31$
+ 空间复杂度$O(C)$，当返回```ERROR```时需要占据32个char大小的空间

### AC代码

#### C++

```cpp
class Solution {
public:
    string printBin(double num) {
        string ans = "0.";
        while (true) {
            num *= 2;
            int thisVal = num >= 1;
            ans += (char)('0' + thisVal);
            num -= thisVal;
            if (num == 0) {
                return ans;
            }
            if (ans.size() == 32) {
                return "ERROR";
            }
        }
    }
};
```

#### Python

```python
class Solution:
    def printBin(self, num: float) -> str:
        ans = "0."
        while True:
            num *= 2
            thisVal = num >= 1
            ans += chr(ord('0') + thisVal)
            num -= thisVal
            if num == 0:
                return ans
            if len(ans) == 32:
                return "ERROR"
```

### What's more

本题无输入为“0”的测试样例，截至当前（2023.3.2 9:53），在控制台输入0时得到的答案是“0.”。但其实答案为“0”比较好

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/03/02/LeetCode%20%E9%9D%A2%E8%AF%95%E9%A2%98%2005.02.%20%E4%BA%8C%E8%BF%9B%E5%88%B6%E6%95%B0%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129295125](https://letmefly.blog.csdn.net/article/details/129295125)
