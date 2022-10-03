---
title: AtCoder Regular Contest 149 - A - Repdigit Number
date: 2022-10-03 09:14:30
tags: [题解, AtCoder, 中等, 取模, 数学]
---

Time Limit: 2 sec / Memory Limit: 1024 MB

<span class="lang-en" style="display: inline;">
<p>Score : <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>300</mn></mrow><annotation encoding="application/x-tex">300</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.64444em; vertical-align: 0em;"></span><span class="mord">3</span><span class="mord">0</span><span class="mord">0</span></span></span></span></span></var> points</p>

<div class="part">
<section>
<h3>Problem Statement</h3><p>You are given positive integers <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>N</mi></mrow><annotation encoding="application/x-tex">N</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.68333em; vertical-align: 0em;"></span><span class="mord mathnormal" style="margin-right: 0.10903em;">N</span></span></span></span></span></var> and <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>M</mi></mrow><annotation encoding="application/x-tex">M</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.68333em; vertical-align: 0em;"></span><span class="mord mathnormal" style="margin-right: 0.10903em;">M</span></span></span></span></span></var>. Find the maximum positive integer <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>X</mi></mrow><annotation encoding="application/x-tex">X</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.68333em; vertical-align: 0em;"></span><span class="mord mathnormal" style="margin-right: 0.07847em;">X</span></span></span></span></span></var> that satisfies all of the following conditions.</p>
<ul>
<li><var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>X</mi></mrow><annotation encoding="application/x-tex">X</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.68333em; vertical-align: 0em;"></span><span class="mord mathnormal" style="margin-right: 0.07847em;">X</span></span></span></span></span></var> is a positive integer less than <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>1</mn><msup><mn>0</mn><mi>N</mi></msup></mrow><annotation encoding="application/x-tex">10^N</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.841331em; vertical-align: 0em;"></span><span class="mord">1</span><span class="mord"><span class="mord">0</span><span class="msupsub"><span class="vlist-t"><span class="vlist-r"><span class="vlist" style="height: 0.841331em;"><span class="" style="top: -3.063em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mathnormal mtight" style="margin-right: 0.10903em;">N</span></span></span></span></span></span></span></span></span></span></span></span></var>, and all digits in the decimal representation of <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>X</mi></mrow><annotation encoding="application/x-tex">X</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.68333em; vertical-align: 0em;"></span><span class="mord mathnormal" style="margin-right: 0.07847em;">X</span></span></span></span></span></var> are the same.</li>
<li><var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>X</mi></mrow><annotation encoding="application/x-tex">X</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.68333em; vertical-align: 0em;"></span><span class="mord mathnormal" style="margin-right: 0.07847em;">X</span></span></span></span></span></var> is a multiple of <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>M</mi></mrow><annotation encoding="application/x-tex">M</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.68333em; vertical-align: 0em;"></span><span class="mord mathnormal" style="margin-right: 0.10903em;">M</span></span></span></span></span></var>.</li>
</ul>
<p>If no positive integer <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>X</mi></mrow><annotation encoding="application/x-tex">X</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.68333em; vertical-align: 0em;"></span><span class="mord mathnormal" style="margin-right: 0.07847em;">X</span></span></span></span></span></var> satisfies the conditions, print <code>-1</code>.</p>
</section>
</div>

