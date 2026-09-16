/*
 * @Author: LetMeFly
 * @Date: 2026-09-16 16:56:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-16 17:48:02
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
const ll MOD = 1e9 + 7;
ll rev[2001];
int _ = []() {}();


class Solution {
public:
    int numberOfSets(int n, int k) {
        // 长n-1，k条线，还有n-1-k长度可供使用
        // 这些长度可以放到k条线段上，也可以放到k条线段两边的k+1个空白位置
        // 问题变成了把n-1-k个东西放到2k+1个位置
        //
        // a个东西放b个位置有多少种方法？相当于a个东西插入b-1个隔板
        // 相当于a+b-1个位置其中选b-1个作为隔板，即C_{a+b-1}^{b-1}
        // 回到本题则是C_{n+k-1}^{2k}
        //
        // C_a^b = a(a-1)(a-2)...(a-b+1) / b(b-1)(b-2)...1
        //       = a/1 * (a-1)/2 * (a-2)/3 * ... * (a-b+1)/b
        // a/t相当于a*rev(t)相当于a*t^{MOD-2}
    }
};
