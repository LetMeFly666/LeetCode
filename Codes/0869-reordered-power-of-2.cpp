/*
 * @Author: LetMeFly
 * @Date: 2021-10-28 20:53:35
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-10-28 20:56:37
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
    bool reorderedPowerOf2(int n) {
        unordered_map<string, bool> could;
        for (int i = 0; i <= 30; i++) {
            could[to_string(1 << i)] = true;
        }
        string s = to_string(n);
        sort(s.begin(), s.end());
        if (could[s]) return true;
        while(next_permutation(s.begin(), s.end())) {
            // dbg(s); //************
            if (could[s]) {
                return true;
            }
        }
        return false;
    }
};