<div class="part">
<section>
<h3>Constraints</h3><ul>
<li><var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>1</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>1</mn><msup><mn>0</mn><mn>5</mn></msup></mrow><annotation encoding="application/x-tex">1\leq N\leq 10^5</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.78041em; vertical-align: -0.13597em;"></span><span class="mord">1</span><span class="mspace" style="margin-right: 0.277778em;"></span><span class="mrel">≤</span><span class="mspace" style="margin-right: 0.277778em;"></span></span><span class="base"><span class="strut" style="height: 0.8193em; vertical-align: -0.13597em;"></span><span class="mord mathnormal" style="margin-right: 0.10903em;">N</span><span class="mspace" style="margin-right: 0.277778em;"></span><span class="mrel">≤</span><span class="mspace" style="margin-right: 0.277778em;"></span></span><span class="base"><span class="strut" style="height: 0.814108em; vertical-align: 0em;"></span><span class="mord">1</span><span class="mord"><span class="mord">0</span><span class="msupsub"><span class="vlist-t"><span class="vlist-r"><span class="vlist" style="height: 0.814108em;"><span class="" style="top: -3.063em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight">5</span></span></span></span></span></span></span></span></span></span></span></span></var></li>
<li><var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>1</mn><mo>≤</mo><mi>M</mi><mo>≤</mo><mn>1</mn><msup><mn>0</mn><mn>9</mn></msup></mrow><annotation encoding="application/x-tex">1\leq M\leq 10^9</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.78041em; vertical-align: -0.13597em;"></span><span class="mord">1</span><span class="mspace" style="margin-right: 0.277778em;"></span><span class="mrel">≤</span><span class="mspace" style="margin-right: 0.277778em;"></span></span><span class="base"><span class="strut" style="height: 0.8193em; vertical-align: -0.13597em;"></span><span class="mord mathnormal" style="margin-right: 0.10903em;">M</span><span class="mspace" style="margin-right: 0.277778em;"></span><span class="mrel">≤</span><span class="mspace" style="margin-right: 0.277778em;"></span></span><span class="base"><span class="strut" style="height: 0.814108em; vertical-align: 0em;"></span><span class="mord">1</span><span class="mord"><span class="mord">0</span><span class="msupsub"><span class="vlist-t"><span class="vlist-r"><span class="vlist" style="height: 0.814108em;"><span class="" style="top: -3.063em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight">9</span></span></span></span></span></span></span></span></span></span></span></span></var></li>
</ul>
</section>
</div>

<hr>
<div class="io-style">
<div class="part">
<section>
<h3>Input</h3><p>The input is given from Standard Input in the following format:</p>
<pre><var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>N</mi></mrow><annotation encoding="application/x-tex">N</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.68333em; vertical-align: 0em;"></span><span class="mord mathnormal" style="margin-right: 0.10903em;">N</span></span></span></span></span></var> <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>M</mi></mrow><annotation encoding="application/x-tex">M</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.68333em; vertical-align: 0em;"></span><span class="mord mathnormal" style="margin-right: 0.10903em;">M</span></span></span></span></span></var>
</pre>
</section>
</div>

<div class="part">
<section>
<h3>Output</h3><p>Print the maximum positive integer <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>X</mi></mrow><annotation encoding="application/x-tex">X</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.68333em; vertical-align: 0em;"></span><span class="mord mathnormal" style="margin-right: 0.07847em;">X</span></span></span></span></span></var> that satisfies all of the conditions, or <code>-1</code> if no such positive integer <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>X</mi></mrow><annotation encoding="application/x-tex">X</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.68333em; vertical-align: 0em;"></span><span class="mord mathnormal" style="margin-right: 0.07847em;">X</span></span></span></span></span></var> exists.</p>
</section>
</div>
</div>

<hr>
<div class="part">
<section>
<h3>Sample Input 1 </h3>
<pre id="pre-sample10">7 12
</pre>
</section>
</div>

<div class="part">
<section>
<h3>Sample Output 1 </h3>
<pre id="pre-sample11">888888
</pre>
<p>Four positive integers <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>X</mi></mrow><annotation encoding="application/x-tex">X</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.68333em; vertical-align: 0em;"></span><span class="mord mathnormal" style="margin-right: 0.07847em;">X</span></span></span></span></span></var> satisfy the conditions: <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>444</mn><mo separator="true">,</mo><mn>888</mn><mo separator="true">,</mo><mn>444444</mn><mo separator="true">,</mo><mn>888888</mn></mrow><annotation encoding="application/x-tex">444, 888, 444444, 888888</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.83888em; vertical-align: -0.19444em;"></span><span class="mord">4</span><span class="mord">4</span><span class="mord">4</span><span class="mpunct">,</span><span class="mspace" style="margin-right: 0.166667em;"></span><span class="mord">8</span><span class="mord">8</span><span class="mord">8</span><span class="mpunct">,</span><span class="mspace" style="margin-right: 0.166667em;"></span><span class="mord">4</span><span class="mord">4</span><span class="mord">4</span><span class="mord">4</span><span class="mord">4</span><span class="mord">4</span><span class="mpunct">,</span><span class="mspace" style="margin-right: 0.166667em;"></span><span class="mord">8</span><span class="mord">8</span><span class="mord">8</span><span class="mord">8</span><span class="mord">8</span><span class="mord">8</span></span></span></span></span></var>. The answer is the maximum of them, which is <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>888888</mn></mrow><annotation encoding="application/x-tex">888888</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.64444em; vertical-align: 0em;"></span><span class="mord">8</span><span class="mord">8</span><span class="mord">8</span><span class="mord">8</span><span class="mord">8</span><span class="mord">8</span></span></span></span></span></var>.</p>
</section>
</div>

