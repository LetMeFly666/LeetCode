/*
 * @Author: LetMeFly
 * @Date: 2026-09-16 16:56:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-17 08:33:08
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
const ll MOD = 1e9 + 7;
ll Jie[2001];
ll Rev[2001];

ll myPow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

// J[i] = J[i-1] * i
// R[i] = (J[i-1] * i)^-1 = J[i-1]^-1 * i^-1 = R[i-1] * i^-1
// R[i-1] = R[i] * i
int _ = []{
    Jie[0] = 1;
    for (int i = 1; i <= 2000; i++) {
        Jie[i] = Jie[i - 1] * i % MOD;
    }
    Rev[2000] = myPow(Jie[2000], MOD - 2);
    for (int i = 2000; i; i--) {
        Rev[i - 1] = Rev[i] * i % MOD;
    }
    return 0;
} ();


class Solution {
private:
    int C(ll a, ll b) {
        return (Jie[a] * Rev[a - b] % MOD) * Rev[b] % MOD;
    }
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
        //
        // 换种思路，C_a^b= a! / (a-b)!b!
        return C(n + k - 1, 2 * k);
    }
};
