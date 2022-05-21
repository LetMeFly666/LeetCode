/*
 * @Author: LetMeFly
 * @Date: 2021-10-08 07:44:24
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-10-08 07:50:08
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
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int>ma;
        for (int i = 9; i < s.size(); i++) {
            ma[s.substr(i - 9, 10)]++;
        }
        vector<string>ans;
        for (auto &it : ma) {
            if (it.second > 1) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};