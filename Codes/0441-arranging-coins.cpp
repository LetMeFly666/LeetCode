/*
 * @Author: LetMeFly
 * @Date: 2021-10-10 13:37:11
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-10-10 13:40:13
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
class Solution {
public:
    int arrangeCoins(int n) {
        ll ans = 1;
        while(ans*(ans+1)/2<=n) ans++;
        return ans - 1;
    }
};