---
title: 870.优势洗牌
date: 2022-10-08 13:18:20
tags: [题解, LeetCode, 中等, 贪心, 数组, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】趣解田忌赛马：能赢则赢，否则摆烂（贪心） - 870.优势洗牌

力扣题目链接：[https://leetcode.cn/problems/advantage-shuffle/](https://leetcode.cn/problems/advantage-shuffle/)

<p>给定两个大小相等的数组&nbsp;<code>nums1</code>&nbsp;和&nbsp;<code>nums2</code>，<code>nums1</code>&nbsp;相对于 <code>nums</code>&nbsp;的<em>优势</em>可以用满足&nbsp;<code>nums1[i] &gt; nums2[i]</code>&nbsp;的索引 <code>i</code>&nbsp;的数目来描述。</p>

<p>返回 <font color="#c7254e" face="Menlo, Monaco, Consolas, Courier New, monospace" size="1"><span style="background-color: rgb(249, 242, 244);">nums1</span></font>&nbsp;的<strong>任意</strong>排列，使其相对于 <code>nums2</code>&nbsp;的优势最大化。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [2,7,11,15], nums2 = [1,10,4,11]
<strong>输出：</strong>[2,11,7,15]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [12,24,8,32], nums2 = [13,25,32,11]
<strong>输出：</strong>[24,32,8,12]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums2.length == nums1.length</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 方法一：田忌赛马（贪心）

思路很简单，就是：

> 从对手战力最弱的🐎开始，每次从 自己未出场 且 战力大于对手的这匹🐎 的🐎中，挑选战力最小的一匹。
> 若无🐎可敌，则**开始摆烂**

举个例子，假如自己的五匹马的战力为```12、24、8、32、6```，对手的五匹马的战力为```13、25、32、11、998```

从对手的战力最弱的🐎开始，先看对手战力为```11```的🐎，再看战力为```13```的🐎，再看```25```，再看```32```，最后看```998```

1. 对于对手的```11```，自己的🐎中，未出场 且 战力大于```11```的有```12、24、32```，其中战力最小的是```12```，因此选派自己的```12```对抗对手的```11```
2. 对于对手的```13```，自己的🐎中，未出场 且 战力大于```13```的有```24、32```，其中战力最小的是```24```，因此选派自己的```24```对抗对手的```13```
3. 对于对手的```25```，自己的🐎中，未出场 且 战力大于```25```的有```32```，其中战力最小的是```32```，因此选派自己的```32```对抗对手的```25```
4. 对于对手的```32```，自己的🐎中，没有 未出场 且 战力大于```32```的🐎，**无🐎可敌，开始摆烂！**

怎么摆烂呢？反正也赢不了了，那么就在自己未出场的🐎中随便上吧！上谁都无所谓，反正也赢不了。

对面还有两匹马```32、998```没有对手，自己还有两匹马```8、6```没有出场。那就用自己的```8```对抗对手的```32```，自己的```6```对抗对手的```998```好了。

因此，对于对手的出场顺序（数组2）```[13, 25, 32, 11, 998]```，我们的回敬（打乱的数组1）是：```[24, 32, 8, 12, 6]```

能胜三场，还行还行。

**那么编程怎么实现呢？**

其实不难发现，我们在挑选对手和自己的🐎时，在背后默默进行了排序操作。

我们将对手的```[13, 25, 32, 11, 998]```默默排序成了```[11, 13, 25, 32, 998]```作为出场顺序；我们将自己的```[12, 24, 8, 32, 6]```默默排序成了```[6, 8, 12, 24, 32]```以方便选取“大于敌方且尽可能小”的🐎。

但是需要注意的是，对手的马匹排序后，原始顺序不能丢失，因为我们默默地将对手马匹按战力排序了，对手可不会因为你的排序而改变自己的出场顺序。

因此，在对对手的马匹进行排序前，不如先做个手脚：将对手的<马匹战力, 出场编号>进行绑定，依据战力排序，排序后出厂编号信息不会丢失。

至于自己的🐎，用一个“指针”记录当前判断到了哪一匹，如果这一匹马的战力不大于当前遍历到的对手的🐎的战力，就指针后移，找到第一个大于对手战力的位置，就是自己“未出场 且 战力大于对手”的🐎中，战力最小的那匹。 （若自己这匹马战力不足，那么指针后移之前，记得将这匹马标记或者存起来，表示“指针扫过了但是未出场”，以到最后和敌方的“无敌之🐎”进行摆烂）

+ 时间复杂度$O(n\log n)$，其中$n$是马匹个数。排序的时间复杂度是$O(n\log n)$，选马的时间复杂度是$O(n)$
+ 空间复杂度$O(n)$。我们使用了额外的空间来记录对手马匹的“出场编号”信息（$O(n)$），且使用了额外空间记录了自己“指针扫过但因战力不足而未出场的🐎”（$O(n)$）；排序的空间复杂度是$O(\log n)$

### AC代码

#### C++

```cpp
typedef pair<int, int> pii;  // <战力, 出场编号>
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
		// 记录对手(nums2)出场顺序信息
        vector<pii> tempNums2(n);
        for (int i = 0; i < n; i++) {
            tempNums2[i] = {nums2[i], i};
        }
		// 对对手、自己马匹排序
        sort(tempNums2.begin(), tempNums2.end());
        sort(nums1.begin(), nums1.end());

        vector<int> ans(n);  // ans存放最终答案
        int loc1 = 0;  // 自己的马匹的“指针”
        vector<int> unused;  // 指针扫过但未出场的马，留着摆烂使用
        for (int i = 0; i < n; i++) {  // 遍历对手马
            while (loc1 < n && nums1[loc1] <= tempNums2[i].first) {  // 自己的马战力不足
                unused.push_back(nums1[loc1]);  // 放入“未使用数组”
                loc1++;  // 指针后移
            }
            if (loc1 == n) {  // 指针到数组尾部，扫描完毕，无高战力马可出场，开始摆烂，摆烂完退出循环
                int locUnused = 0;  // 为了遍历“未使用数组”
                while (i < n) {  // 为后面所有的“对手无敌马”分配自己的“摆烂马”
                    ans[tempNums2[i++].second] = unused[locUnused++];
                }
                break;  // 摆烂完退出循环
            }
            ans[tempNums2[i].second] = nums1[loc1++];  // 为对手的彼马分配自己的 未使用且战力更强 的战力尽可能小马
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/10/08/LeetCode%200870.%E4%BC%98%E5%8A%BF%E6%B4%97%E7%89%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127207642](https://letmefly.blog.csdn.net/article/details/127207642)
