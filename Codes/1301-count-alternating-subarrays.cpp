/*
 * @Author: LetMeFly
 * @Date: 2024-07-06 10:40:05
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-06 10:43:15
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans = 0;
        for (int from = 0, to = 1; to <= nums.size(); to++) {
            if (to == nums.size() || nums[to] == nums[to - 1]) {
                long long length = to - from;
                ans += (1 + length) * length / 2;
                from = to;
            }
        }
        return ans;
    }
};