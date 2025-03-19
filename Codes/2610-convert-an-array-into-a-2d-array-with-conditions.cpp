/*
 * @Author: LetMeFly
 * @Date: 2025-03-19 19:54:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-19 19:55:17
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> cnt;
        for (int t : nums) {
            cnt[t]++;
            if (cnt[t] > ans.size()) {
                ans.push_back({});
            }
            ans[cnt[t] - 1].push_back(t);
        }
        return ans;
    }
};