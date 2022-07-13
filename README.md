<!--
 * @Author: LetMeFly
 * @Date: 2022-05-19 18:48:53
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-09 23:44:38
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
|0086.分隔链表|中等|<a href="https://leetcode.cn/problems/partition-list/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/06/26/LeetCode%200086.%E5%88%86%E9%9A%94%E9%93%BE%E8%A1%A8/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125467594" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/partition-list/solution/letmefly-86fen-ge-lian-biao-by-tisfy-64z3/" target="_blank">地址点我</a>|
|0091.解码方法|中等|<a href="https://leetcode.cn/problems/decode-ways/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/06/27/LeetCode%200091.%E8%A7%A3%E7%A0%81%E6%96%B9%E6%B3%95/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125487393" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/decode-ways/solution/by-tisfy-l576/" target="_blank">地址点我</a>|
|0102.二叉树的层序遍历|中等|<a href="https://leetcode.cn/problems/binary-tree-level-order-traversal/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/07/03/LeetCode%200102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125584554" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/binary-tree-level-order-traversal/solution/letmefly-102er-cha-shu-de-ceng-xu-bian-l-jaze/" target="_blank">地址点我</a>|
|0107.二叉树的层序遍历II|中等|<a href="https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/07/04/LeetCode%200107.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86II/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125610699" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/solution/107er-cha-shu-de-ceng-xu-bian-li-ii-by-t-8zit/" target="_blank">地址点我</a>|
|0108.将有序数组转换为二叉搜索树|简单|<a href="https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/07/04/LeetCode%200108.%E5%B0%86%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E8%BD%AC%E6%8D%A2%E4%B8%BA%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125610878" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/solution/letmefly-by-tisfy-qxyu/" target="_blank">地址点我</a>|
|0109.有序链表转换二叉搜索树|中等|<a href="https://leetcode.cn/problems/convert-sorted-list-to-binary-search-tree/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/07/09/LeetCode%200109.%E6%9C%89%E5%BA%8F%E9%93%BE%E8%A1%A8%E8%BD%AC%E6%8D%A2%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125691471" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/convert-sorted-list-to-binary-search-tree/solution/by-tisfy-vl6x/" target="_blank">地址点我</a>|
|0110.平衡二叉树|简单|<a href="https://leetcode.cn/problems/balanced-binary-tree/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/07/09/LeetCode%200110.%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125691684" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/balanced-binary-tree/solution/by-tisfy-au3u/" target="_blank">地址点我</a>|
|0111.二叉树的最小深度|简单|<a href="https://leetcode.cn/problems/minimum-depth-of-binary-tree/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/07/11/LeetCode%200111.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E5%B0%8F%E6%B7%B1%E5%BA%A6/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125718620" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/minimum-depth-of-binary-tree/solution/by-tisfy-tghs/" target="_blank">地址点我</a>|
|0112.路径总和|简单|<a href="https://leetcode.cn/problems/path-sum/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/07/11/LeetCode%200112.%E8%B7%AF%E5%BE%84%E6%80%BB%E5%92%8C/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125718939" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/path-sum/solution/by-tisfy-nzbd/" target="_blank">地址点我</a>|
|0113.路径总和II|中等|<a href="https://leetcode.cn/problems/path-sum-ii/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/07/12/LeetCode%200113.%E8%B7%AF%E5%BE%84%E6%80%BB%E5%92%8CII/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125739794" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/path-sum-ii/solution/by-tisfy-4r65/" target="_blank">地址点我</a>|
|0114.二叉树展开为链表|中等|<a href="https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/07/12/LeetCode%200114.%E4%BA%8C%E5%8F%89%E6%A0%91%E5%B1%95%E5%BC%80%E4%B8%BA%E9%93%BE%E8%A1%A8/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125741572" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/solution/by-tisfy-pzcv/" target="_blank">地址点我</a>|
|0156.上下翻转二叉树|中等|<a href="https://leetcode.cn/problems/binary-tree-upside-down/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/05/29/LeetCode%200156.%E4%B8%8A%E4%B8%8B%E7%BF%BB%E8%BD%AC%E4%BA%8C%E5%8F%89%E6%A0%91" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125028889" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/partition-list/solution/letmefly-86fen-ge-lian-biao-by-tisfy-64z3/" target="_blank">地址点我</a>|
|0157.用Read4读取N个字符|简单|<a href="https://leetcode.cn/problems/read-n-characters-given-read4/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/05/29/LeetCode%200157.%E7%94%A8Read4%E8%AF%BB%E5%8F%96N%E4%B8%AA%E5%AD%97%E7%AC%A6" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125030886" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/read-n-characters-given-read4/solution/letmefly-157yong-read4du-qu-nge-zi-fu-by-ve20/" target="_blank">地址点我</a>|
|0241.为运算表达式设计优先级|中等|<a href="https://leetcode.cn/problems/different-ways-to-add-parentheses/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/07/01/LeetCode%200241.%E4%B8%BA%E8%BF%90%E7%AE%97%E8%A1%A8%E8%BE%BE%E5%BC%8F%E8%AE%BE%E8%AE%A1%E4%BC%98%E5%85%88%E7%BA%A7/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125555659" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/different-ways-to-add-parentheses/solution/letmefly-241wei-yun-suan-biao-da-shi-she-kkj9/" target="_blank">地址点我</a>|
|0467.环绕字符串中唯一的子字符串|中等|<a href="https://leetcode.cn/problems/unique-substrings-in-wraparound-string/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/05/25/LeetCode%200467.%E7%8E%AF%E7%BB%95%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E5%94%AF%E4%B8%80%E7%9A%84%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/124972046" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/unique-substrings-in-wraparound-string/solution/by-tisfy-w4y6/" target="_blank">地址点我</a>|
|0478.在圆内随机生成点|中等|<a href="https://leetcode.cn/problems/generate-random-point-in-a-circle/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/06/05/LeetCode%200478.%E5%9C%A8%E5%9C%86%E5%86%85%E9%9A%8F%E6%9C%BA%E7%94%9F%E6%88%90%E7%82%B9" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125129132" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/generate-random-point-in-a-circle/solution/letmefly-tong-su-de-hua-miao-shu-478zai-8wm7k/" target="_blank">地址点我</a>|
|0556.下一个更大元素 III|中等|<a href="https://leetcode.cn/problems/next-greater-element-iii/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/07/03/LeetCode%200556.%E4%B8%8B%E4%B8%80%E4%B8%AA%E6%9B%B4%E5%A4%A7%E5%85%83%E7%B4%A0III" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125582351" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/next-greater-element-iii/solution/letmefly-4bu-jiang-wan-556xia-yi-ge-geng-o247/" target="_blank">地址点我</a>|
|0564.寻找最近的回文数|困难|<a href="https://leetcode.cn/problems/find-the-closest-palindrome/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/03/03/LeetCode%200564.%E5%AF%BB%E6%89%BE%E6%9C%80%E8%BF%91%E7%9A%84%E5%9B%9E%E6%96%87%E6%95%B0/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/123254172" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/find-the-closest-palindrome/solution/letmefly-da-an-hou-xuan-by-letmefly-2-k2vn/" target="_blank">地址点我</a>|
|0676.实现一个魔法字典|中等|<a href="https://leetcode.cn/problems/implement-magic-dictionary/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/07/11/LeetCode%200676.%E5%AE%9E%E7%8E%B0%E4%B8%80%E4%B8%AA%E9%AD%94%E6%B3%95%E5%AD%97%E5%85%B8/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125718347" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/implement-magic-dictionary/solution/by-tisfy-idnh/" target="_blank">地址点我</a>|
|0699.掉落的方块|困难|<a href="https://leetcode.cn/problems/falling-squares/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/05/26/LeetCode%200699.%E6%8E%89%E8%90%BD%E7%9A%84%E6%96%B9%E5%9D%97/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/124978728" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/falling-squares/solution/letmefly-liang-chong-fang-fa-jie-jue-699-pc90/" target="_blank">地址点我</a>|
|0710.黑名单中的随机数|困难|<a href="https://leetcode.cn/problems/random-pick-with-blacklist/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/06/26/LeetCode%200710.%20%E9%BB%91%E5%90%8D%E5%8D%95%E4%B8%AD%E7%9A%84%E9%9A%8F%E6%9C%BA%E6%95%B0/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125466455" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/random-pick-with-blacklist/solution/710hei-ming-dan-zhong-de-sui-ji-shu-yu-c-cmxn/" target="_blank">地址点我</a>|
|0735.行星碰撞|中等|<a href="https://leetcode.cn/problems/asteroid-collision/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/07/13/LeetCode%200735.%E8%A1%8C%E6%98%9F%E7%A2%B0%E6%92%9E/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125774687" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/asteroid-collision/solution/by-tisfy-nxaa/" target="_blank">地址点我</a>|
|0871.最低加油次数|困难|<a href="https://leetcode.cn/problems/minimum-number-of-refueling-stops/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/07/02/LeetCode%200871.%E6%9C%80%E4%BD%8E%E5%8A%A0%E6%B2%B9%E6%AC%A1%E6%95%B0/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125575683" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/minimum-number-of-refueling-stops/solution/letmefly-871zui-di-jia-you-ci-shu-lei-si-ucry/" target="_blank">地址点我</a>|
|0873.最长的斐波那契子序列的长度|中等|<a href="https://leetcode.cn/problems/length-of-longest-fibonacci-subsequence/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/07/09/LeetCode%200873.%E6%9C%80%E9%95%BF%E7%9A%84%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E5%AD%90%E5%BA%8F%E5%88%97%E7%9A%84%E9%95%BF%E5%BA%A6/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125690924" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/length-of-longest-fibonacci-subsequence/solution/by-tisfy-4gh4/" target="_blank">地址点我</a>|
|0961.在长度2N的数组中找出重复N次的元素|简单|<a href="https://leetcode.cn/problems/n-repeated-element-in-size-2n-array/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/05/21/LeetCode%200961.%E5%9C%A8%E9%95%BF%E5%BA%A62N%E7%9A%84%E6%95%B0%E7%BB%84%E4%B8%AD%E6%89%BE%E5%87%BA%E9%87%8D%E5%A4%8DN%E6%AC%A1%E7%9A%84%E5%85%83%E7%B4%A0/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/124897591" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/find-the-closest-palindrome/solution/letmefly-da-an-hou-xuan-by-letmefly-2-k2vn/" target="_blank">地址点我</a>|
|1021.删除最外层的括号|简单|<a href="https://leetcode.cn/problems/remove-outermost-parentheses/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/05/28/LeetCode%201021.%E5%88%A0%E9%99%A4%E6%9C%80%E5%A4%96%E5%B1%82%E7%9A%84%E6%8B%AC%E5%8F%B7" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125015777" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/remove-outermost-parentheses/solution/letmefly-1021shan-chu-zui-wai-ceng-de-gu-nyio/" target="_blank">地址点我</a>|
|1022.从根到叶的二进制数之和|简单|<a href="https://leetcode.cn/problems/sum-of-root-to-leaf-binary-numbers/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/05/30/LeetCode%201022.%E4%BB%8E%E6%A0%B9%E5%88%B0%E5%8F%B6%E7%9A%84%E4%BA%8C%E8%BF%9B%E5%88%B6%E6%95%B0%E4%B9%8B%E5%92%8C" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125043202" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/sum-of-root-to-leaf-binary-numbers/solution/letmefly-1022cong-gen-dao-xie-de-er-jin-xcjny/" target="_blank">地址点我</a>|
|1200.最小绝对差|简单|<a href="https://leetcode.cn/problems/minimum-absolute-difference/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/07/04/LeetCode%201200.%E6%9C%80%E5%B0%8F%E7%BB%9D%E5%AF%B9%E5%B7%AE/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125609898" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/minimum-absolute-difference/solution/letmefly-1200zui-xiao-jue-dui-chai-by-ti-nocj/" target="_blank">地址点我</a>|
|1252.奇数值单元格的数目|简单|<a href="https://leetcode.cn/problems/cells-with-odd-values-in-a-matrix/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/07/12/LeetCode%201252.%E5%A5%87%E6%95%B0%E5%80%BC%E5%8D%95%E5%85%83%E6%A0%BC%E7%9A%84%E6%95%B0%E7%9B%AE/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125738504" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/cells-with-odd-values-in-a-matrix/solution/by-tisfy-fqsc/" target="_blank">地址点我</a>|
|剑指OfferII0091.粉刷房子|中等|<a href="https://leetcode.cn/problems/JEj789/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/06/25/LeetCode%20%E5%89%91%E6%8C%87%20Offer%20II%200091.%20%E7%B2%89%E5%88%B7%E6%88%BF%E5%AD%90/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125456885" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/JEj789/solution/letmefly-jian-zhi-offer-ii-091fen-shua-f-3olz/" target="_blank">地址点我</a>|
|面试题17.11.单词距离|中等|<a href="https://leetcode.cn/problems/find-closest-lcci/" target="_blank">地址点我</a>|<a href="https://leetcode.letmefly.xyz/2022/05/27/LeetCode%20%E9%9D%A2%E8%AF%95%E9%A2%98%2017.11.%20%E5%8D%95%E8%AF%8D%E8%B7%9D%E7%A6%BB/" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/124998677" target="_blank">地址点我</a>|<a href="https://leetcode.cn/problems/find-closest-lcci/solution/letmefly-mian-shi-ti-1711dan-ci-ju-chi-k-t5d5/" target="_blank">地址点我</a>|

