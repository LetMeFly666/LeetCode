<!--
 * @Author: LetMeFly
 * @Date: 2023-10-20 22:24:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-08 09:52:46
-->
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

引入方式（`_DEBUG` 由 `.vscode/tasks.json` 中的 `-D_DEBUG` 编译参数定义，Windows 和 macOS 均生效）：

本仓库的 `.vscode/tasks.json` 在 **g++（Windows）** 和 **clang++（macOS）** 的编译任务中均传入了 `-D_DEBUG` 参数，`.vscode/c_cpp_properties.json` 的 Win32 和 Mac 配置也都在 `defines` 中包含了 `_DEBUG`。因此，使用 VSCode 本地编译时 `_DEBUG` 宏始终可用。
#ifdef _DEBUG
**推荐方式（跨平台，使用 `_DEBUG`）：**

如何解决这个问题呢？只需引入```Codes```下的```_[1,2]toVector.h```即可。
#ifdef _DEBUG
如果你使用的是Windows，引入方式：

```cpp
#ifdef _WIN32
> `_DEBUG` 由 `.vscode/tasks.json` 的 `-D_DEBUG` 编译参数定义，Windows 和 macOS 下均生效。
#ifdef _DEBUG
**仅 Windows 平台：**

```cpp
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif
```

**Windows + macOS：**

```cpp
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif
```

> 上述三种方式均可，推荐使用 `_DEBUG`，因为它与 `.vscode` 的编译配置一致，且不依赖特定操作系统宏。

### 本地调试
#endif
引入头文件后就可以编写LeetCode的代码了。

```_[1,2]toVector.h```中包含了很多LeetCode中常用的数据结构。

如果想在本地调试，可以在文件尾部加上代码如：

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

可以通过[Github Gist](https://gist.github.com/LetMeFly666/9e9c47db429532b212537cc1f6f36a42)进行下载/查看

## 其他文件

`cargo.lock`、`cargo.toml`、`lib.rs`都是rust所需