<hr>
<div class="part">
<section>
<h3>Sample Input 2 </h3>
<pre id="pre-sample12">9 12
</pre>
</section>
</div>

<div class="part">
<section>
<h3>Sample Output 2 </h3>
<pre id="pre-sample13">888888888
</pre>
<p>Six positive integers <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>X</mi></mrow><annotation encoding="application/x-tex">X</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.68333em; vertical-align: 0em;"></span><span class="mord mathnormal" style="margin-right: 0.07847em;">X</span></span></span></span></span></var> satisfy the conditions: <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>444</mn><mo separator="true">,</mo><mn>888</mn><mo separator="true">,</mo><mn>444444</mn><mo separator="true">,</mo><mn>888888</mn><mo separator="true">,</mo><mn>444444444</mn><mo separator="true">,</mo><mn>888888888</mn></mrow><annotation encoding="application/x-tex">444, 888, 444444, 888888, 444444444, 888888888</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.83888em; vertical-align: -0.19444em;"></span><span class="mord">4</span><span class="mord">4</span><span class="mord">4</span><span class="mpunct">,</span><span class="mspace" style="margin-right: 0.166667em;"></span><span class="mord">8</span><span class="mord">8</span><span class="mord">8</span><span class="mpunct">,</span><span class="mspace" style="margin-right: 0.166667em;"></span><span class="mord">4</span><span class="mord">4</span><span class="mord">4</span><span class="mord">4</span><span class="mord">4</span><span class="mord">4</span><span class="mpunct">,</span><span class="mspace" style="margin-right: 0.166667em;"></span><span class="mord">8</span><span class="mord">8</span><span class="mord">8</span><span class="mord">8</span><span class="mord">8</span><span class="mord">8</span><span class="mpunct">,</span><span class="mspace" style="margin-right: 0.166667em;"></span><span class="mord">4</span><span class="mord">4</span><span class="mord">4</span><span class="mord">4</span><span class="mord">4</span><span class="mord">4</span><span class="mord">4</span><span class="mord">4</span><span class="mord">4</span><span class="mpunct">,</span><span class="mspace" style="margin-right: 0.166667em;"></span><span class="mord">8</span><span class="mord">8</span><span class="mord">8</span><span class="mord">8</span><span class="mord">8</span><span class="mord">8</span><span class="mord">8</span><span class="mord">8</span><span class="mord">8</span></span></span></span></span></var>.</p>
</section>
</div>

<hr>
<div class="part">
<section>
<h3>Sample Input 3 </h3>
<pre id="pre-sample14">1 3
</pre>
</section>
</div>

<div class="part">
<section>
<h3>Sample Output 3 </h3>
<pre id="pre-sample15">9
</pre>
<p>Three positive integers <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>X</mi></mrow><annotation encoding="application/x-tex">X</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.68333em; vertical-align: 0em;"></span><span class="mord mathnormal" style="margin-right: 0.07847em;">X</span></span></span></span></span></var> satisfy the conditions: <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>3</mn><mo separator="true">,</mo><mn>6</mn><mo separator="true">,</mo><mn>9</mn></mrow><annotation encoding="application/x-tex">3, 6, 9</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.83888em; vertical-align: -0.19444em;"></span><span class="mord">3</span><span class="mpunct">,</span><span class="mspace" style="margin-right: 0.166667em;"></span><span class="mord">6</span><span class="mpunct">,</span><span class="mspace" style="margin-right: 0.166667em;"></span><span class="mord">9</span></span></span></span></span></var>.</p>
</section>
</div>

