/*
 * @Author: LetMeFly
 * @Date: 2024-01-30 11:52:25
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-01-30 12:00:08
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> ma;
        for (int i = 0; i < nums.size(); i++) {
            ma[nums[i]].push_back(i);
        }
        int ans = nums.size() - 1;
        for (auto&& [num, positions] : ma) {
            int thisMax = positions[0] + nums.size() - positions.back();
            for (int i = 1; i < positions.size(); i++) {
                thisMax = max(thisMax, positions[i] - positions[i - 1]);
            }
            ans = min(ans, thisMax / 2);
        }
        return ans;
    }
};