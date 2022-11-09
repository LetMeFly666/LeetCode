---
title: 剑指 Offer II 041.滑动窗口的平均值
date: 2022-07-16 13:41:54
tags: [题解, LeetCode, 简单, 设计, 队列, 数组, 数据流, 滑动窗口, 类, 静态数组模拟队列, 定长队列]
---

# 【LetMeFly】低空间消耗解决：剑指 Offer II 041.滑动窗口的平均值

力扣题目链接：[https://leetcode.cn/problems/qIsx9U/](https://leetcode.cn/problems/qIsx9U/)

<p>给定一个整数数据流和一个窗口大小，根据该滑动窗口的大小，计算滑动窗口里所有数字的平均值。</p>

<p>实现 <code>MovingAverage</code> 类：</p>

<ul>
	<li><code>MovingAverage(int size)</code> 用窗口大小 <code>size</code> 初始化对象。</li>
	<li><code>double next(int val)</code>&nbsp;成员函数 <code>next</code>&nbsp;每次调用的时候都会往滑动窗口增加一个整数，请计算并返回数据流中最后 <code>size</code> 个值的移动平均值，即滑动窗口里所有数字的平均值。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
inputs = [&quot;MovingAverage&quot;, &quot;next&quot;, &quot;next&quot;, &quot;next&quot;, &quot;next&quot;]
inputs = [[3], [1], [10], [3], [5]]
<strong>输出：</strong>
[null, 1.0, 5.5, 4.66667, 6.0]

<strong>解释：</strong>
MovingAverage movingAverage = new MovingAverage(3);
movingAverage.next(1); // 返回 1.0 = 1 / 1
movingAverage.next(10); // 返回 5.5 = (1 + 10) / 2
movingAverage.next(3); // 返回 4.66667 = (1 + 10 + 3) / 3
movingAverage.next(5); // 返回 6.0 = (10 + 3 + 5) / 3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= size &lt;= 1000</code></li>
	<li><code>-10<sup>5</sup> &lt;= val &lt;= 10<sup>5</sup></code></li>
	<li>最多调用 <code>next</code> 方法 <code>10<sup>4</sup></code> 次</li>
</ul>

<p>&nbsp;</p>

<p><meta charset="UTF-8" />注意：本题与主站 346&nbsp;题相同：&nbsp;<a href="https://leetcode-cn.com/problems/moving-average-from-data-stream/">https://leetcode-cn.com/problems/moving-average-from-data-stream/</a></p>



## 方法一：模拟

这道题模拟即可。

+ 用```int size```记录“滑动窗口”的最大大小
+ 用```int sum```记录“滑动窗口”中的所有的值的和
+ 用```int num```记录“滑动窗口”的数字的个数

那么用什么来模拟窗口呢？其实用队列是个非常棒的选择。

但是看这篇标题也可以看出，本题解主要使用低空间消耗来解决问题，因此决定使用```静态数组```来模拟队列。

因为队列的长度是固定不变的，因此我们开辟数组的时候，开辟的大小就为“滑动窗口”的大小即可。

+ 用```int* a```模拟队列
+ 用```int loc```记录即将要出队的元素的下标

```cpp
private:
    int size;
    int sum;
    int num;
    int *a;  // Array
    int loc;  // 该移除哪个了

public:
    /** Initialize your data structure here. */
    MovingAverage(int size): size(size), sum(0), num(0), a(new int[size]), loc(0) {

    }
```

当向“滑动窗口”中添加新的元素时，首先看队列是否已满。

+ 若不满则添加新元素
+ 若已满则删除旧元素的同时添加新元素

```cpp
if (num < size) {  // 刚开始，还没填满窗口
    sum += val;
    a[num++] = val;
    return ONE * sum / num;  // 其中ONE是double类型的1
}
else {
    sum -= a[loc];
    sum += val;
    a[loc++] = val;
    loc %= size;
    return ONE * sum / num;
}
```

运行结果：

![result](https://img-blog.csdnimg.cn/07494cd6ca7c4ada98102869944bb8fa.jpeg#pic_center)

如果想要更加严谨一点，可以在类析构的时候```delete```new出来的数组

```cpp
~MovingAverage() {
    delete[] a;
}
```

运行时间竟然减少了

![加上delete](https://img-blog.csdnimg.cn/1e2419eab57244078e0a68b3e07c80c6.jpeg#pic_center)

+ 时间复杂度$O(n)$，其中$n$是要添加的元素的个数
+ 空间复杂度$O(m)$，其中$m$是“滑动窗口”的大小

### AC代码

#### C++

```cpp
const double ONE = 1;

class MovingAverage {
private:
    int size;
    int sum;
    int num;
    int *a;  // Array
    int loc;  // 该移除哪个了
public:
    /** Initialize your data structure here. */
    MovingAverage(int size): size(size), sum(0), num(0), a(new int[size]), loc(0) {

    }

    ~MovingAverage() {
        delete[] a;
    }
    
    double next(int val) {
        if (num < size) {  // 刚开始，还没填满窗口
            sum += val;
            a[num++] = val;
            return ONE * sum / num;
        }
        else {
            sum -= a[loc];
            sum += val;
            a[loc++] = val;
            loc %= size;
            return ONE * sum / num;
        }
    }
};
```


> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/07/16/LeetCode%20%E5%89%91%E6%8C%87%20Offer%20II%200041.%20%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E7%9A%84%E5%B9%B3%E5%9D%87%E5%80%BC/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125819216](https://letmefly.blog.csdn.net/article/details/125819216)