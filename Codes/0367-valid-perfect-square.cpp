/*
 * @Author: LetMeFly
 * @Date: 2021-11-04 01:09:37
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-11-04 01:09:38
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
    bool isPerfectSquare(int num) {
        int k = sqrt(num);
        return k * k == num;
    }
};