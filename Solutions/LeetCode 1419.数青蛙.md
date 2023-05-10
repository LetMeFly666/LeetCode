---
title: 1419.数青蛙
date: 2023-05-06 09:54:31
tags: [题解, LeetCode, 中等, 字符串, 计数, 模拟, 哈希表, 哈希, map]
---

# 【LetMeFly】1419.数青蛙

力扣题目链接：[https://leetcode.cn/problems/minimum-number-of-frogs-croaking/](https://leetcode.cn/problems/minimum-number-of-frogs-croaking/)

<p>给你一个字符串 <code>croakOfFrogs</code>，它表示不同青蛙发出的蛙鸣声（字符串 <code>"croak"</code> ）的组合。由于同一时间可以有多只青蛙呱呱作响，所以&nbsp;<code>croakOfFrogs</code> 中会混合多个 <code>“croak”</code> <em>。</em></p>

<p>请你返回模拟字符串中所有蛙鸣所需不同青蛙的最少数目。</p>

<p>要想发出蛙鸣 "croak"，青蛙必须 <strong>依序</strong> 输出 <code>‘c’, ’r’, ’o’, ’a’, ’k’</code> 这 5 个字母。如果没有输出全部五个字母，那么它就不会发出声音。如果字符串 <code>croakOfFrogs</code> 不是由若干有效的 "croak" 字符混合而成，请返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>croakOfFrogs = "croakcroak"
<strong>输出：</strong>1 
<strong>解释：</strong>一只青蛙 “呱呱” 两次
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>croakOfFrogs = "crcoakroak"
<strong>输出：</strong>2 
<strong>解释：</strong>最少需要两只青蛙，“呱呱” 声用黑体标注
第一只青蛙 "<strong>cr</strong>c<strong>oak</strong>roak"
第二只青蛙 "cr<strong>c</strong>oak<strong>roak</strong>"
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>croakOfFrogs = "croakcrook"
<strong>输出：</strong>-1
<strong>解释：</strong>给出的字符串不是 "croak<strong>"</strong> 的有效组合。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= croakOfFrogs.length &lt;= 10<sup>5</sup></code></li>
	<li>字符串中的字符只有 <code>'c'</code>, <code>'r'</code>, <code>'o'</code>, <code>'a'</code> 或者 <code>'k'</code></li>
</ul>


    
## 方法一：计数 + 模拟

题目大意是每只青蛙依次叫完“c、r、o、a、k”算作一次发声，一只青蛙完整叫完这一次后可以叫下一次，但是不能只叫一半。问最少有多少只青蛙在叫。

我们只需要一个计数器“cnt”，分别统计当前叫到“c、r、o、a、k”的青蛙数量。

接着还需要一个变量“nowFrog”来统计当前正在叫且还没有叫完的青蛙的数量。答案用变量“ans”来表示。

遍历发生字符串：

+ 如果当前字符是“c”，那么就说明这个声音来自某一只青蛙的开始，$nowFrog++$，并更新答案（同时发声的最大青蛙数量）和cnt
+ 否则，这个声音来自某只叫了一半的青蛙，假如这一声是“o”，那么就需要由一只“r”青蛙改叫“o”
  + 如果“r”青蛙数量为0，直接返回-1
  + 否则cnt[r]--，cnt[o]++
  注意查看这一声是否为最后一声“k”，如果为k，则说明某只青蛙叫完了，nowFrog--，cnt[o]--（其实cnt[0]可以恒为0）


+ 时间复杂度$O(len(croakOfFrogs))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char, int> ma = {{'c', 0}, {'r', 1}, {'o', 2}, {'a', 3}, {'k', 4}};
        int cnt[5] = {0};
        int nowFrog = 0;
        int ans = 0;
        for (char c : croakOfFrogs) {
            int th = ma[c];
            if (th == 0) {  // 新青蛙
                nowFrog++;
                ans = max(ans, nowFrog);
                cnt[0]++;
            }
            else {  // 老青蛙
                if (!cnt[th - 1]) {
                    return -1;
                }
                cnt[th - 1]--;
                if (th == 4) {  // 这个青蛙叫完了
                    nowFrog--;
                }
                else {
                    cnt[th]++;
                }
            }
        }
        return nowFrog ? -1 : ans;
    }
};
```

#### Python

```python
class Solution:
    def minNumberOfFrogs(self, croakOfFrogs: str) -> int:
        ma = {'c':0, 'r':1, 'o':2, 'a':3, 'k':4}
        cnt = [0] * 5
        nowFrog = 0
        ans = 0
        for c in croakOfFrogs:
            th = ma[c]
            if not th:  # 新青蛙
                nowFrog += 1
                ans = max(ans, nowFrog)
                cnt[0] += 1
            else:  # 老青蛙
                if not cnt[th - 1]:
                    return -1
                cnt[th - 1] -= 1
                if th == 4:  # 这个青蛙叫完了
                    nowFrog -= 1
                else:
                    cnt[th] += 1
        return ans if not nowFrog else -1
```

#### Java

🔥 感谢 [@水](https://leetcode.cn/u/shui-ar/)大佬 提供Java版本的代码~

```java
class Solution {
    public int minNumberOfFrogs(String croakOfFrogs) {
        if(croakOfFrogs.length()%5!=0){
            return -1;
        }
        HashMap<Character,Integer> map=new HashMap<>();
        map.put('c',0);
        map.put('r',1);
        map.put('o',2);
        map.put('a',3);
        map.put('k',4);
        int frog=0;
        int maxfrog=0;
        int[] count=new int[5];
        for(char now:croakOfFrogs.toCharArray()){
            int croak=map.get(now);
            if(now=='c'){
                frog++;
                count[0]++;
                maxfrog=Math.max(frog,maxfrog);
            }else{
                if(count[croak-1]==0){
                return -1;
                }
                count[croak-1]--;
                if(now=='k'){
                    frog--;
                }else{
                    count[croak]++;
                }
            }
        }
        if(frog>0){
            return -1;
        }
        return maxfrog;
    }
}
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/05/06/LeetCode%201419.%E6%95%B0%E9%9D%92%E8%9B%99/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130520908](https://letmefly.blog.csdn.net/article/details/130520908)