### 其他平台题解

|题目|题解|CSDN题解|
|:--|:--|:--|
|<a href="https://atcoder.jp/contests/abc259/tasks/abc259_a">AtCoder Beginner Contest 259 - A - Growth Record</a>|<a href="https://leetcode.letmefly.xyz/2022/07/09/AtCoder%20Beginner%20Contest%20259%20-%20A%20-%20Growth%20Record/">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125699180">地址点我</a>|
|<a href="https://atcoder.jp/contests/abc259/tasks/abc259_b">AtCoder Beginner Contest 259 - B - Counterclockwise Rotation </a>|<a href="https://leetcode.letmefly.xyz/2022/07/09/AtCoder%20Beginner%20Contest%20259%20-%20B%20-%20Counterclockwise%20Rotation/">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125699603">地址点我</a>|
|<a href="https://atcoder.jp/contests/abc259/tasks/abc259_c">AtCoder Beginner Contest 259 - C - XX to XXX </a>|<a href="https://leetcode.letmefly.xyz/2022/07/09/AtCoder%20Beginner%20Contest%20259%20-%20C%20-%20XX%20to%20XXX/">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125700254">地址点我</a>|
|<a href="https://atcoder.jp/contests/abc259/tasks/abc259_d">AtCoder Beginner Contest 259 - D - Circumferences </a>|<a href="https://leetcode.letmefly.xyz/2022/07/09/AtCoder%20Beginner%20Contest%20259%20-%20D%20-%20Circumferences/">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/125700650">地址点我</a>|

## TODO:

+ 考完闲一些的时候，特别想写写[62. 不同路径](https://leetcode.cn/problems/unique-paths) 的题解
+ [1037. 有效的回旋镖](https://leetcode.cn/problems/valid-boomerang/)也可写
+ 还有[65. 有效数字](https://leetcode.cn/problems/valid-number/)
+ [67. 二进制求和](https://leetcode.cn/problems/add-binary/)
+ [926. 将字符串翻转到单调递增](https://leetcode.cn/problems/flip-string-to-monotone-increasing/)
+ [70. 爬楼梯](https://leetcode.cn/problems/climbing-stairs/)
