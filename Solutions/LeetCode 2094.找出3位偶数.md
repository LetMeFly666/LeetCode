---
title: 2094.找出 3 位偶数：遍历3位偶数
date: 2025-05-12 22:45:08
tags: [题解, LeetCode, 简单, 数组, 哈希表, 枚举, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】2094.找出 3 位偶数：遍历3位偶数

力扣题目链接：[https://leetcode.cn/problems/finding-3-digit-even-numbers/](https://leetcode.cn/problems/finding-3-digit-even-numbers/)

<p>给你一个整数数组 <code>digits</code> ，其中每个元素是一个数字（<code>0 - 9</code>）。数组中可能存在重复元素。</p>

<p>你需要找出 <strong>所有</strong> 满足下述条件且 <strong>互不相同</strong> 的整数：</p>

<ul>
	<li>该整数由 <code>digits</code> 中的三个元素按 <strong>任意</strong> 顺序 <strong>依次连接</strong> 组成。</li>
	<li>该整数不含 <strong>前导零</strong></li>
	<li>该整数是一个 <strong>偶数</strong></li>
</ul>

<p>例如，给定的 <code>digits</code> 是 <code>[1, 2, 3]</code> ，整数 <code>132</code> 和 <code>312</code> 满足上面列出的全部条件。</p>

<p>将找出的所有互不相同的整数按 <strong>递增顺序</strong> 排列，并以数组形式返回<em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>digits = [2,1,3,0]
<strong>输出：</strong>[102,120,130,132,210,230,302,310,312,320]
<strong>解释：</strong>
所有满足题目条件的整数都在输出数组中列出。 
注意，答案数组中不含有 <strong>奇数</strong> 或带 <strong>前导零</strong> 的整数。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>digits = [2,2,8,8,2]
<strong>输出：</strong>[222,228,282,288,822,828,882]
<strong>解释：</strong>
同样的数字（0 - 9）在构造整数时可以重复多次，重复次数最多与其在 <code>digits</code> 中出现的次数一样。 
在这个例子中，数字 8 在构造 288、828 和 882 时都重复了两次。 
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>digits = [3,7,5]
<strong>输出：</strong>[]
<strong>解释：</strong>
使用给定的 digits 无法构造偶数。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;=&nbsp;digits.length &lt;= 100</code></li>
	<li><code>0 &lt;= digits[i] &lt;= 9</code></li>
</ul>


    
## 解题方法：遍历统计

首先统计给出的$digits$数组中，$0-9$各有多少个（记为$times[j]$）。

接着从$100$到$998$遍历所有偶数，对于其中一个偶数$i$，统计$i$中$0-9$分别出现多少次（记为$thisTimes[j]$）。

如果$thisTimse[j]\gt times[j]$，则说明这个偶数无法由digits中的元素组成。

+ 时间复杂度$O(CD+len(digits))$，其中$D=10$，$C=500$
+ 空间复杂度$O(D)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-05-12 10:20:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-12 22:35:40
 */
class Solution {
private:
    int cnt[10] = {0};

    bool isOk(int i) {
        if (i % 2) {
            return false;
        }
        int temp[10] = {0};
        while (i) {
            temp[i % 10]++;
            i /= 10;
        }
        for (int i = 0; i < 10; i++) {
            if (cnt[i] < temp[i]) {
                return false;
            }
        }
        return true;
    }
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        for (int d : digits) {
            cnt[d]++;
        }
        vector<int> ans;
        for (int i = 100; i < 1000; i++) {
            if (isOk(i)) {
                ans.push_back(i);
            }
        }
        // sort(ans.begin(), ans.end());
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-05-12 10:20:43
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-12 13:16:04
'''
from typing import List

class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        times = [0] * 10
        for d in digits:
            times[d] += 1
        ans = []
        for i in range(100, 1000, 2):
            thisTimes = [0] * 10
            tmp = i
            while tmp:
                thisTimes[tmp % 10] += 1
                tmp //= 10
            ok = True
            for j in range(10):
                if thisTimes[j] > times[j]:
                    ok = False
                    break
            if ok:
                ans.append(i)
        return sorted(ans)

```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-05-12 10:20:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-12 22:38:33
 */
import java.util.Arrays;
import java.util.ArrayList;

class Solution {
    public int[] findEvenNumbers(int[] digits) {
        int[] times = new int[10];
        for (int d : digits) {
            times[d]++;
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 100; i < 1000; i += 2) {
            int tmp = i;
            int[] thisTimes = new int[10];
            while (tmp > 0) {
                thisTimes[tmp % 10]++;
                tmp /= 10;
            }
            boolean ok = true;
            for (int j = 0; j < 10; j++) {
                if (thisTimes[j] > times[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans.add(i);
            }
        }
        int[] res = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) {
            res[i] = ans.get(i);
        }
        return res;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-05-12 21:58:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-12 22:43:11
 */
package main

func findEvenNumbers(digits []int) []int {
    times := make([]int, 10)
    for _, d := range digits {
        times[d]++
    }
    ans := make([]int, 0)
    for i := 100; i < 1000; i += 2 {
        thisTimes := make([]int, 10)
        for tmp := i; tmp > 0; tmp /= 10 {
            thisTimes[tmp % 10]++
        }
        ok := true
        for j := range times {
            if thisTimes[j] > times[j] {
                ok = false
                break
            }
        }
        if ok {
            ans = append(ans, i)
        }
    }
    return ans
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/147906775)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/05/12/LeetCode%202094.%E6%89%BE%E5%87%BA3%E4%BD%8D%E5%81%B6%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
