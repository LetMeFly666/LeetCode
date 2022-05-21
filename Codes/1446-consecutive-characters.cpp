/*
 * @Author: LetMeFly
 * @Date: 2021-12-01 22:00:16
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-12-01 22:01:49
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
    int maxPower(string s) {
        s += '-';
        int ans = 1;
        int lastLoc = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[i - 1]) {
                ans = max(ans, i - lastLoc);
                lastLoc = i;
            }
        }
        return ans;
    }
};