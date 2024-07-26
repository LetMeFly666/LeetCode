/*
 * @Author: LetMeFly
 * @Date: 2024-07-26 15:16:01
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-26 15:18:45
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 1'000'000'000;
        for (int i = 1; i < nums.size(); i++) {
            ans = min(ans, abs(nums[i] - nums[i - 1]));
        }
        return ans;
    }
};