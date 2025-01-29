/*
 * @Author: LetMeFly
 * @Date: 2025-01-29 11:48:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-29 11:49:49
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> ma;
        for (int i = 0; i < nums.size(); i++) {
            if (ma.count(nums[i]) && i - ma[nums[i]] <= k) {
                return true;
            }
            ma[nums[i]] = i;
        }
        return false;
    }
};