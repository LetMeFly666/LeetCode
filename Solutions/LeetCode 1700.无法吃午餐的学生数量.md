---
title: 1700.无法吃午餐的学生数量
date: 2022-10-19 09:52:09
tags: [题解, LeetCode, 简单, 栈, 队列, 数组, 模拟]
---

# 【LetMeFly】1700.无法吃午餐的学生数量：真假模拟（极简代码） + 奇技淫巧

力扣题目链接：[https://leetcode.cn/problems/number-of-students-unable-to-eat-lunch/](https://leetcode.cn/problems/number-of-students-unable-to-eat-lunch/)

<p>学校的自助午餐提供圆形和方形的三明治，分别用数字 <code>0</code> 和 <code>1</code> 表示。所有学生站在一个队列里，每个学生要么喜欢圆形的要么喜欢方形的。<br>
餐厅里三明治的数量与学生的数量相同。所有三明治都放在一个 <strong>栈</strong> 里，每一轮：</p>

<ul>
	<li>如果队列最前面的学生 <strong>喜欢</strong> 栈顶的三明治，那么会 <strong>拿走它</strong> 并离开队列。</li>
	<li>否则，这名学生会 <strong>放弃这个三明治</strong> 并回到队列的尾部。</li>
</ul>

<p>这个过程会一直持续到队列里所有学生都不喜欢栈顶的三明治为止。</p>

<p>给你两个整数数组 <code>students</code> 和 <code>sandwiches</code> ，其中 <code>sandwiches[i]</code> 是栈里面第 <code>i<sup>​​​​​​</sup></code> 个三明治的类型（<code>i = 0</code> 是栈的顶部）， <code>students[j]</code> 是初始队列里第 <code>j<sup>​​​​​​</sup></code> 名学生对三明治的喜好（<code>j = 0</code> 是队列的最开始位置）。请你返回无法吃午餐的学生数量。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>students = [1,1,0,0], sandwiches = [0,1,0,1]
<b>输出：</b>0<strong> 
解释：</strong>
- 最前面的学生放弃最顶上的三明治，并回到队列的末尾，学生队列变为 students = [1,0,0,1]。
- 最前面的学生放弃最顶上的三明治，并回到队列的末尾，学生队列变为 students = [0,0,1,1]。
- 最前面的学生拿走最顶上的三明治，剩余学生队列为 students = [0,1,1]，三明治栈为 sandwiches = [1,0,1]。
- 最前面的学生放弃最顶上的三明治，并回到队列的末尾，学生队列变为 students = [1,1,0]。
- 最前面的学生拿走最顶上的三明治，剩余学生队列为 students = [1,0]，三明治栈为 sandwiches = [0,1]。
- 最前面的学生放弃最顶上的三明治，并回到队列的末尾，学生队列变为 students = [0,1]。
- 最前面的学生拿走最顶上的三明治，剩余学生队列为 students = [1]，三明治栈为 sandwiches = [1]。
- 最前面的学生拿走最顶上的三明治，剩余学生队列为 students = []，三明治栈为 sandwiches = []。
所以所有学生都有三明治吃。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
<b>输出：</b>3
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= students.length, sandwiches.length &lt;= 100</code></li>
	<li><code>students.length == sandwiches.length</code></li>
	<li><code>sandwiches[i]</code> 要么是 <code>0</code> ，要么是 <code>1</code> 。</li>
	<li><code>students[i]</code> 要么是 <code>0</code> ，要么是 <code>1</code> 。</li>
</ul>


    
## 方法一：真模拟

真模拟就是真的按照题意，将```students```变成队列，```sandwich```变成栈

然后每次从头到尾依次出队，遇到与栈顶元素相同的就“走人”

所有同学都出队过一次也没有匹配到三明治的话，谁都吃不到了，就返回剩余学生的数量。

+ 时间复杂度$O(n^2)$，其中$n$是学生个数。（其实遍历不了这么多）
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for (int& t : students) {
            q.push(t);
        }
        stack<int> st;
        for (int i = sandwiches.size() - 1; i >= 0; i--) {
            st.push(sandwiches[i]);
        }
        while (true) {
            int thisSandwich = st.top();
            st.pop();
            bool found = false;
            for (int i = q.size(); i > 0; i--) {
                int thisStudent = q.front();
                q.pop();
                if (thisStudent == thisSandwich) {
                    found = true;
                    break;
                }
                else {
                    q.push(thisStudent);
                }
            }
            if (!found) {
                return q.size();
            }
            else if (q.empty()) {
                return 0;
            }
        }
        return -1;  // Fake Return
    }
};
```

## 方法二：假模拟

真的要学生一个一个地出队入队吗？

当然不！假如栈顶三明治是```1```，那么只要队列中存在```1```就能匹配上啊

谁先匹配上的不影响结果。

除非剩下学生全是```0```😉，那所有人都吃不到了。

**打住**，刚刚说什么，“剩下学生全是```0```”？

哦哦，这不就是**终止条件**嘛！

我们只需要从前到后遍历三明治（模拟出栈的过程），如果有学生与这个三明治匹配，那就拿走去吃，否则（所有学生与三明治都不匹配），模拟终止，谁都吃不到了~~（论```1```的重要性）~~

如果三明治遍历完了，那就说明所有同学都吃到了，那就返回```0```

+ 时间复杂度$O(n)$，其中$n$是学生个数
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // s[0]代表学生中0的数量，s[1]代表学生中1的数量
        int s[2] = {(int)count(students.begin(), students.end(), 0), (int)students.size() - s[0]};
        // cout << s[0] << ' ' << s[1] << endl;
        for (int& t : sandwiches) {
            if (s[t])  // 匹配
                s[t]--;  // 走人
            else  // 无人可匹
                return s[0] + s[1];  // 谁都别想吃了
        }
        return 0;
    }
};
```

