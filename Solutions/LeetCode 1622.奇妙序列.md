---
title: 1622.奇妙序列：懒更新
date: 2026-03-15 11:27:36
tags: [题解, LeetCode, 困难, 设计, 线段树, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】1622.奇妙序列：懒更新

力扣题目链接：[https://leetcode.cn/problems/fancy-sequence/](https://leetcode.cn/problems/fancy-sequence/)

<p>请你实现三个 API <code>append</code>，<code>addAll</code> 和 <code>multAll</code> 来实现奇妙序列。</p>

<p>请实现 <code>Fancy</code> 类 ：</p>

<ul>
	<li><code>Fancy()</code> 初始化一个空序列对象。</li>
	<li><code>void append(val)</code> 将整数 <code>val</code> 添加在序列末尾。</li>
	<li><code>void addAll(inc)</code> 将所有序列中的现有数值都增加 <code>inc</code> 。</li>
	<li><code>void multAll(m)</code> 将序列中的所有现有数值都乘以整数 <code>m</code> 。</li>
	<li><code>int getIndex(idx)</code> 得到下标为 <code>idx</code> 处的数值（下标从 0 开始），并将结果对 <code>10<sup>9</sup> + 7</code> 取余。如果下标大于等于序列的长度，请返回 <code>-1</code> 。</li>
</ul>

<p> </p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["Fancy", "append", "addAll", "append", "multAll", "getIndex", "addAll", "append", "multAll", "getIndex", "getIndex", "getIndex"]
[[], [2], [3], [7], [2], [0], [3], [10], [2], [0], [1], [2]]
<strong>输出：</strong>
[null, null, null, null, null, 10, null, null, null, 26, 34, 20]

<strong>解释：</strong>
Fancy fancy = new Fancy();
fancy.append(2);   // 奇妙序列：[2]
fancy.addAll(3);   // 奇妙序列：[2+3] -> [5]
fancy.append(7);   // 奇妙序列：[5, 7]
fancy.multAll(2);  // 奇妙序列：[5*2, 7*2] -> [10, 14]
fancy.getIndex(0); // 返回 10
fancy.addAll(3);   // 奇妙序列：[10+3, 14+3] -> [13, 17]
fancy.append(10);  // 奇妙序列：[13, 17, 10]
fancy.multAll(2);  // 奇妙序列：[13*2, 17*2, 10*2] -> [26, 34, 20]
fancy.getIndex(0); // 返回 26
fancy.getIndex(1); // 返回 34
fancy.getIndex(2); // 返回 20
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= val, inc, m <= 100</code></li>
	<li><code>0 <= idx <= 10<sup>5</sup></code></li>
	<li>总共最多会有 <code>10<sup>5</sup></code> 次对 <code>append</code>，<code>addAll</code>，<code>multAll</code> 和 <code>getIndex</code> 的调用。</li>
</ul>


    
## 解题方法：懒加载

**先看加法**

假设这道题只有加法操作没有乘法操作，应该怎么做？每次`addAll`操作都把所有数加上个$inc$？太耗时了，时间复杂度直接干到了$O(n^2)$。

所以我们很容易想到懒加载，`addAll`操作到时候不真的加，只有`getIndex`读取一个数的时候再一块加上。使用一个变量$add$存储每个数应该加上多少就可以了。

但是`append`操作呢？新`append`的$m$发生在之前的`addAll`之后，$m$不应该加上已经累积的$add$。所以`append`的时候直接把$m$减去$add$再加入数组中就可以了，这样读取到时候剪去的$add$还会再加回来。

**加上乘法**

乘法操作也类似，使用一个变量$mul$记录每个数应该乘以多少就好了。但是注意：

> 例如一个数$a$应有的操作是：$(a+add)\times mul$，那么其实相当于$a\times mul + add\times mul$。（令$add_{new}=add\times mul$则相当于$a\times mul + add_{new}$）

所以乘法操作时不但需要累乘$mul$，还要将加数$add$也乘上$mul$变成新的加数$add$。

但是`append`操作呢？和只有加法时候同理，由于`getIndex`读数时需要$a\times mul+add$，所以`append`$val$的时候提前剪去$add$再除以$mul$就好了，即`append`一个$\frac{val-add}{mul}$。

**模运算**

好在模运算具有分配律，$(a+b)\% MOD = (a \% MOD + b\% MOD)\% MOD，$所以可以在加减乘除运算过程中多次取模结果不变。

> 注意质数模运算下的除法中，$a$除以$b$对质数$MOD$取模等于$a$乘以$b$对$MOD$的逆元，即$\frac{a}{b}\mod MOD = a\times b^{MOD-2}\mod MOD$，而$b^{x}$可以使用快速幂在$\log x$的时间复杂度内求出。

+ 时间复杂度：append操作$O(\log MOD)$，其他操作$O(1)$
+ 空间复杂度$O(a)$，其中$a$是append的次数

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-03-15 11:19:41
 */
typedef long long ll;
const ll MOD = 1e9 + 7;


class Num {
private:
    ll val;

    ll power(ll a, ll n) const {
        ll ans = 1;
        for (; n; n >>= 1) {
            if (n & 1) {
                ans = ans * a % MOD;
            }
            a = a * a % MOD;
        }
        return ans;
    }
public:
    Num(): val(0) {}  // 记得初始化val
    Num(ll n) : val(n % MOD) {}
    Num(int n) : val(n % MOD) {}
    Num operator+(const ll& b) const { return Num((val + b) % MOD); }
    Num operator-(const ll& b) const { return Num((val - b + MOD) % MOD); }
    Num operator*(const ll& b) const { return Num(val * b % MOD); }
    Num operator/(const ll& b) const { return Num(val * power(b, MOD - 2) % MOD); }
    Num operator+(const Num& b) const { return Num((val + b.val) % MOD); }
    Num operator-(const Num& b) const { return Num((val - b.val + MOD) % MOD); }
    Num operator*(const Num& b) const { return Num(val * b.val % MOD); }
    Num operator/(const Num& b) const { return Num(val * power(b.val, MOD - 2) % MOD); }
    Num& operator+=(const ll& b) { return *this = *this + b; }
    Num& operator-=(const ll& b) { return *this = *this - b; }
    Num& operator*=(const ll& b) { return *this = *this * b; }
    Num& operator/=(const ll& b) { return *this = *this / b; }
    operator int() const { return static_cast<int>(val); }
};

class Fancy {
private:
    vector<Num> vals;
    Num add;
    Num mul;
public:
    Fancy() {
        mul = Num(1);
    }
    
    void append(int val) {
        vals.push_back((Num(val) - add) / mul);
    }
    
    void addAll(int inc) {
        add += inc;
    }
    
    void multAll(int m) {
        add *= m;
        mul *= m;
    }
    
    int getIndex(int idx) {
        return idx >= vals.size() ? -1 : (int)(vals[idx] * mul + add);
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
#ifdef _DEBUG
/*
["Fancy","append","addAll","append","multAll","getIndex","addAll","append","multAll","getIndex","getIndex","getIndex"]
[[],[2],[3],[7],[2],[0],[3],[10],[2],[0],[1],[2]]

*/
int main() {
    string a, b;
    while (cin >> a >> b) {
        vector<string> va = stringToVectorString(a);
        vector<vector<int>> vb = stringToVectorVector(b);
        if (va.size() != vb.size()) {
            cout << "ERROR length" << endl;
            continue;
        }
        Fancy fancy;
        for (int i = 0; i < va.size(); i++) {
            string s = va[i];
            if (!s.empty() && s[0] == '"') {
                s.erase(s.begin());
            }
            if (!s.empty() && s.back() == '"') {
                s.erase(prev(s.end()));
            }
            int val = vb[i].empty() ? 0 : vb[i][0];
            if (s == "Fancy") {
                fancy = Fancy();
            } else if (s == "append") {
                fancy.append(val);
            } else if (s == "addAll") {
                fancy.addAll(val);
            } else if (s == "multAll") {
                fancy.multAll(val);
            } else if (s == "getIndex") {
                cout << fancy.getIndex(val) << endl;
            } else {
                cout << "ERROR" << endl;
            }
        }
    }
    return 0;
}
#endif
```

#### Python

```python
'''
LastEditTime: 2026-03-15 11:25:58
'''
MOD = 1000000007

class Fancy:
    def __init__(self):
        self.add = 0
        self.mul = 1
        self.vals = []

    def append(self, val: int) -> None:
        self.vals.append((val - self.add + MOD) * pow(self.mul, -1, MOD) % MOD)

    def addAll(self, inc: int) -> None:
        self.add = (self.add + inc) % MOD

    def multAll(self, m: int) -> None:
        self.add = self.add * m % MOD
        self.mul = self.mul * m % MOD

    def getIndex(self, idx: int) -> int:
        if idx >= len(self.vals):
            return -1
        return (self.vals[idx] * self.mul + self.add) % MOD


# Your Fancy object will be instantiated and called as such:
# obj = Fancy()
# obj.append(val)
# obj.addAll(inc)
# obj.multAll(m)
# param_4 = obj.getIndex(idx)
```

这道题也可以使用线段树来做。

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/159079979)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/03/15/LeetCode%201622.%E5%A5%87%E5%A6%99%E5%BA%8F%E5%88%97/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
