/*
 * @Author: LetMeFly
 * @Date: 2024-05-22 20:16:19
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-22 20:20:27
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        unordered_map<int, int> cnt;
        for (vector<int>& match : matches) {
            cnt[match[0]] += 0;
            cnt[match[1]]++;
        }
        for (auto&& [id, times] : cnt) {
            if (times == 0) {
                ans[0].push_back(id);
            }
            else if (times == 1) {
                ans[1].push_back(id);
            }
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};