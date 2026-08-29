/*
 * @Author: LetMeFly
 * @Date: 2026-08-29 11:00:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-29 11:05:44
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        for (int i = 1, n = nums.size(), m = nums[0], M = nums[0], from = 0; i <= n; i++) {
            if (i == n || abs(nums[i] - m) > limit && abs(nums[i] - M) > limit) {
                sort(nums.begin() + from, nums.begin() + i);
                m = nums[i], M = nums[i], from = i;
            } else {
                m = min()
            }
        }
    }
};
