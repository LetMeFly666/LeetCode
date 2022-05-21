/*
 * @Author: LetMeFly
 * @Date: 2021-11-07 08:19:56
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-11-07 08:19:57
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
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (vector<int>& v : ops) {
            m = min(m, v[0]);
            n = min(n, v[1]);
        }
        return m * n;
    }
};