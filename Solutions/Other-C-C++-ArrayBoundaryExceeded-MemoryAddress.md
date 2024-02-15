---
title: C(C++)数组越界但能正常运行？关于数组越界和变量内存地址的一点研究：何时地址连续
date: 2023-12-27 21:29:48
tags: [C++, 简单, 数组越界]
---

# C(C&#43;&#43;)数组越界但能正常运行？关于数组越界和变量内存地址的一点研究：何时地址连续

## 前言

今天美丽的本科同班同学[xyy](https://www.luogu.com.cn/user/870958)问了我一个问题：

她出了一道C++基础题：

> 第一行输入一个正整数$n$（$1\leq n\leq 100$），第二行输入空格隔开的$n$个正整数（$1$到$10000$），第三行输入空格隔开的两个正整数$x$和$y$（$1\leq x, y\leq n$），按顺序输出这$n$个数中将第$x$个数修改为$y$后的结果（输出一行且用空格隔开）

出这道题的目的之一是考察C++等编程语言的数组越界问题。$n$的最大值是$100$，如果开辟一个大小为$100$的数组$a$，并且从下标$1$开始存数据，则$a[100]$会发生数组越界。

测试数据中存在$n=100$的数据，题目出在了洛谷上，但是对于以下代码，能正常AC本题：

```cpp
#include <bits/stdc++.h>
using namespace std;
int a[1];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int x, y;
    cin >> x >> y;
    a[x] = y;
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
```

于是我就开启了对这个“越界但能正常运行”的问题进行了研究。

## 本地运行尝试

现在本地运行了上述代码（开了个全局变量$a[1]$）：

```bash
g++ xieyingying.cpp -o xieyingying.exe
./xieyingying.exe
5
1 2 3 4 5
4 100
```

运行结果：

```
1 2 3 100 5
```

一切正常！第$4$个元素被替换成了$100$，其他元素没有变化。

## 获取元素的内存地址

将上述代码添加几行

```cpp
cout << &a << " - " << &a[100] << endl;
cout << &n << ", " << &x << ", " << & y << endl;
```

获取元素在内存中的地址：

```cpp
#include <bits/stdc++.h>
using namespace std;
int a[1];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int x, y;
    cin >> x >> y;
    cout << &a << " - " << &a[100] << endl;
    cout << &n << ", " << &x << ", " << & y << endl;
    a[x] = y;
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
```

运行以下命令：

```bash
g++ xieyingying.cpp -o xieyingying.exe
./xieyingying.exe
5
1 2 3 4 5
4 100
```

得到结果：

```
0x407030 - 0x4071c0
0x61fe14, 0x61fe10, 0x61fe0c
1 2 3 100 5
```

可见，其实数组$a$的地址和$n$、$x$、$y$的地址并不连续。$n$、$x$、$y$的地址是连续的，而和$a$相差很远。并且恰好没有其他操作使用了$a + 1$到$a + 100$对应的内存空间，因此结果正确。

**这是因为全局变量和局部变量的地址分配不在一个区中。**

## 研究何时越界会有影响

如果我将代码修改一下，将数组$a$变成局部变量：

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[1];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int x, y;
    cin >> x >> y;
    cout << &a << " - " << &a[100] << endl;
    cout << &n << ", " << &x << ", " << & y << endl;
    a[x] = y;
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
```

运行以下命令：

```bash
g++ xieyingying2.cpp -o xieyingying2.exe
./xieyingying2.exe
5
1 2 3 4 5
4 100
```

得到结果：

```
0x61fe14 - 0x61ffa4
0x61fe10, 0x61fe0c, 0x61fe08
1 6 3 100 5
```

嘿嘿，内存空间一连续，答案不对了吧。

其实第一版代码，如果后续操作过多，“数组中”元素也会有概率被修改的。

但是你看，我是一个出题者，出了一道题在洛谷上，我没办法修改编译选项（如开启ASAN），也没办法限制用户：不许将数组开到全局变量而其他元素开到局部变量。那么怎么办才好呢？

## 一个比较可行的让不注意选手 答案错误 的方式

我能想到的办法只有修改题目了。毕竟主要是在考“数组越界”，因此可以将题目修改为：

> 第一行输入一个正整数$n$（$1\leq n\leq 100$），第二行输入空格隔开的$n$个正整数（$1$到$10000$）代表数组$a$中的元素，第三行输入空格隔开的$n$个正整数（$1$到$10000$）代表数组$b$中的元素，第四行输入空格隔开的两个正整数$x$和$y$（$1\leq x, y\leq n$），交换$a[x]$和$b[y]$，并按顺序输出数组$a$和数组$b$中的元素（每个输出一行且用不用元素之间用空格隔开）

也就是说，现在有两个数组$a$和$b$，一般人不会把这两个数组一个开到全局一个开到局部吧。假设这两个数组开到了一个位置，那么不管是全局还是局部，都会冲突。

为了易读性，假设$n$的范围是$1$到$5$，对于以下代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
int a[5];
int b[5];
int main() {
    cout << &a << " - " << &a[5] << endl;
    cout << &b << " - " << &b[5] << endl;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >>b[i];
    }
    int x, y;
    cin >> x >> y;
    swap(a[x], b[y]);
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
    return 0;
}
```

运行以下命令：

```bash
g++ xieyingying.cpp -o xieyingying.exe
./xieyingying.exe
5
1 2 3 4 5
100 200 300 400 500
2 4
```

运行结果：

```
0x407030 - 0x407044
0x407050 - 0x407064
1 400 3 4 5 100 200 300 2 500 
```

纳尼，结果仍然正确？虽然数组$a$后立刻开辟了数组$b$并且它们的大小都为$5$，但是$a[5]$地址仍不等于$b$的地址？？？

## 何时内存地址连续？

尝试使用以下代码来获取数组在内存中的地址：

```cpp
#include <bits/stdc++.h>
using namespace std;

#define SIZE 100
int a[SIZE], b[SIZE];
int main() {
    cout << &a << " - " << &a[SIZE] << endl;
    cout << &b << " - " << &b[SIZE] << endl;
    return 0;
}
```

执行以下命令：

```bash
g++ xieyingying4.cpp -o xieyingying4.exe
./xieyingying4.exe
```

得到结果：

```
0x407040 - 0x4071d0
0x4071e0 - 0x407370
```

可见```0x4071d0```不等于```0x4071e0```，内存仍不连续。

接下来将```SIZE```修改为```1```、```2```、...，发现有时候数组地址是连续的，有时候是不连续的。

**写个脚本判断数组大小为1到128时何时连续：**

```python
import os

for i in range(1, 128 + 1):
    source = """
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define SIZE """ + str(i) + """
int a[SIZE], b[SIZE];
int main() {
    cout << &a << " - " << &a[SIZE] << " | ";
    cout << &b << " - " << &b[SIZE] << " | ";
    cout << ((ll)&a[SIZE] == (ll)&b);
    return 0;
}
"""
    with open('source.cpp', 'w', encoding='utf-8') as f:
        f.write(source)
    os.system('g++ source.cpp -o source.exe')
    exe = os.popen('source.exe')
    result = exe.read()
    ifSame = result[-1] == '1'
    print(f'i = {i}({"same" if ifSame else "different"}): {result}')
```

执行后可以得到结果：

```
i = 1(same): 0x407030 - 0x407034 | 0x407034 - 0x407038 | 1
i = 2(same): 0x407030 - 0x407038 | 0x407038 - 0x407040 | 1
i = 3(different): 0x407030 - 0x40703c | 0x407040 - 0x40704c | 0
i = 4(same): 0x407030 - 0x407040 | 0x407040 - 0x407050 | 1
i = 5(different): 0x407030 - 0x407044 | 0x407050 - 0x407064 | 0
i = 6(different): 0x407030 - 0x407048 | 0x407050 - 0x407068 | 0
i = 8(same): 0x407040 - 0x407060 | 0x407060 - 0x407080 | 1
i = 9(different): 0x407040 - 0x407064 | 0x407080 - 0x4070a4 | 0
i = 10(different): 0x407040 - 0x407068 | 0x407080 - 0x4070a8 | 0
i = 11(different): 0x407040 - 0x40706c | 0x407080 - 0x4070ac | 0
i = 12(different): 0x407040 - 0x407070 | 0x407080 - 0x4070b0 | 0
i = 13(different): 0x407040 - 0x407074 | 0x407080 - 0x4070b4 | 0
i = 14(different): 0x407040 - 0x407078 | 0x407080 - 0x4070b8 | 0
i = 15(different): 0x407040 - 0x40707c | 0x407080 - 0x4070bc | 0
i = 16(same): 0x407040 - 0x407080 | 0x407080 - 0x4070c0 | 1
i = 17(different): 0x407040 - 0x407084 | 0x4070a0 - 0x4070e4 | 0
i = 18(different): 0x407040 - 0x407088 | 0x4070a0 - 0x4070e8 | 0
i = 19(different): 0x407040 - 0x40708c | 0x4070a0 - 0x4070ec | 0
i = 20(different): 0x407040 - 0x407090 | 0x4070a0 - 0x4070f0 | 0
i = 21(different): 0x407040 - 0x407094 | 0x4070a0 - 0x4070f4 | 0
i = 22(different): 0x407040 - 0x407098 | 0x4070a0 - 0x4070f8 | 0
i = 23(different): 0x407040 - 0x40709c | 0x4070a0 - 0x4070fc | 0
i = 24(same): 0x407040 - 0x4070a0 | 0x4070a0 - 0x407100 | 1
i = 25(different): 0x407040 - 0x4070a4 | 0x4070c0 - 0x407124 | 0
i = 26(different): 0x407040 - 0x4070a8 | 0x4070c0 - 0x407128 | 0
i = 27(different): 0x407040 - 0x4070ac | 0x4070c0 - 0x40712c | 0
i = 28(different): 0x407040 - 0x4070b0 | 0x4070c0 - 0x407130 | 0
i = 29(different): 0x407040 - 0x4070b4 | 0x4070c0 - 0x407134 | 0
i = 30(different): 0x407040 - 0x4070b8 | 0x4070c0 - 0x407138 | 0
i = 31(different): 0x407040 - 0x4070bc | 0x4070c0 - 0x40713c | 0
i = 32(same): 0x407040 - 0x4070c0 | 0x4070c0 - 0x407140 | 1
i = 33(different): 0x407040 - 0x4070c4 | 0x4070e0 - 0x407164 | 0
i = 34(different): 0x407040 - 0x4070c8 | 0x4070e0 - 0x407168 | 0
i = 35(different): 0x407040 - 0x4070cc | 0x4070e0 - 0x40716c | 0
i = 36(different): 0x407040 - 0x4070d0 | 0x4070e0 - 0x407170 | 0
i = 37(different): 0x407040 - 0x4070d4 | 0x4070e0 - 0x407174 | 0
i = 38(different): 0x407040 - 0x4070d8 | 0x4070e0 - 0x407178 | 0
i = 39(different): 0x407040 - 0x4070dc | 0x4070e0 - 0x40717c | 0
i = 40(same): 0x407040 - 0x4070e0 | 0x4070e0 - 0x407180 | 1
i = 41(different): 0x407040 - 0x4070e4 | 0x407100 - 0x4071a4 | 0
i = 42(different): 0x407040 - 0x4070e8 | 0x407100 - 0x4071a8 | 0
i = 43(different): 0x407040 - 0x4070ec | 0x407100 - 0x4071ac | 0
i = 44(different): 0x407040 - 0x4070f0 | 0x407100 - 0x4071b0 | 0
i = 45(different): 0x407040 - 0x4070f4 | 0x407100 - 0x4071b4 | 0
i = 46(different): 0x407040 - 0x4070f8 | 0x407100 - 0x4071b8 | 0
i = 47(different): 0x407040 - 0x4070fc | 0x407100 - 0x4071bc | 0
i = 48(same): 0x407040 - 0x407100 | 0x407100 - 0x4071c0 | 1
i = 49(different): 0x407040 - 0x407104 | 0x407120 - 0x4071e4 | 0
i = 50(different): 0x407040 - 0x407108 | 0x407120 - 0x4071e8 | 0
i = 51(different): 0x407040 - 0x40710c | 0x407120 - 0x4071ec | 0
i = 52(different): 0x407040 - 0x407110 | 0x407120 - 0x4071f0 | 0
i = 53(different): 0x407040 - 0x407114 | 0x407120 - 0x4071f4 | 0
i = 54(different): 0x407040 - 0x407118 | 0x407120 - 0x4071f8 | 0
i = 55(different): 0x407040 - 0x40711c | 0x407120 - 0x4071fc | 0
i = 56(same): 0x407040 - 0x407120 | 0x407120 - 0x407200 | 1
i = 57(different): 0x407040 - 0x407124 | 0x407140 - 0x407224 | 0
i = 58(different): 0x407040 - 0x407128 | 0x407140 - 0x407228 | 0
i = 59(different): 0x407040 - 0x40712c | 0x407140 - 0x40722c | 0
i = 60(different): 0x407040 - 0x407130 | 0x407140 - 0x407230 | 0
i = 61(different): 0x407040 - 0x407134 | 0x407140 - 0x407234 | 0
i = 62(different): 0x407040 - 0x407138 | 0x407140 - 0x407238 | 0
i = 63(different): 0x407040 - 0x40713c | 0x407140 - 0x40723c | 0
i = 64(same): 0x407040 - 0x407140 | 0x407140 - 0x407240 | 1
i = 65(different): 0x407040 - 0x407144 | 0x407160 - 0x407264 | 0
i = 66(different): 0x407040 - 0x407148 | 0x407160 - 0x407268 | 0
i = 67(different): 0x407040 - 0x40714c | 0x407160 - 0x40726c | 0
i = 68(different): 0x407040 - 0x407150 | 0x407160 - 0x407270 | 0
i = 69(different): 0x407040 - 0x407154 | 0x407160 - 0x407274 | 0
i = 70(different): 0x407040 - 0x407158 | 0x407160 - 0x407278 | 0
i = 71(different): 0x407040 - 0x40715c | 0x407160 - 0x40727c | 0
i = 72(same): 0x407040 - 0x407160 | 0x407160 - 0x407280 | 1
i = 73(different): 0x407040 - 0x407164 | 0x407180 - 0x4072a4 | 0
i = 74(different): 0x407040 - 0x407168 | 0x407180 - 0x4072a8 | 0
i = 75(different): 0x407040 - 0x40716c | 0x407180 - 0x4072ac | 0
i = 76(different): 0x407040 - 0x407170 | 0x407180 - 0x4072b0 | 0
i = 77(different): 0x407040 - 0x407174 | 0x407180 - 0x4072b4 | 0
i = 78(different): 0x407040 - 0x407178 | 0x407180 - 0x4072b8 | 0
i = 79(different): 0x407040 - 0x40717c | 0x407180 - 0x4072bc | 0
i = 80(same): 0x407040 - 0x407180 | 0x407180 - 0x4072c0 | 1
i = 81(different): 0x407040 - 0x407184 | 0x4071a0 - 0x4072e4 | 0
i = 82(different): 0x407040 - 0x407188 | 0x4071a0 - 0x4072e8 | 0
i = 83(different): 0x407040 - 0x40718c | 0x4071a0 - 0x4072ec | 0
i = 84(different): 0x407040 - 0x407190 | 0x4071a0 - 0x4072f0 | 0
i = 85(different): 0x407040 - 0x407194 | 0x4071a0 - 0x4072f4 | 0
i = 86(different): 0x407040 - 0x407198 | 0x4071a0 - 0x4072f8 | 0
i = 87(different): 0x407040 - 0x40719c | 0x4071a0 - 0x4072fc | 0
i = 88(same): 0x407040 - 0x4071a0 | 0x4071a0 - 0x407300 | 1
i = 89(different): 0x407040 - 0x4071a4 | 0x4071c0 - 0x407324 | 0
i = 90(different): 0x407040 - 0x4071a8 | 0x4071c0 - 0x407328 | 0
i = 91(different): 0x407040 - 0x4071ac | 0x4071c0 - 0x40732c | 0
i = 92(different): 0x407040 - 0x4071b0 | 0x4071c0 - 0x407330 | 0
i = 93(different): 0x407040 - 0x4071b4 | 0x4071c0 - 0x407334 | 0
i = 94(different): 0x407040 - 0x4071b8 | 0x4071c0 - 0x407338 | 0
i = 95(different): 0x407040 - 0x4071bc | 0x4071c0 - 0x40733c | 0
i = 96(same): 0x407040 - 0x4071c0 | 0x4071c0 - 0x407340 | 1
i = 97(different): 0x407040 - 0x4071c4 | 0x4071e0 - 0x407364 | 0
i = 98(different): 0x407040 - 0x4071c8 | 0x4071e0 - 0x407368 | 0
i = 99(different): 0x407040 - 0x4071cc | 0x4071e0 - 0x40736c | 0
i = 100(different): 0x407040 - 0x4071d0 | 0x4071e0 - 0x407370 | 0
i = 101(different): 0x407040 - 0x4071d4 | 0x4071e0 - 0x407374 | 0
i = 102(different): 0x407040 - 0x4071d8 | 0x4071e0 - 0x407378 | 0
i = 103(different): 0x407040 - 0x4071dc | 0x4071e0 - 0x40737c | 0
i = 104(same): 0x407040 - 0x4071e0 | 0x4071e0 - 0x407380 | 1
i = 105(different): 0x407040 - 0x4071e4 | 0x407200 - 0x4073a4 | 0
i = 106(different): 0x407040 - 0x4071e8 | 0x407200 - 0x4073a8 | 0
i = 107(different): 0x407040 - 0x4071ec | 0x407200 - 0x4073ac | 0
i = 108(different): 0x407040 - 0x4071f0 | 0x407200 - 0x4073b0 | 0
i = 109(different): 0x407040 - 0x4071f4 | 0x407200 - 0x4073b4 | 0
i = 110(different): 0x407040 - 0x4071f8 | 0x407200 - 0x4073b8 | 0
i = 111(different): 0x407040 - 0x4071fc | 0x407200 - 0x4073bc | 0
i = 112(same): 0x407040 - 0x407200 | 0x407200 - 0x4073c0 | 1
i = 113(different): 0x407040 - 0x407204 | 0x407220 - 0x4073e4 | 0
i = 114(different): 0x407040 - 0x407208 | 0x407220 - 0x4073e8 | 0
i = 115(different): 0x407040 - 0x40720c | 0x407220 - 0x4073ec | 0
i = 116(different): 0x407040 - 0x407210 | 0x407220 - 0x4073f0 | 0
i = 117(different): 0x407040 - 0x407214 | 0x407220 - 0x4073f4 | 0
i = 118(different): 0x407040 - 0x407218 | 0x407220 - 0x4073f8 | 0
i = 119(different): 0x407040 - 0x40721c | 0x407220 - 0x4073fc | 0
i = 120(same): 0x407040 - 0x407220 | 0x407220 - 0x407400 | 1
i = 121(different): 0x407040 - 0x407224 | 0x407240 - 0x407424 | 0
i = 122(different): 0x407040 - 0x407228 | 0x407240 - 0x407428 | 0
i = 123(different): 0x407040 - 0x40722c | 0x407240 - 0x40742c | 0
i = 124(different): 0x407040 - 0x407230 | 0x407240 - 0x407430 | 0
i = 125(different): 0x407040 - 0x407234 | 0x407240 - 0x407434 | 0
i = 126(different): 0x407040 - 0x407238 | 0x407240 - 0x407438 | 0
i = 127(different): 0x407040 - 0x40723c | 0x407240 - 0x40743c | 0
i = 128(same): 0x407040 - 0x407240 | 0x407240 - 0x407440 | 1
```

可以发现：

**在全局变量中连续开辟两个大小相同的数组，当数组大小SIZE满足以下条件时，两个数组的内存地址连续：**

$$
\begin{cases}
  &SIZE\in\{1,2,4\} \text{ if } SIZE<8 \\
  &SIZE\in\{8k|k为整数\} \text{ if } 8\leq SIZE\leq 128
\end{cases}
$$

换一台机器（同为Win10）的执行结果也是一样的。

但是当我把数组$a$和数组$b$开到局部变量时，啊咧，全部不一样。。。

```
i = 1(different): 0x61fe1c - 0x61fe20 | 0x61fe18 - 0x61fe1c | 0
i = 2(different): 0x61fe18 - 0x61fe20 | 0x61fe10 - 0x61fe18 | 0
i = 3(different): 0x61fe14 - 0x61fe20 | 0x61fe08 - 0x61fe14 | 0
i = 4(different): 0x61fe10 - 0x61fe20 | 0x61fe00 - 0x61fe10 | 0
i = 5(different): 0x61fe00 - 0x61fe14 | 0x61fde0 - 0x61fdf4 | 0
i = 6(different): 0x61fe00 - 0x61fe18 | 0x61fde0 - 0x61fdf8 | 0
i = 7(different): 0x61fe00 - 0x61fe1c | 0x61fde0 - 0x61fdfc | 0
i = 8(different): 0x61fe00 - 0x61fe20 | 0x61fde0 - 0x61fe00 | 0
i = 9(different): 0x61fdf0 - 0x61fe14 | 0x61fdc0 - 0x61fde4 | 0
i = 10(different): 0x61fdf0 - 0x61fe18 | 0x61fdc0 - 0x61fde8 | 0
i = 11(different): 0x61fdf0 - 0x61fe1c | 0x61fdc0 - 0x61fdec | 0
i = 12(different): 0x61fdf0 - 0x61fe20 | 0x61fdc0 - 0x61fdf0 | 0
i = 13(different): 0x61fde0 - 0x61fe14 | 0x61fda0 - 0x61fdd4 | 0
i = 14(different): 0x61fde0 - 0x61fe18 | 0x61fda0 - 0x61fdd8 | 0
i = 15(different): 0x61fde0 - 0x61fe1c | 0x61fda0 - 0x61fddc | 0
i = 16(different): 0x61fde0 - 0x61fe20 | 0x61fda0 - 0x61fde0 | 0
i = 17(different): 0x61fdd0 - 0x61fe14 | 0x61fd80 - 0x61fdc4 | 0
i = 18(different): 0x61fdd0 - 0x61fe18 | 0x61fd80 - 0x61fdc8 | 0
i = 19(different): 0x61fdd0 - 0x61fe1c | 0x61fd80 - 0x61fdcc | 0
i = 20(different): 0x61fdd0 - 0x61fe20 | 0x61fd80 - 0x61fdd0 | 0
i = 21(different): 0x61fdc0 - 0x61fe14 | 0x61fd60 - 0x61fdb4 | 0
i = 22(different): 0x61fdc0 - 0x61fe18 | 0x61fd60 - 0x61fdb8 | 0
i = 23(different): 0x61fdc0 - 0x61fe1c | 0x61fd60 - 0x61fdbc | 0
i = 24(different): 0x61fdc0 - 0x61fe20 | 0x61fd60 - 0x61fdc0 | 0
i = 25(different): 0x61fdb0 - 0x61fe14 | 0x61fd40 - 0x61fda4 | 0
i = 26(different): 0x61fdb0 - 0x61fe18 | 0x61fd40 - 0x61fda8 | 0
i = 27(different): 0x61fdb0 - 0x61fe1c | 0x61fd40 - 0x61fdac | 0
i = 28(different): 0x61fdb0 - 0x61fe20 | 0x61fd40 - 0x61fdb0 | 0
i = 29(different): 0x61fda0 - 0x61fe14 | 0x61fd20 - 0x61fd94 | 0
i = 30(different): 0x61fda0 - 0x61fe18 | 0x61fd20 - 0x61fd98 | 0
i = 31(different): 0x61fda0 - 0x61fe1c | 0x61fd20 - 0x61fd9c | 0
i = 32(different): 0x61fda0 - 0x61fe20 | 0x61fd20 - 0x61fda0 | 0
i = 33(different): 0x61fd90 - 0x61fe14 | 0x61fd00 - 0x61fd84 | 0
i = 34(different): 0x61fd90 - 0x61fe18 | 0x61fd00 - 0x61fd88 | 0
i = 35(different): 0x61fd90 - 0x61fe1c | 0x61fd00 - 0x61fd8c | 0
i = 36(different): 0x61fd90 - 0x61fe20 | 0x61fd00 - 0x61fd90 | 0
i = 37(different): 0x61fd80 - 0x61fe14 | 0x61fce0 - 0x61fd74 | 0
i = 38(different): 0x61fd80 - 0x61fe18 | 0x61fce0 - 0x61fd78 | 0
i = 39(different): 0x61fd80 - 0x61fe1c | 0x61fce0 - 0x61fd7c | 0
i = 40(different): 0x61fd80 - 0x61fe20 | 0x61fce0 - 0x61fd80 | 0
i = 41(different): 0x61fd70 - 0x61fe14 | 0x61fcc0 - 0x61fd64 | 0
i = 42(different): 0x61fd70 - 0x61fe18 | 0x61fcc0 - 0x61fd68 | 0
i = 43(different): 0x61fd70 - 0x61fe1c | 0x61fcc0 - 0x61fd6c | 0
i = 44(different): 0x61fd70 - 0x61fe20 | 0x61fcc0 - 0x61fd70 | 0
i = 45(different): 0x61fd60 - 0x61fe14 | 0x61fca0 - 0x61fd54 | 0
i = 46(different): 0x61fd60 - 0x61fe18 | 0x61fca0 - 0x61fd58 | 0
i = 47(different): 0x61fd60 - 0x61fe1c | 0x61fca0 - 0x61fd5c | 0
i = 48(different): 0x61fd60 - 0x61fe20 | 0x61fca0 - 0x61fd60 | 0
i = 49(different): 0x61fd50 - 0x61fe14 | 0x61fc80 - 0x61fd44 | 0
i = 50(different): 0x61fd50 - 0x61fe18 | 0x61fc80 - 0x61fd48 | 0
i = 51(different): 0x61fd50 - 0x61fe1c | 0x61fc80 - 0x61fd4c | 0
i = 52(different): 0x61fd50 - 0x61fe20 | 0x61fc80 - 0x61fd50 | 0
i = 53(different): 0x61fd40 - 0x61fe14 | 0x61fc60 - 0x61fd34 | 0
i = 54(different): 0x61fd40 - 0x61fe18 | 0x61fc60 - 0x61fd38 | 0
i = 55(different): 0x61fd40 - 0x61fe1c | 0x61fc60 - 0x61fd3c | 0
i = 56(different): 0x61fd40 - 0x61fe20 | 0x61fc60 - 0x61fd40 | 0
i = 57(different): 0x61fd30 - 0x61fe14 | 0x61fc40 - 0x61fd24 | 0
i = 58(different): 0x61fd30 - 0x61fe18 | 0x61fc40 - 0x61fd28 | 0
i = 59(different): 0x61fd30 - 0x61fe1c | 0x61fc40 - 0x61fd2c | 0
i = 60(different): 0x61fd30 - 0x61fe20 | 0x61fc40 - 0x61fd30 | 0
i = 61(different): 0x61fd20 - 0x61fe14 | 0x61fc20 - 0x61fd14 | 0
i = 62(different): 0x61fd20 - 0x61fe18 | 0x61fc20 - 0x61fd18 | 0
i = 63(different): 0x61fd20 - 0x61fe1c | 0x61fc20 - 0x61fd1c | 0
i = 64(different): 0x61fd20 - 0x61fe20 | 0x61fc20 - 0x61fd20 | 0
i = 65(different): 0x61fd10 - 0x61fe14 | 0x61fc00 - 0x61fd04 | 0
i = 66(different): 0x61fd10 - 0x61fe18 | 0x61fc00 - 0x61fd08 | 0
i = 67(different): 0x61fd10 - 0x61fe1c | 0x61fc00 - 0x61fd0c | 0
i = 68(different): 0x61fd10 - 0x61fe20 | 0x61fc00 - 0x61fd10 | 0
i = 69(different): 0x61fd00 - 0x61fe14 | 0x61fbe0 - 0x61fcf4 | 0
i = 70(different): 0x61fd00 - 0x61fe18 | 0x61fbe0 - 0x61fcf8 | 0
i = 71(different): 0x61fd00 - 0x61fe1c | 0x61fbe0 - 0x61fcfc | 0
i = 72(different): 0x61fd00 - 0x61fe20 | 0x61fbe0 - 0x61fd00 | 0
i = 73(different): 0x61fcf0 - 0x61fe14 | 0x61fbc0 - 0x61fce4 | 0
i = 74(different): 0x61fcf0 - 0x61fe18 | 0x61fbc0 - 0x61fce8 | 0
i = 75(different): 0x61fcf0 - 0x61fe1c | 0x61fbc0 - 0x61fcec | 0
i = 76(different): 0x61fcf0 - 0x61fe20 | 0x61fbc0 - 0x61fcf0 | 0
i = 77(different): 0x61fce0 - 0x61fe14 | 0x61fba0 - 0x61fcd4 | 0
i = 78(different): 0x61fce0 - 0x61fe18 | 0x61fba0 - 0x61fcd8 | 0
i = 79(different): 0x61fce0 - 0x61fe1c | 0x61fba0 - 0x61fcdc | 0
i = 80(different): 0x61fce0 - 0x61fe20 | 0x61fba0 - 0x61fce0 | 0
i = 81(different): 0x61fcd0 - 0x61fe14 | 0x61fb80 - 0x61fcc4 | 0
i = 82(different): 0x61fcd0 - 0x61fe18 | 0x61fb80 - 0x61fcc8 | 0
i = 83(different): 0x61fcd0 - 0x61fe1c | 0x61fb80 - 0x61fccc | 0
i = 84(different): 0x61fcd0 - 0x61fe20 | 0x61fb80 - 0x61fcd0 | 0
i = 85(different): 0x61fcc0 - 0x61fe14 | 0x61fb60 - 0x61fcb4 | 0
i = 86(different): 0x61fcc0 - 0x61fe18 | 0x61fb60 - 0x61fcb8 | 0
i = 87(different): 0x61fcc0 - 0x61fe1c | 0x61fb60 - 0x61fcbc | 0
i = 88(different): 0x61fcc0 - 0x61fe20 | 0x61fb60 - 0x61fcc0 | 0
i = 89(different): 0x61fcb0 - 0x61fe14 | 0x61fb40 - 0x61fca4 | 0
i = 90(different): 0x61fcb0 - 0x61fe18 | 0x61fb40 - 0x61fca8 | 0
i = 91(different): 0x61fcb0 - 0x61fe1c | 0x61fb40 - 0x61fcac | 0
i = 92(different): 0x61fcb0 - 0x61fe20 | 0x61fb40 - 0x61fcb0 | 0
i = 93(different): 0x61fca0 - 0x61fe14 | 0x61fb20 - 0x61fc94 | 0
i = 94(different): 0x61fca0 - 0x61fe18 | 0x61fb20 - 0x61fc98 | 0
i = 95(different): 0x61fca0 - 0x61fe1c | 0x61fb20 - 0x61fc9c | 0
i = 96(different): 0x61fca0 - 0x61fe20 | 0x61fb20 - 0x61fca0 | 0
i = 97(different): 0x61fc90 - 0x61fe14 | 0x61fb00 - 0x61fc84 | 0
i = 98(different): 0x61fc90 - 0x61fe18 | 0x61fb00 - 0x61fc88 | 0
i = 99(different): 0x61fc90 - 0x61fe1c | 0x61fb00 - 0x61fc8c | 0
i = 100(different): 0x61fc90 - 0x61fe20 | 0x61fb00 - 0x61fc90 | 0
i = 101(different): 0x61fc80 - 0x61fe14 | 0x61fae0 - 0x61fc74 | 0
i = 102(different): 0x61fc80 - 0x61fe18 | 0x61fae0 - 0x61fc78 | 0
i = 103(different): 0x61fc80 - 0x61fe1c | 0x61fae0 - 0x61fc7c | 0
i = 104(different): 0x61fc80 - 0x61fe20 | 0x61fae0 - 0x61fc80 | 0
i = 105(different): 0x61fc70 - 0x61fe14 | 0x61fac0 - 0x61fc64 | 0
i = 106(different): 0x61fc70 - 0x61fe18 | 0x61fac0 - 0x61fc68 | 0
i = 107(different): 0x61fc70 - 0x61fe1c | 0x61fac0 - 0x61fc6c | 0
i = 108(different): 0x61fc70 - 0x61fe20 | 0x61fac0 - 0x61fc70 | 0
i = 109(different): 0x61fc60 - 0x61fe14 | 0x61faa0 - 0x61fc54 | 0
i = 110(different): 0x61fc60 - 0x61fe18 | 0x61faa0 - 0x61fc58 | 0
i = 111(different): 0x61fc60 - 0x61fe1c | 0x61faa0 - 0x61fc5c | 0
i = 112(different): 0x61fc60 - 0x61fe20 | 0x61faa0 - 0x61fc60 | 0
i = 113(different): 0x61fc50 - 0x61fe14 | 0x61fa80 - 0x61fc44 | 0
i = 114(different): 0x61fc50 - 0x61fe18 | 0x61fa80 - 0x61fc48 | 0
i = 115(different): 0x61fc50 - 0x61fe1c | 0x61fa80 - 0x61fc4c | 0
i = 116(different): 0x61fc50 - 0x61fe20 | 0x61fa80 - 0x61fc50 | 0
i = 117(different): 0x61fc40 - 0x61fe14 | 0x61fa60 - 0x61fc34 | 0
i = 118(different): 0x61fc40 - 0x61fe18 | 0x61fa60 - 0x61fc38 | 0
i = 119(different): 0x61fc40 - 0x61fe1c | 0x61fa60 - 0x61fc3c | 0
i = 120(different): 0x61fc40 - 0x61fe20 | 0x61fa60 - 0x61fc40 | 0
i = 121(different): 0x61fc30 - 0x61fe14 | 0x61fa40 - 0x61fc24 | 0
i = 122(different): 0x61fc30 - 0x61fe18 | 0x61fa40 - 0x61fc28 | 0
i = 123(different): 0x61fc30 - 0x61fe1c | 0x61fa40 - 0x61fc2c | 0
i = 124(different): 0x61fc30 - 0x61fe20 | 0x61fa40 - 0x61fc30 | 0
i = 125(different): 0x61fc20 - 0x61fe14 | 0x61fa20 - 0x61fc14 | 0
i = 126(different): 0x61fc20 - 0x61fe18 | 0x61fa20 - 0x61fc18 | 0
i = 127(different): 0x61fc20 - 0x61fe1c | 0x61fa20 - 0x61fc1c | 0
i = 128(different): 0x61fc20 - 0x61fe20 | 0x61fa20 - 0x61fc20 | 0
```

正当我沮丧之时，忽然发现，数组$b$的起始地址小于数组$a$的“越界地址”！！！因此是会产生“数据覆盖”的。

## 何时真正可以？

> 第一行输入一个正整数$n$（$1\leq n\leq 128$），第二行输入空格隔开的$n$个正整数（$1$到$10000$）代表数组$a$中的元素，第三行输入空格隔开的$n$个正整数（$1$到$10000$）代表数组$b$中的元素，第四行输入空格隔开的两个正整数$x$和$y$（$1\leq x, y\leq n$），交换$a[x]$和$b[y]$，并按顺序输出数组$a$和数组$b$中的元素（每个输出一行且用不用元素之间用空格隔开）

这里的$n=128$非常重要，$128=8\times 16$，对于初期编程选手，可能会连开两个大小为$128$的数组，并从下标$1$开始存数据到下标$n$，导致数组越界。

理论上 如果测试数据中有$n=128$的数据，则（期望条件下）只要两个数组是连续开的，就会结果错误？

但结果是即使开大小为127的数组也还是会AC。。。开128可能是因为数组$a+128$正好是$b[0]$而$b$是从下标$1$开始使用的。但是开127还能过，，也许是测评姬上和本地内存开辟情况不同？

到最后，越界时不能AC的目标还是没能实现啊。。。[ArrayBoundaryExceeded Killer Failed](https://www.luogu.com.cn/problem/U393605)

最后贴个正确代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

int a[128], b[128];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >>b[i];
    }
    int x, y;
    cin >> x >> y;
    swap(a[x - 1], b[y - 1]);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    return 0;
}
```

<center><font size="6px" face="Ink Free">The Real End, Thanks!</font></center>

> 原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/12/27/Other-C-C++-ArrayBoundaryExceeded-MemoryAddress/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135256408](https://letmefly.blog.csdn.net/article/details/135256408)
