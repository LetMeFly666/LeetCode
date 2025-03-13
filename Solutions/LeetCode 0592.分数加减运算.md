---
title: 592.分数加减运算
date: 2022-07-27 11:17:02
tags: [题解, LeetCode, 中等, 数学, 字符串, 模拟, 重载]
categories: [题解, LeetCode]
---

# 【LetMeFly】592.分数加减运算：手把手分步のC++讲解

力扣题目链接：[https://leetcode.cn/problems/fraction-addition-and-subtraction/](https://leetcode.cn/problems/fraction-addition-and-subtraction/)

<p>给定一个表示分数加减运算的字符串&nbsp;<code>expression</code>&nbsp;，你需要返回一个字符串形式的计算结果。&nbsp;</p>

<p>这个结果应该是不可约分的分数，即<a href="https://baike.baidu.com/item/%E6%9C%80%E7%AE%80%E5%88%86%E6%95%B0" target="_blank">最简分数</a>。&nbsp;如果最终结果是一个整数，例如&nbsp;<code>2</code>，你需要将它转换成分数形式，其分母为&nbsp;<code>1</code>。所以在上述例子中, <code>2</code>&nbsp;应该被转换为&nbsp;<code>2/1</code>。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre>
<strong>输入:</strong>&nbsp;<code>expression</code>&nbsp;= "-1/2+1/2"
<strong>输出:</strong> "0/1"
</pre>

<p><strong>&nbsp;示例 2:</strong></p>

<pre>
<strong>输入:</strong>&nbsp;<code>expression</code>&nbsp;= "-1/2+1/2+1/3"
<strong>输出:</strong> "1/3"
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong>&nbsp;<code>expression</code>&nbsp;= "1/3-1/2"
<strong>输出:</strong> "-1/6"
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li>输入和输出字符串只包含&nbsp;<code>'0'</code> 到&nbsp;<code>'9'</code>&nbsp;的数字，以及&nbsp;<code>'/'</code>, <code>'+'</code> 和&nbsp;<code>'-'</code>。&nbsp;</li>
	<li>输入和输出分数格式均为&nbsp;<code>±分子/分母</code>。如果输入的第一个分数或者输出的分数是正数，则&nbsp;<code>'+'</code>&nbsp;会被省略掉。</li>
	<li>输入只包含合法的<strong>最简分数</strong>，每个分数的<strong>分子</strong>与<strong>分母</strong>的范围是&nbsp;&nbsp;[1,10]。&nbsp;如果分母是1，意味着这个分数实际上是一个整数。</li>
	<li>输入的分数个数范围是 [1,10]。</li>
	<li><strong>最终结果</strong>的分子与分母保证是 32 位整数范围内的有效整数。</li>
</ul>


    
## 方法一：C++模拟

用```pair<int, int>```表示分数，然后不断模拟即可。

主要需要实现三个功能：

1. **字符串转分数**
    字符串转分数稍微复杂一些。
    首先根据字符串的首个字符判断分数的正负，然后计算分子和分母分别对应字符串中的哪几个字符，最后再把字符串转为int即可。
    ```cpp
    pii string2fraction(string s) {
		pii ans;
		// 判断分数的正负
		if (s[0] == '-') {
			ans.first = -1;
		}
		else {
			ans.first = 1;
		}
		// 计算分子开始位置的下标
		int l = 0;
		if (s[0] == '-' || s[0] == '+') {
			l++;
		}
		// 计算分子结束位置的下标
		int r = l;
		while (s[r] != '/')
			r++;
		// 计算分子分母
		ans.first *= atoi(s.substr(l, r - l).c_str());
		ans.second = atoi(s.substr(r + 1, s.size() - r -1).c_str());
		return ans;
	}
    ```
2. **两个分数相加**
    分数相加首先要通分。
	令新的分母为原本两个分数的最小公倍数，然后将两个分数的分子分别化为通分后的值并累加，最后进行约分即可。
	注意分子分母约分的时候，```__gcd()```函数调用时记得传入分子分母的绝对值，否则求得的最小公倍数可能会为负数。
	```cpp
    pii add(pii p1, pii p2) {
        pii ans;
        ans.second = p1.second * p2.second / __gcd(p1.second, p2.second);
        ans.first = p1.first * (ans.second / p1.second) + p2.first * (ans.second / p2.second);
        int gcd = __gcd(abs(ans.first), ans.second);
        ans.first /= gcd, ans.second /= gcd;
        return ans;
    }
	```
3. **将分数转为字符串**
	这个功能实现起来相对容易，只需要将分子分母分别转为字符串，并在中间加上```/```即可。
    ```cpp
    string fraction2string(pii f) {
        return to_string(f.first) + "/" + to_string(f.second);
    }
	```

实现了上述三个功能，只需要在主函数中对原始字符串按加减号进行分割，并把每个分割出来的分数的值累加即可。

```cpp
string fractionAddition(string expression) {
	pii ans = {0, 1};
	int last = 0;  // 上一个处理到的字符的位置
	for (int i = 1; i < expression.size(); i++) {
		if (expression[i] == '+' || expression[i] == '-') {  // 遇到加减号就开始分割
			ans = add(ans, string2fraction(expression.substr(last, i - last)));
			last = i;
		}
	}
	ans = add(ans, string2fraction(expression.substr(last, expression.size() - last)));  // 注意字符串末尾没有加减号，不要把最后一个分数遗漏了。
	return fraction2string(ans);
}
```

**拓展：**

如果想要```debug```分数长啥样，可以直接重载运算符```<<```

```cpp
ostream &operator << (ostream& out, pii& p) {
    out << p.first << "/" << p.second;
    return out;
}
```

这样，当想要```debug```时，就可以直接

```cpp
pair<int, int> fraction = {1, 2};
cout << fraction << endl;
```

了。

+ 时间复杂度$O(n)$，其中$n$是字符串长度
+ 空间复杂度$O(m)$，其中$m$是一个分数的字符串的平均长度

### AC代码

#### C++

```cpp
typedef pair<int, int> pii;

ostream &operator << (ostream& out, pii& p) {
    out << p.first << "/" << p.second;
    return out;
}

class Solution {
private:
    pii string2fraction(string s) {
        pii ans;
        if (s[0] == '-') {
            ans.first = -1;
        }
        else {
            ans.first = 1;
        }
        int l = 0;
        if (s[0] == '-' || s[0] == '+') {
            l++;
        }
        int r = l;
        while (s[r] != '/')
            r++;
        ans.first *= atoi(s.substr(l, r - l).c_str());
        ans.second = atoi(s.substr(r + 1, s.size() - r - 1).c_str());

        // cout << s << " -> " << ans << endl;

        return ans;
    }

    pii add(pii p1, pii p2) {
        pii ans;
        ans.second = p1.second * p2.second / __gcd(p1.second, p2.second);
        ans.first = p1.first * (ans.second / p1.second) + p2.first * (ans.second / p2.second);
        int gcd = __gcd(abs(ans.first), ans.second);
        ans.first /= gcd, ans.second /= gcd;
        return ans;
    }

    string fraction2string(pii f) {
        return to_string(f.first) + "/" + to_string(f.second);
    }
public:
    string fractionAddition(string expression) {
        pii ans = {0, 1};
        int last = 0;
        for (int i = 1; i < expression.size(); i++) {
            if (expression[i] == '+' || expression[i] == '-') {
                ans = add(ans, string2fraction(expression.substr(last, i - last)));
                last = i;
            }
        }
        ans = add(ans, string2fraction(expression.substr(last, expression.size() - last)));
        return fraction2string(ans);
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/27/LeetCode%200592.%E5%88%86%E6%95%B0%E5%8A%A0%E5%87%8F%E8%BF%90%E7%AE%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126011320](https://letmefly.blog.csdn.net/article/details/126011320)
