/*
 * @Author: LetMeFly
 * @Date: 2023-11-24 10:00:19
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-24 10:01:51
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                ans += nums[i] + nums[j] < target;
            }
        }
        return ans;
    }
};