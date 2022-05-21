/*
 * @Author: LetMeFly
 * @Date: 2021-09-18 13:17:14
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-09-18 13:17:14
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
class Solution
{
public:
    bool canWinNim(int n)
    {
        return n%4;
    }
};