# LeetCode

本项目将会长期更新【力扣题解】、【解题技巧】等，欢迎各位大佬共同参与、提交PR，目标包括但不限于力扣中数字开头的2k多道题。

## AC代码

AC代码见```Codes/*```，命名格式为：{题号}-{uri}.{后缀}

### 题号

题号类型有以下两种：数字开头、非数字开头。

> + 数字开头的题目(如[https://leetcode.cn/problems/two-sum/](https://leetcode.cn/problems/two-sum/)的题目为“1. 两数之和”)
>
> + 非数字开头的题目(如[https://leetcode.cn/problems/successor-lcci/](https://leetcode.cn/problems/successor-lcci/)的题目为“面试题 04.06. 后继者”)

|类型|例如|题号格式|
|:--:|:--:|:--:|
|数字开头|1. 两数之和(<a href="https://leetcode.cn/problems/two-sum/">https://leetcode.cn/problems/two-sum/</a>)|四位整数：0001|
|面试题|面试题 04.06. 后继者(<a href="https://leetcode.cn/problems/successor-lcci/">https://leetcode.cn/problems/successor-lcci/</a>)|MianShiTi04.06|
|LCP|LCP 28. 采购方案(<a href="https://leetcode.cn/problems/4xy4Wx/">https://leetcode.cn/problems/4xy4Wx/</a>)|LCP0028|
|...|...|...|

### uri

uri是题目地址中对应的最后一部分，也是每道题目中独一无二的一部分。

截至2022.5.21，LeetCode中的题目地址为 ```https://leetcode.cn/problems/{uri}/```

也就是说，如果想要根据一个代码文件确定题目地址，我们只需要把文件名中的uri部分待入上述地址即可。

例如：

```1. 两数之和``` 的地址为 ```https://leetcode.cn/problems/two-sum/```，它对应的C++代码文件为：```0001-two-sum.cpp```。

想要通过```0001-two-sum.cpp```查看对应题目，我们只需要在浏览器地址栏中输入```https://leetcode.cn/problems/two-sum/```即可。

### 后缀

不同的后缀对应不同的编程语言。比如```.cpp```对应编程语言```C++```、```.py```对应编程语言```Python```。

## AC代码/基础头文件

LeetCode很多题不需要写头文件、main函数等，因此在本地编写代码时如果仅仅复制粘贴要提交的部分，编译器很肯能会报错。

如何解决这个问题呢？只需引入```Codes```下的```_[1,2]toVector.h```即可。

如果你使用的是Windows，引入方式：

```cpp
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif
```

然后就可以编写LeetCode的代码了。

```_[1,2]toVector.h```中包含了很多LeetCode中常用的数据结构，如果想在本地调试，可以在文件尾部加上代码如：

```cpp
#ifdef _WIN32
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        cout << sol.demoString(s) << endl;
    }
    return 0;
}
#endif
```

## 现有题解

|题目名称|困难程度|题目地址|题解地址|CSDN题解|LeetCode题解|
|:--|:--|:--|:--|:--|:--|
|0564.寻找最近的回文数|困难|<a href="https://leetcode.cn/problems/find-the-closest-palindrome/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/05/21/LeetCode%200961.%E5%9C%A8%E9%95%BF%E5%BA%A62N%E7%9A%84%E6%95%B0%E7%BB%84%E4%B8%AD%E6%89%BE%E5%87%BA%E9%87%8D%E5%A4%8DN%E6%AC%A1%E7%9A%84%E5%85%83%E7%B4%A0/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/123254172" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/find-the-closest-palindrome/solution/letmefly-da-an-hou-xuan-by-letmefly-2-k2vn/" target="_blank">地址点我</a>|
|0961.在长度2N的数组中找出重复N次的元素|简单|<a href="https://leetcode.cn/problems/n-repeated-element-in-size-2n-array/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/05/21/LeetCode%200961.%E5%9C%A8%E9%95%BF%E5%BA%A62N%E7%9A%84%E6%95%B0%E7%BB%84%E4%B8%AD%E6%89%BE%E5%87%BA%E9%87%8D%E5%A4%8DN%E6%AC%A1%E7%9A%84%E5%85%83%E7%B4%A0/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/124897591" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/find-the-closest-palindrome/solution/letmefly-da-an-hou-xuan-by-letmefly-2-k2vn/" target="_blank">地址点我</a>|
