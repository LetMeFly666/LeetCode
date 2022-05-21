/*
 * @Author: LetMeFly
 * @Date: 2021-11-09 10:50:31
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-11-09 10:58:24
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
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length()) return false;
        if (s.length() == 1) return false;
        int diffLoc[2];
        int cnt = 0;
        int num[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != goal[i]) {
                if (cnt == 2) return false; // 已经两个了，第三个不行
                diffLoc[cnt++] = i;
            }
            num[s[i] - 'a']++;
        }
        if (cnt == 0) {
            for (int i = 0; i < 26; i++) {
                if (num[i] > 1) return true;
            }
            return false;
        }
        if (cnt == 1) return false;
        if (s[diffLoc[0]] == goal[diffLoc[1]] && s[diffLoc[1]] == goal[diffLoc[0]]) return true;
        return false;
    }
};