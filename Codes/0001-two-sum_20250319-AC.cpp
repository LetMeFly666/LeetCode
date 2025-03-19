/*
 * @Author: LetMeFly
 * @Date: 2025-03-19 22:13:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-19 22:14:46
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ma;
        for (int i = 0; i < nums.size(); i++) {
            if (ma.count(target - nums[i])) {
                return {i, ma[target - nums[i]]};
            }
            ma[nums[i]] = i;
        }
        return {};  // FAKE RETURN
    }
};