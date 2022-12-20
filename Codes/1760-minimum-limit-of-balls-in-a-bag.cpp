/*
 * @Author: LetMeFly
 * @Date: 2022-12-20 22:52:45
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-20 22:55:05
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int& t : nums) {
                cnt += (t - 1) / mid;
            }
            if (cnt <= maxOperations)
                r = mid;
            else
                l = mid + 1;
        }
        return r;
    }
};