<hr>
<div class="part">
<section>
<h3>Sample Input 4 </h3>
<pre id="pre-sample16">1000 25
</pre>
</section>
</div>

<div class="part">
<section>
<h3>Sample Output 4 </h3>
<pre id="pre-sample17">-1
</pre>
<p>No positive integers <var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>X</mi></mrow><annotation encoding="application/x-tex">X</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.68333em; vertical-align: 0em;"></span><span class="mord mathnormal" style="margin-right: 0.07847em;">X</span></span></span></span></span></var> satisfy the conditions.</p>
</section>
</div>

<hr>
<div class="part">
<section>
<h3>Sample Input 5 </h3>
<pre id="pre-sample18">30 1
</pre>
</section>
</div>

<div class="part">
<section>
<h3>Sample Output 5 </h3>
<pre id="pre-sample19">999999999999999999999999999999
</pre></section>
</div>
</span>


# 题目大意

给你两个正整数$N$和$M$，让你找到最大的 形如```11111...1```的数，其中这个数不大于$N$，并且这个数能被$M$整除




# 解题思路

首先想想怎么暴力。暴力的话，Python自带大整数，而C++则需要手写高精度。

以数字1为例，那么暴力无非就是：

+ 从```1```开始尝试，接着尝试```11```、```111```、```...```、```1111...1```，看看哪个数能整除$M$。如果能整除$M$，就更新答案的最大值。

但是这样肯定超时，因为$N$的最大值是$10^5$，也就是说最多尝试到```1111...1```(100000个1)。

构造出这个有100000个1的数字，再让它除以$M$，光是这一步的时间复杂度就是$O(N)$了

从$1$个1到$N$个1,时间复杂度同样是$O(N)$，因此，总时间复杂度为$O(N^2)$。

**那么，有没有一种办法，能够优化一个维度呢？有没有办法不适用大整数，而是直接使用64位整数（如C语言的long long）存下整个运算过程的结果呢？**

这让我们想到了取模。

取模有以下两种性质：

1. $(x+y)\% MOD = ((x \% MOD) +(y\% MOD))\%MOD$
1. $(x\times y)\% MOD = ((x \% MOD) \times (y\% MOD))\%MOD$

说人话就是：加法和乘法运算不改变取模结果。

取模好啊，取模后，就能用64位整数存下了。

在计算过111的基础上，有没有办法，在$O(1)$的时间复杂度内，计算出1111的结果呢？

$1111 = 111 * 10 + 1$，$1111 \% M = ((111 \% M) * 10 + 1) \% M$

同时，$111...1$能整除$M$，等价于$111...1 \% M = 0$

所以，问题解决啦！

先考虑```1```、```11```、```...```、```11...1```， 从```1```开始，然后在```1```的结果上计算```11```，再在```11```的基础上计算```111```，直到计算到$N$个```1```为止。

```cpp
for (int j = 0; j < n; j++) {
    num = num * 10 + i;
    num %= MOD;
    if (num == 0) {
        更新答案最大值，记录下来是j个i
    }
}
```

如果中间过程中，取模结果为0，那么就更新答案的最大值（记录下来是多少个几）

之后考虑```222...2```、```333..3```、```...```、```999..9```

最后输出$j$个$i$即可

总时间复杂度$O(N)$，空间复杂度$O(1)$

---



# AC代码
```cpp
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
int main() {
    int n, m;
    cin >> n >> m;
    int maxI = -1, maxJ = -1;
    for (int i = 1; i < 10; i++) {
        ll num = i;
        for (int j = 0; j < n; j++) {
            num %= m;
            if (num == 0) {
                if (j + 1 >= maxJ) {
                    maxI = i, maxJ = j + 1;
                }
            }
            num = num * 10 + i;
        }
    }
    if (maxI == -1) {
        puts("-1");
        return 0;
    }
    for (int i = 0; i < maxJ; i++) {
        putchar('0' + maxI);
    }
    return 0;
}
```


> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/10/03/AtCoder%20Regular%20Contest%20149%20-%20A%20-%20Repdigit%20Number/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127149808](https://letmefly.blog.csdn.net/article/details/127149808)