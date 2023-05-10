---
title: 157.用Read4读取N个字符
date: 2022-05-29 13:56:48
tags: [题解, LeetCode, 简单, 字符串, 交互, 模拟]
---

# 【LetMeFly】157.用Read4读取N个字符

给你一个文件，并且该文件只能通过给定的 ```read4``` 方法来读取，请实现一个方法使其能够读取 ```n``` 个字符。

**read4 方法：**

API ```read4``` 可以从文件中读取 4 个连续的字符，并且将它们写入缓存数组 ```buf``` 中。

返回值为实际读取的字符个数。

注意 ```read4()``` 自身拥有文件指针，很类似于 C 语言中的 ```FILE *fp``` 。

**read4 的定义：**

```
参数类型: char[] buf4
返回类型: int

注意: buf4[] 是目标缓存区不是源缓存区，read4 的返回结果将会复制到 buf4[] 当中。
```

下列是一些使用 ```read4``` 的例子：

```
File file("abcde"); // 文件名为 "abcde"， 初始文件指针 (fp) 指向 'a' 
char[] buf4 = new char[4]; // 创建一个缓存区使其能容纳足够的字符
read4(buf4); // read4 返回 4。现在 buf4 = "abcd"，fp 指向 'e'
read4(buf4); // read4 返回 1。现在 buf4 = "e"，fp 指向文件末尾
read4(buf4); // read4 返回 0。现在 buf = ""，fp 指向文件末尾
```

**read 方法：**

通过使用 ```read4``` 方法，实现 ```read``` 方法。该方法可以从文件中读取 n 个字符并将其存储到缓存数组 ```buf``` 中。您 **不能** 直接操作文件。

返回值为实际读取的字符。

**read 的定义：**

```
参数类型:   char[] buf, int n
返回类型:   int

注意: buf[] 是目标缓存区不是源缓存区，你需要将结果写入 buf[] 中。
```

**示例 1:**

```
输入： file = "abc", n = 4
输出： 3
解释： 当执行你的 read 方法后，buf 需要包含 "abc"。 文件一共 3 个字符，因此返回 3。 注意 "abc" 是文件的内容，不是 buf 的内容，buf 是你需要写入结果的目标缓存区。 
```

**示例 2:**

```
输入： file = "abcde", n = 5
输出： 5
解释： 当执行你的 read 方法后，buf 需要包含 "abcde"。文件共 5 个字符，因此返回 5。
```

**示例 3:**

```
输入： file = "abcdABCD1234", n = 12
输出： 12
解释： 当执行你的 read 方法后，buf 需要包含 "abcdABCD1234"。文件一共 12 个字符，因此返回 12。
```

**示例 4:**

```
输入： file = "leetcode", n = 5
输出： 5
解释： 当执行你的 read 方法后，buf 需要包含 "leetc"。文件中一共 5 个字符，因此返回 5。
```

**提示:**

+ 你 **不能** 直接操作该文件，文件只能通过 ```read4``` 获取而 **不能** 通过 ```read```。
+ ```read```  函数只在每个测试用例调用一次。
+ 你可以假定目标缓存数组 ```buf``` 保证有足够的空间存下 n 个字符。 

# 题目大意

```int read4(char* buf)```函数的作用是从字符串缓冲区读取4个字符（当字符数量小于4个时读取全部的字符）

```int read(char* buf, int n)```函数的作用是从字符缓冲区读取n个字符（当字符数量小于n个时读取全部的字符）

现在已经实现好了```read4```函数，让你用```read4```函数来实现```read```函数。

# 思路

在读取字符数量不足$n$时，我们可以一直尝试读取（每次读取4个字符），直到“无字符可读”或“读够n个字符”为止。

同时，因为我们要把字符全部读入到```buf```中，所以每次读取4个字符的时候，存放的起始位置不同。

假如某次读取完$4$个字符后字符数量超过了$n$，那就把多读入的字符抹去即可（变成```\0```）。

## 方法一：模拟

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int ans = 0;
        int thisNum;
        while (thisNum = read4(buf + ans)) {
            ans += thisNum;
            if (ans >= n) {
                while (ans > n) {
                    *(buf + --ans) = '\0';
                }
                break;
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/05/29/LeetCode%200157.%E7%94%A8Read4%E8%AF%BB%E5%8F%96N%E4%B8%AA%E5%AD%97%E7%AC%A6)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125030886](https://letmefly.blog.csdn.net/article/details/125030886)
