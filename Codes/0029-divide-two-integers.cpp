/*
 * @Author: LetMeFly
 * @Date: 2021-10-12 11:07:15
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-10-12 11:09:56
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
// typedef long long ll;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend==-2147483648&&divisor==-1)return 2147483647;
        return dividend / divisor;
    }
};