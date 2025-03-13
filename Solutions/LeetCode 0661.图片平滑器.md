---
title: 661.图片平滑器
date: 2024-11-18 21:36:49
tags: [题解, LeetCode, 简单, 数组, 矩阵, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】661.图片平滑器：模拟

力扣题目链接：[https://leetcode.cn/problems/image-smoother/](https://leetcode.cn/problems/image-smoother/)

<p><strong>图像平滑器</strong> 是大小为&nbsp;<code>3 x 3</code> 的过滤器，用于对图像的每个单元格平滑处理，平滑处理后单元格的值为该单元格的平均灰度。</p>

<p>每个单元格的<strong>&nbsp; 平均灰度</strong> 定义为：该单元格自身及其周围的 8 个单元格的平均值，结果需向下取整。（即，需要计算蓝色平滑器中 9 个单元格的平均值）。</p>

<p>如果一个单元格周围存在单元格缺失的情况，则计算平均灰度时不考虑缺失的单元格（即，需要计算红色平滑器中 4 个单元格的平均值）。</p>

<p><img src="https://assets.leetcode.com/uploads/2021/05/03/smoother-grid.jpg" style="height: 493px; width: 493px;" /></p>

<!-- https://i-blog.csdnimg.cn/direct/c0079440db3d44c182a1a7505fa91db1.png -->

<p>给你一个表示图像灰度的 <code>m x n</code> 整数矩阵 <code>img</code> ，返回对图像的每个单元格平滑处理后的图像&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2021/05/03/smooth-grid.jpg" /></p>
<!-- ![在这里插入图片描述](https://i-blog.csdnimg.cn/direct/0535b69bc6c343f3a2e3caa5c747939c.png) -->

<pre>
<strong>输入:</strong>img = [[1,1,1],[1,0,1],[1,1,1]]
<strong>输出:</strong>[[0, 0, 0],[0, 0, 0], [0, 0, 0]]
<strong>解释:</strong>
对于点 (0,0), (0,2), (2,0), (2,2): 平均(3/4) = 平均(0.75) = 0
对于点 (0,1), (1,0), (1,2), (2,1): 平均(5/6) = 平均(0.83333333) = 0
对于点 (1,1): 平均(8/9) = 平均(0.88888889) = 0
</pre>

<p><strong>示例 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/03/smooth2-grid.jpg" />
<!-- ![在这里插入图片描述](https://i-blog.csdnimg.cn/direct/48d226238db34b39bbf7712fe4791185.png) -->
<pre>
<strong>输入:</strong> img = [[100,200,100],[200,50,200],[100,200,100]]
<strong>输出:</strong> [[137,141,137],[141,138,141],[137,141,137]]
<strong>解释:</strong>
对于点 (0,0), (0,2), (2,0), (2,2): floor((100+200+200+50)/4) = floor(137.5) = 137
对于点 (0,1), (1,0), (1,2), (2,1): floor((200+200+50+200+100+100)/6) = floor(141.666667) = 141
对于点 (1,1): floor((50+200+200+200+200+100+100+100+100)/9) = floor(138.888889) = 138
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>m == img.length</code></li>
	<li><code>n == img[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>0 &lt;= img[i][j] &lt;= 255</code></li>
</ul>


    
## 解题方法：模拟

依次枚举每个元素，对于某个元素枚举其3x3矩阵（若超出边界则跳过）。按题目要求，对边界问题细心一点并计算即可。

+ 时间复杂度$O(mnC^2)$
+ 空间复杂度$O(1)$：力扣返回值不计入算法空间复杂度

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans(img.size(), vector<int>(img[0].size()));
        for (int i = 0; i < img.size(); i++) {
            for (int j = 0; j < img[0].size(); j++) {
                int cnt = 0, s = 0;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        int nx = i + x, ny = j + y;
                        if (0 <= nx && nx < img.size() && 0 <= ny && ny < img[0].size()) {
                            s += img[nx][ny];
                            cnt++;
                        }
                    }
                }
                ans[i][j] = s / cnt;
            }
        }
        return ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        ans = [[0 for _ in range(len(img[0]))] for _ in range(len(img))]
        for i in range(len(img)):
            for j in range(len(img[0])):
                cnt, s = 0, 0
                for dx in range(-1, 2):
                    for dy in range(-1, 2):
                        x, y = i + dx, j + dy
                        if 0 <= x < len(img) and 0 <= y < len(img[0]):
                            cnt += 1
                            s += img[x][y]
                ans[i][j] = s // cnt
        return ans
```

#### Java

```java
class Solution {
    public int[][] imageSmoother(int[][] img) {
        int[][] ans = new int[img.length][img[0].length];
        for (int i = 0; i < img.length; i++) {
            for (int j = 0; j < img[0].length; j++) {
                int cnt = 0, s = 0;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        int x = i + dx, y = j + dy;
                        if (0 <= x && x < img.length && 0 <= y && y < img[0].length) {
                            cnt++;
                            s += img[x][y];
                        }
                    }
                }
                ans[i][j] = s / cnt;
            }
        }
        return ans;
    }
}
```

#### Go

```go
package main

func imageSmoother(img [][]int) (ans [][]int) {
    ans = make([][]int, len(img))
    for i := range ans {
        ans[i] = make([]int, len(img[0]))
        for j := range ans[i] {
            cnt, s := 0, 0
            for _, row := range img[max(0, i - 1):min(len(img), i + 2)] {
                for _, val := range row[max(0, j - 1):min(len(img[0]), j + 2)] {
                    cnt++
                    s += val
                }
            }
            ans[i][j] = s / cnt
        }
    }
    return ans
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/11/18/LeetCode%200661.%E5%9B%BE%E7%89%87%E5%B9%B3%E6%BB%91%E5%99%A8/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143867615](https://letmefly.blog.csdn.net/article/details/143867615)
