/*
 * @Author: LetMeFly
 * @Date: 2021-08-13 13:10:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-13 13:11:36
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
// copy
class Solution
{
public:
    int countDigitOne(int n)
    {
        long long mulk = 1;
        int ans = 0;
        while (n >= mulk)
            ans += (n / (mulk * 10)) * mulk + min(max(n % (mulk * 10) - mulk + 1, 0LL), mulk), mulk *= 10;
        return ans;
    }
};