/*
 * @Author: LetMeFly
 * @Date: 2021-10-30 12:23:07
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-10-30 12:24:30
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
    vector<int> singleNumber(vector<int>& nums) {
        map<int, int> ma;
        for (int &t : nums) {
            ma[t]++;
        }
        vector<int> ans;
        for (pair<int, int> it : ma) {
            if (it.second == 1) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};