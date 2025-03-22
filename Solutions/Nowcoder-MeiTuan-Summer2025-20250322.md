---
title: 牛客-美团暑期2025-20250322-前两题和第三题的思路
date: 2025-03-22 22:57:49
tags: [题解, Nowcoder, 字符串, 回文, 回文串, 模拟, 暴力]
categories: [题解, 牛客]
---

# 【LetMeFly】牛客-美团暑期2025-20250322-前两题和第三题的思路

第三题刚开始想复杂了，后面想到了个思路但是没来得及实现。

## 一：对称回文串

标签：[回文串](https://blog.letmefly.xyz/tags/%E5%9B%9E%E6%96%87%E4%B8%B2/)

### 题目描述

判断一个字符串有多少个长度大于1的`对称回文子串`。

一个字符串为对称回文串当且仅当：

+ 该字符串为回文串
+ 该字符串只由字母`AHIMOTUVWXY`组成

数据范围：字符串长度不超过$100$

### 解题思路

$O(n^2)$枚举每个字符串子串，判断当前字符串是否为`对称回文串`。

### AC代码

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-22 19:14:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-22 19:25:02
 */
#include <bits/stdc++.h>
using namespace std;

inline bool isOk(char c) {
    static const string okList = "AHIMOTUVWXY";
    for (char ok : okList) {
        if (c == ok) {
            return true;
        }
    }
    return false;
}

bool isOk(string s) {
    for (char c : s) {
        if (!isOk(c)) {
            return false;
        }
    }
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

int solve(string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {  // 长度大于1
            bool thisIsOk = isOk(s.substr(i, j - i + 1));
            ans += thisIsOk;
            #ifdef _WIN32
                if (thisIsOk) {
                    printf("i = %d, j = %d, s.substr(%d, %d) = %s : OK\n", i, j, i, j, s.substr(i, j).c_str());
                }
            #endif
        }
    }
    return ans;
}

int main() {
#ifdef _WIN32
    vector<string> S = {"AHHAMTT"};
    vector<int> ANS = {3};
    for (int i = 0; i < S.size(); i++) {
        int ans = solve(S[i]);
        cout << S[i] << ": " << ans << endl;
        assert(ans == ANS[i]);
    }
#else
    string s;
    cin >> s;
    cout << solve(s) << endl;
#endif
    return 0;
}
```

## 二：下一个更大元素

标签：[暴力](https://blog.letmefly.xyz/tags/%E6%9A%B4%E5%8A%9B/)[模拟](https://blog.letmefly.xyz/tags/%E6%A8%A1%E6%8B%9F/)

### 题目描述

判断一个“全排列”的数组有多少个长度为奇数的子数组满足：

> 数组最中间的元素正好为数组的中位数

数据范围：单个测试用例多组输入字符串总长度不超过$10^4$

### 解题思路

本来想着先暴力一波看看能得多少分，结果就AC了，并且只用了84ms。

### AC代码

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-22 19:30:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-22 19:36:56
 */
// 诶，不是哥们，还没利用“排列中数各不相同的性质”呢，咋就84ms然后AC了
#include <bits/stdc++.h>
using namespace std;

int a[10010];

int solve(int n) {
    int ans = 0;
    for (int start = 0; start < n; start++) {
        int lt = 0, gt = 0;
        ans++;
        for (int i = 1; start - i >= 0 && start + i < n; i++) {
            if (a[start - i] > a[start]) {
                gt++;
            } else {
                lt++;
            }
            if (a[start + i] > a[start]) {
                gt++;
            } else {
                lt++;
            }
            ans += lt == gt;
        }
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int ans = solve(n);
        printf("%d\n", ans);
    }
    return 0;
}
```

## 三：移动的机器人最终停在哪里

标签：[模拟](https://blog.letmefly.xyz/tags/%E6%A8%A1%E6%8B%9F/)

### 题目描述

共n个位置机器人初始位置在$k$，问机器人执行完指令可能停在哪些位置。

指令执行方式为：

> 一个指令字符串，一个字符为一个指令。
>
> 字符`L`表示机器人向左移动一个位置，`R`表示向右移动一个位置，`?`表示既可以向左移动一个位置又可以向右移动一个位置。
>
> 若机器人达到了边界的位置无法向目标方向移动，则停在原地。

数据范围$10^6$

### 解题思路

假设位置有无限多个，那么不论移动多少次，最终的可能位置要么全是奇数，要么全是偶数：

> 例如初始位置是5，移动一次可能到4或6（都是偶数）
>
> 移动两次可能到3或5或7（都是奇数）

除非移动到了边界可能导致终点既有可能奇数又可能有偶数。

因此可以使用如下结构：

```cpp
struct Range {
    int start, end;

    Range(int a, int b) : start(a), end(b) {};
};
```

那么`vector<Range>`则表示所有终点的可能范围，其中`Range`为`start=3, end=7`的话代表终点范围可能是`3, 5, 7`。

每次移动都更新所有可以到达的终点。并合并。

> 为什么要合并呢
>
> > 因为不合并的话，最终的合法终点范围可能会越来越多，并且有重复现象。
>
> 怎么个合并法呢？
>
> > 例如有段范围表示`1, 3, 5, 7`，有段范围表示`3, 5, 7, 9`，那么它们就可以合并为`1, 3, 5, 7, 9`（使用`Range(1, 9)`表示即可）
>
> 具体怎么做？
> 
> > 可以奇偶分开合并。例如对于奇数：先将位置排序，然后判断下一个位置和上一个位置是否重复或可拼接，若能拼接则合并之。

没有具体验证，由于最多存在：开头、中间、结尾的奇数和偶数等有限个“终点可达区间”，所以每次都合并的话似乎区间个数不会超过$6$，$6\times 10^6$在合理范围内。

### WA代码

嗐，没写完时间就到了，还好在没合并的时候就交了一版，过了`%20`。

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-22 20:15:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-22 20:38:50
 */

#include <bits/stdc++.h>

using namespace std;


struct Range {
    int start, end;

    Range(int a, int b) : start(a), end(b) {};
};

int n, k;
string s;
vector<Range> OkList;
bool a[1000010] = {false};



void print() {
    for (Range& r : OkList) {
        for (int i = r.start; i <= r.end; i += 2) {
            a[i] = true;
        }
    }
    for (int i = 1; i <= n; i++) {
        putchar(a[i] ? '1' : '0');
    }
}

vector<Range> genOdd() {
    vector<Range> ans;
    for (Range r : OkList) {
        if (r.start % 2) {
            ans.push_back(r);
        }
    }
    return ans;
}

vector<Range> genEven() {
    vector<Range> ans;
    for (Range r : OkList) {
        if (r.start % 2 == 0) {
            ans.push_back(r);
        }
    }
    return ans;
}

vector<Range> mergeOddOrEven(vector<Range>& odd) {  // 全是奇数或全是偶数
    if (odd.empty()) {
        return {};
    }
    vector<Range> ans;
    int l = odd[0].start, r = odd[0].end;
    for (int i = 1; i <= odd.size(); i++) {
        if (i == odd.size() || odd[i].start > r + 2) {
            ans.push_back(Range(l, r));
            l = odd[i].start, r = odd[i].end;
        } else {
            r = max(r, odd[i].end);
        }
    }
    return ans;
}


void mergeList() {
    vector<Range> odd = genOdd();
    vector<Range> even = genEven();
    OkList = mergeOddOrEven(odd);
    for (Range r : mergeOddOrEven(even)) {
        OkList.push_back(r);
    }
}

void left(vector<Range>& leftOk) {
    for (Range r : OkList) {
        int left = r.start;
        int right = r.end;
        left--;
        right--;
        if (left == 0) {
            leftOk.push_back(Range(1, 1));
            left = 2;
        }
        if (left <= right)  {
            leftOk.push_back(Range(left, right));
        }
    }
}

void right(vector<Range>& leftOk) {
    for (Range& r : OkList) {
        int left = r.start;
        int right = r.end;
        left++;
        right++;
        if (right == n + 1) {
            leftOk.push_back(Range(n, n));
            right = n - 1;
        }
        if (left <= right)  {
            leftOk.push_back(Range(left, right));
        }
    }
}

/*
3 2
RL?

010
*/

/*
5 2
?????

11111
*/

int main() {
    cin >> n >> k;
    cin >> s;
    OkList.push_back(Range(k, k));
    
    for (char c : s) {
        vector<Range> nextOk;
        if (c == 'L' || c == '?') {
            left(nextOk);
        }
        if (c == 'R' || c == '?') {
            right(nextOk);
        }
        OkList = move(nextOk);
        mergeList();
    }

    print();
    return 0;
}
```

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146448313)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/22/Nowcoder-MeiTuan-Summer2025-20250322/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
