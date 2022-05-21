/*
 * @Author: LetMeFly
 * @Date: 2021-10-22 23:17:54
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-10-22 23:19:14
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
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> ma;
        for (int &t: nums) {
            ma[t]++;
        }
        int ban = nums.size() / 3;
        vector<int> ans;
        for (auto &it: ma) {
            if (it.second > ban) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};