**注意**，这里是```学生0```和```三明治0```匹配，不是```0```和```1```匹配。

**代码简化**（行数压缩）

```cpp
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int s[2] = {(int)count(students.begin(), students.end(), 0), (int)students.size() - s[0]};
        for (int& t : sandwiches)
            if (s[t]) s[t]--;
            else return s[0] + s[1];
        return 0;
    }
};
```

## 方法三：奇技淫巧 - 计时器

方法三对应于方法一，也是真模拟。

不同之处在于方法一中，我们需要判断“是否所有学生都出队过一次”

不同的是，方法三中，没有对此进行判断，而是当没有学生能与栈顶三明治匹配时，不断地进行“出队入队出队入队出队入队...”

直到把学生累死，查看尸体个数就行了。

怎么累死呢？

我们在程序中设置一个计时器，对于```100```个学生这种数量级，一般几毫秒就能模拟完。（我们把几毫秒看成是“午饭时间30min”）

那么好，我们执行个“1000毫秒”，1000ms / 5ms * 30min = 60,000min = 1000h = 41.666...天

让所有学生不吃一口三明治不断排队40多天，肯定累死了。

那么，**剩下的学生就是答案**。

+ 时间复杂度：不易衡量。如果所有学生都能吃完，那么就是$O(n^2)$，其中$n$是学生个数；如果有学生不能吃到，那程序就会执行大约```1秒```
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
		// 构建队列和栈
        queue<int> q;
        for (int& t : students) {
            q.push(t);
        }
        stack<int> st;
        for (int i = sandwiches.size() - 1; i >= 0; i--) {
            st.push(sandwiches[i]);
        }
		开始模拟
        time_t start = clock();
        while (clock() - start < 1000 && q.size()) {
            if (q.front() == st.top())
                q.pop(), st.pop();
            else {
                int thisStudent = q.front();
                q.pop();
                q.push(thisStudent);
            }
        }
        return q.size();
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/10/19/LeetCode%201700.%E6%97%A0%E6%B3%95%E5%90%83%E5%8D%88%E9%A4%90%E7%9A%84%E5%AD%A6%E7%94%9F%E6%95%B0%E9%87%8F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127402719](https://letmefly.blog.csdn.net/article/details/127402719)
