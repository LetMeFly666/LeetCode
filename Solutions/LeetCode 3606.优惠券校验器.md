---
title: 3606.优惠券校验器：分类 + 排序
date: 2025-12-13 22:44:25
tags: [题解, LeetCode, 简单, 数组, 字符串, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】3606.优惠券校验器：分类 + 排序

力扣题目链接：[https://leetcode.cn/problems/coupon-code-validator/](https://leetcode.cn/problems/coupon-code-validator/)

<p>给你三个长度为 <code>n</code> 的数组，分别描述 <code>n</code> 个优惠券的属性：<code>code</code>、<code>businessLine</code> 和 <code>isActive</code>。其中，第 <code>i</code> 个优惠券具有以下属性：</p>

<ul>
	<li><code>code[i]</code>：一个 <strong>字符串</strong>，表示优惠券的标识符。</li>
	<li><code>businessLine[i]</code>：一个 <strong>字符串</strong>，表示优惠券所属的业务类别。</li>
	<li><code>isActive[i]</code>：一个 <strong>布尔值</strong>，表示优惠券是否当前有效。</li>
</ul>

<p>当以下所有条件都满足时，优惠券被认为是&nbsp;<strong>有效的&nbsp;</strong>：</p>

<ol>
	<li><code>code[i]</code> 不能为空，并且仅由字母数字字符（a-z、A-Z、0-9）和下划线（<code>_</code>）组成。</li>
	<li><code>businessLine[i]</code> 必须是以下四个类别之一：<code>"electronics"</code>、<code>"grocery"</code>、<code>"pharmacy"</code>、<code>"restaurant"</code>。</li>
	<li><code>isActive[i]</code> 为 <strong>true&nbsp;</strong>。</li>
</ol>

<p>返回所有&nbsp;<strong>有效优惠券的标识符&nbsp;</strong>组成的数组，按照以下规则排序：</p>

<ul>
	<li>先按照其 <strong>businessLine</strong> 的顺序排序：<code>"electronics"</code>、<code>"grocery"</code>、<code>"pharmacy"</code>、<code>"restaurant"</code>。</li>
	<li>在每个类别内，再按照 <strong>标识符的字典序（升序）</strong>排序。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">code = ["SAVE20","","PHARMA5","SAVE@20"], businessLine = ["restaurant","grocery","pharmacy","restaurant"], isActive = [true,true,true,true]</span></p>

<p><strong>输出：</strong> <span class="example-io">["PHARMA5","SAVE20"]</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>第一个优惠券有效。</li>
	<li>第二个优惠券的标识符为空（无效）。</li>
	<li>第三个优惠券有效。</li>
	<li>第四个优惠券的标识符包含特殊字符 <code>@</code>（无效）。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">code = ["GROCERY15","ELECTRONICS_50","DISCOUNT10"], businessLine = ["grocery","electronics","invalid"], isActive = [false,true,true]</span></p>

<p><strong>输出：</strong> <span class="example-io">["ELECTRONICS_50"]</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>第一个优惠券无效，因为它未激活。</li>
	<li>第二个优惠券有效。</li>
	<li>第三个优惠券无效，因为其业务类别无效。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == code.length == businessLine.length == isActive.length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>0 &lt;= code[i].length, businessLine[i].length &lt;= 100</code></li>
	<li><code>code[i]</code> 和 <code>businessLine[i]</code> 由可打印的 ASCII 字符组成。</li>
	<li><code>isActive[i]</code> 的值为 <code>true</code> 或 <code>false</code>。</li>
</ul>


    
## 解题方法：分组 + 排序

> 分组/分类似乎差不多，暂不深究。

使用4个数组，分别存放合法的4类优惠券。最后对4个数组分别按字符串字典序排序，合并为一个数组并返回。

如何判断一个优惠券是否合法？

1. active为true
2. businessLine属于4类之一
3. code不为空且只由数组字母下划线组成

注意，C++中合并vector时若被合并vector后续无需再使用，则可以使用make_move_iterator在内存上移动。

+ 时间复杂度$O(L\log n)$，其中$L$是合法code总字符数
+ 空间复杂度：C++$O(L)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-12-13 22:42:29
 */
class Solution {
private:
    inline bool is_ok(string& s) {
        for (char c : s) {
            if (c != '_' && !isalnum(c)) {
                return false;
            }
        }
        return !s.empty();
    }
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> electronics, grocery, pharmacy, restaurant;
        for (int i = 0; i < code.size(); i++) {
            if (!isActive[i]) {
                continue;
            }
            if (!is_ok(code[i])) {
                continue;
            }
            if (businessLine[i] == "electronics") {
                electronics.push_back(code[i]);
            } else if (businessLine[i] == "grocery") {
                grocery.push_back(code[i]);
            } else if (businessLine[i] == "pharmacy") {
                pharmacy.push_back(code[i]);
            } else if (businessLine[i] == "restaurant") {
                restaurant.push_back(code[i]);
            }
        }
        sort(electronics.begin(), electronics.end());
        sort(grocery.begin(), grocery.end());
        sort(pharmacy.begin(), pharmacy.end());
        sort(restaurant.begin(), restaurant.end());
        vector<string> ans;
        ans.reserve(electronics.size() + grocery.size() + pharmacy.size() + restaurant.size());
        ans.insert(ans.end(), make_move_iterator(electronics.begin()), make_move_iterator(electronics.end()));
        ans.insert(ans.end(), make_move_iterator(grocery.begin()), make_move_iterator(grocery.end()));
        ans.insert(ans.end(), make_move_iterator(pharmacy.begin()), make_move_iterator(pharmacy.end()));
        ans.insert(ans.end(), make_move_iterator(restaurant.begin()), make_move_iterator(restaurant.end()));
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/155893803)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/12/13/LeetCode%203606.%E4%BC%98%E6%83%A0%E5%88%B8%E6%A0%A1%E9%AA%8C%E5%99%A8/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
