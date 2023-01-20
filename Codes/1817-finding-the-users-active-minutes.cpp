/*
 * @Author: LetMeFly
 * @Date: 2023-01-20 09:15:50
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-01-20 09:31:24
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, set<int>> ma;  // 其实这里可以使用unordered_map<int, unordered_set<int>>
        for (auto& log : logs) {
            ma[log[0]].insert(log[1]);
        }
        vector<int> ans(k);
        for (auto a : ma) {
            ans[a.second.size() - 1]++;
        }
        return ans;
    }
};