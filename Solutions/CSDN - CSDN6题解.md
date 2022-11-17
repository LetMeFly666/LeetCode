---
title: CSDN - CSDN6题解
date: 2022-09-23 16:32:53
tags: [题解, CSDN]
---

>  CSDN编程竞赛报名地址：https://edu.csdn.net/contest/detail/16


*努力是为了让自己不平庸*


## 前言/背景
> 看到CSDN竞赛6的通知后，报着随缘的态度，参加了这次竞赛。（是的，睡过是不可能的）
## 大赛简介
> 只能使用在线IDE，不能使用本地工具，不能复制粘贴，不能跳出页面。
> 时间2h
> 一共4道编程题
> 可提前交卷

## 解题思路
### 1. 严查枪火

#### 题目描述

X国最近开始严管枪火。 像是“ak”,“m4a1”,“skr”。都是明令禁止的。 现在小Q查获了一批违禁物品其中部分是枪支。
小Q想知道自己需要按照私藏枪火来关押多少人。 （只有以上三种枪被视为违法）

#### 解题思路

直接统计输入的字符串中，有多少是是“ak”,“m4a1”或“skr”

#### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	int ans = 0;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (s == "ak" || s == "m4a1" || s == "skr")
			ans++;
	}
	cout << ans << endl;
	return 0;
}
```

### 2. 鬼画符门

#### 题目描述
鬼画符门，每年都会统计自己宗门鬼画符消耗的数量，往年一直是大师兄管理， 但是这次鬼艺接手了， 你能帮鬼艺写一个
程序统计每年消耗数量最多的鬼画符吗？

#### 解题思路

map记录每种物品出现的次数，求出最大出现次数，遍历一遍输出次数为最大次数的物品。

#### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	unordered_map<string, int> ma;
	int M = 0;
	while (n--) {
		string s;
		cin >> s;
		ma[s]++;
		M = max(M, ma[s]);
	}
	for (auto [a, b] : ma) {
		if (b == M) {
			cout << a << endl;
			return 0;
		}
	}
	return 0;
}
```

### 3. 收件邮箱
#### 题目描述

已知字符串str，str表示邮箱的不标准格式。 其中”.”会被记录成”dot”，”@”记录成”at”。 写一个程序将str转化成可用
的邮箱格式。(可用格式中字符串中除了开头结尾所有”dot”,都会被转换,”at”只会被转化一次，开头结尾的不转化)

#### 解题思路

*-这道题题目描述真的好含糊*

解题思路就是按要求进行特判+特判

#### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	string s2;
	for (size_t i = 0; i < s.size(); i++) {
		if (i > 0 && i + 2 < s.size() - 1 && s[i] == 'd' && s[i + 1] == 'o' && s[i + 2] == 't') {
			s2 += '.';
			i += 2;
		}
		else {
			s2 += s[i];
		}
	}
	s = s2;
	bool already = false;
	s2 = "";
	for (size_t i = 0; i < s.size(); i++) {
		if (already) {
			s2 += s[i];
		}
		else {
			if (i > 0 && i + 1 < s.size() - 1 && s[i] == 'a' && s[i + 1] == 't') {
				s2 += '@';
				i += 1;
				already = true;
			}
			else {
				s2 += s[i];
			}
		}
	}
	cout << s2 << endl;
	return 0;
}
```

### 4. 最长递增的区间长度

#### 题目描述
给一个无序数组，求最长递增的区间长度。如：[5,2,3,8,1,9] 最长区间 2,3,8 长度为 3

#### 解题思路
模拟即可。如遇不递增，就更新最大值。
#### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 1;
	int thisAns = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] > a[i - 1]) {
			thisAns++;
		}
		else {
			ans = max(ans, thisAns);
			thisAns = 1;
		}
	}
	ans = max(ans, thisAns);
	cout << ans << endl;
	return 0;
}
```

## BUG反馈
最初成绩不能正确显示，但是最后这个BUG被修复了：[反馈链接](https://bbs.csdn.net/topics/608098305?#601784609)

![在这里插入图片描述](https://img-blog.csdnimg.cn/b852a1fb61304cdc9703bf069f022c23.png)
> 这道题我用Python提交没有全部通过，然后我用C++提交，全部通过了。
> 因此，最终成绩应该是100分，但是系统没有取最高成绩，也没有取最后一次提交的成绩（最后一次我使用C++通过了全部的测试样例），而是取了Python的最后一次提交


## 资料分享
> 分享某刷题博主的博客：[CSDN@Tisfy](https://letmefly.blog.csdn.net/)

## 后记
<small>说实话，线上IDE体验挺不好的```~_~```</small>
