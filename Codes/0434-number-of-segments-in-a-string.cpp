/*
 * @Author: LetMeFly
 * @Date: 2021-10-07 14:25:29
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-10-07 14:29:21
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
    int countSegments(string s) {
        if (s.empty()) return 0;
        int ans = s[0] != ' ';
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != ' ' && s[i - 1] == ' ') {
                ans ++;
            }
        }
        return ans;
    }
};