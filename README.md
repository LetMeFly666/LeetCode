<!--
 * @Author: LetMeFly
 * @Date: 2022-05-19 18:48:53
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-08 11:28:15
-->
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
|0049.字母异位词分组|中等|<a href="https://leetcode.cn/problems/group-anagrams/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/05/25/LeetCode%200049.%E5%AD%97%E6%AF%8D%E5%BC%82%E4%BD%8D%E8%AF%8D%E5%88%86%E7%BB%84/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/124972260" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/group-anagrams/solution/by-tisfy-v56n/" target="_blank">地址点我</a>|
|0050.Pow(x, n)|中等|<a href="https://leetcode.cn/problems/powx-n/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/05/25/LeetCode%200050.Pow(x,%20n)/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/124972517" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/powx-n/solution/by-tisfy-8ort/" target="_blank">地址点我</a>|
|0051.N皇后|困难|<a href="https://leetcode.cn/problems/n-queens/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/05/27/LeetCode%200051.N%E7%9A%87%E5%90%8E/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/124999635" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/n-queens/solution/letmefly-51nhuang-hou-by-tisfy-4cor/" target="_blank">地址点我</a>|
|0052.N皇后II|困难|<a href="https://leetcode.cn/problems/n-queens-ii/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/05/27/LeetCode%200052.N%E7%9A%87%E5%90%8EII/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125000091" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/n-queens-ii/solution/letmefly-52nhuang-hou-ii-by-tisfy-0uq2/" target="_blank">地址点我</a>|
|0054.螺旋矩阵|中等|<a href="https://leetcode.cn/problems/spiral-matrix/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/05/28/LeetCode%200054.%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125016209" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/spiral-matrix/solution/by-tisfy-6ehi/" target="_blank">地址点我</a>|
|0055.跳跃游戏|中等|<a href="https://leetcode.cn/problems/jump-game/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/05/28/LeetCode%200055.%E8%B7%B3%E8%B7%83%E6%B8%B8%E6%88%8F" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125021531" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/jump-game/solution/letmefly-55tiao-yue-you-xi-by-tisfy-q3af/" target="_blank">地址点我</a>|
|0156.上下翻转二叉树|中等|<a href="https://leetcode.cn/problems/binary-tree-upside-down/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/05/29/LeetCode%200156.%E4%B8%8A%E4%B8%8B%E7%BF%BB%E8%BD%AC%E4%BA%8C%E5%8F%89%E6%A0%91" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125028889" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/binary-tree-upside-down/solution/by-tisfy-bsuu/" target="_blank">地址点我</a>|
|0157.用Read4读取N个字符|简单|<a href="https://leetcode.cn/problems/read-n-characters-given-read4/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/05/29/LeetCode%200157.%E7%94%A8Read4%E8%AF%BB%E5%8F%96N%E4%B8%AA%E5%AD%97%E7%AC%A6" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125030886" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/read-n-characters-given-read4/solution/letmefly-157yong-read4du-qu-nge-zi-fu-by-ve20/" target="_blank">地址点我</a>|
|0467.环绕字符串中唯一的子字符串|中等|<a href="https://leetcode.cn/problems/unique-substrings-in-wraparound-string/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/05/25/LeetCode%200467.%E7%8E%AF%E7%BB%95%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E5%94%AF%E4%B8%80%E7%9A%84%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/124972046" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/unique-substrings-in-wraparound-string/solution/by-tisfy-w4y6/" target="_blank">地址点我</a>|
|0478.在圆内随机生成点|中等|<a href="https://leetcode.cn/problems/generate-random-point-in-a-circle/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/06/05/LeetCode%200478.%E5%9C%A8%E5%9C%86%E5%86%85%E9%9A%8F%E6%9C%BA%E7%94%9F%E6%88%90%E7%82%B9" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125129132" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/generate-random-point-in-a-circle/solution/letmefly-tong-su-de-hua-miao-shu-478zai-8wm7k/" target="_blank">地址点我</a>|
|0564.寻找最近的回文数|困难|<a href="https://leetcode.cn/problems/find-the-closest-palindrome/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/03/03/LeetCode%200564.%E5%AF%BB%E6%89%BE%E6%9C%80%E8%BF%91%E7%9A%84%E5%9B%9E%E6%96%87%E6%95%B0/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/123254172" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/find-the-closest-palindrome/solution/letmefly-da-an-hou-xuan-by-letmefly-2-k2vn/" target="_blank">地址点我</a>|
|0699.掉落的方块|困难|<a href="https://leetcode.cn/problems/falling-squares/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/05/26/LeetCode%200699.%E6%8E%89%E8%90%BD%E7%9A%84%E6%96%B9%E5%9D%97/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/124978728" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/falling-squares/solution/letmefly-liang-chong-fang-fa-jie-jue-699-pc90/" target="_blank">地址点我</a>|
|0961.在长度2N的数组中找出重复N次的元素|简单|<a href="https://leetcode.cn/problems/n-repeated-element-in-size-2n-array/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/05/21/LeetCode%200961.%E5%9C%A8%E9%95%BF%E5%BA%A62N%E7%9A%84%E6%95%B0%E7%BB%84%E4%B8%AD%E6%89%BE%E5%87%BA%E9%87%8D%E5%A4%8DN%E6%AC%A1%E7%9A%84%E5%85%83%E7%B4%A0/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/124897591" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/find-the-closest-palindrome/solution/letmefly-da-an-hou-xuan-by-letmefly-2-k2vn/" target="_blank">地址点我</a>|
|1021.删除最外层的括号|简单|<a href="https://leetcode.cn/problems/remove-outermost-parentheses/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/05/28/LeetCode%201021.%E5%88%A0%E9%99%A4%E6%9C%80%E5%A4%96%E5%B1%82%E7%9A%84%E6%8B%AC%E5%8F%B7" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125015777" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/remove-outermost-parentheses/solution/letmefly-1021shan-chu-zui-wai-ceng-de-gu-nyio/" target="_blank">地址点我</a>|
|1022.从根到叶的二进制数之和|简单|<a href="https://leetcode.cn/problems/sum-of-root-to-leaf-binary-numbers/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/05/30/LeetCode%201022.%E4%BB%8E%E6%A0%B9%E5%88%B0%E5%8F%B6%E7%9A%84%E4%BA%8C%E8%BF%9B%E5%88%B6%E6%95%B0%E4%B9%8B%E5%92%8C" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125043202" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/sum-of-root-to-leaf-binary-numbers/solution/letmefly-1022cong-gen-dao-xie-de-er-jin-xcjny/" target="_blank">地址点我</a>|
|面试题17.11.单词距离|中等|<a href="https://leetcode.cn/problems/find-closest-lcci/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/05/27/LeetCode%20%E9%9D%A2%E8%AF%95%E9%A2%98%2017.11.%20%E5%8D%95%E8%AF%8D%E8%B7%9D%E7%A6%BB/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/124998677" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/find-closest-lcci/solution/letmefly-mian-shi-ti-1711dan-ci-ju-chi-k-t5d5/" target="_blank">地址点我</a>|

## TODO: 

+ 考完闲一些的时候，特别想写写[62. 不同路径](https://leetcode.cn/problems/unique-paths) 的题解
+ [1037. 有效的回旋镖](https://leetcode.cn/problems/valid-boomerang/)也可写
+ 还有[65. 有效数字](https://leetcode.cn/problems/valid-number/)
+ [67. 二进制求和](https://leetcode.cn/problems/add-binary/)
