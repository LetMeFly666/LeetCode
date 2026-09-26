/*
 * @Author: LetMeFly
 * @Date: 2026-04-12 23:06:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-04-12 23:09:14
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

const int inf = 200000;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = inf;
        unordered_map<int, vector<int>> cnt;
        for (int i = 0, n = nums.size(); i < n; i++) {
            cnt[nums[i]].push_back(i);
        }
        for (auto it = cnt.begin(); it != cnt.end(); it++) {
            for (int i = 0, n = it->second.size(); i + 2 < n; i++) {
                ans = min(ans, 2 * (it->second[i + 2] - it->second[i]));
            }
        }
        return ans == inf ? -1 : ans;
    }
};