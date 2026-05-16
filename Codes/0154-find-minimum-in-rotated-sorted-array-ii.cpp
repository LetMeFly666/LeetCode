/*
 * @Author: LetMeFly
 * @Date: 2026-05-16 20:33:53
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-16 20:39:17
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size();
        while (l < r) {
            int m = (l + r) >> 1;
            if (nums[m] == nums[r]) {
                r--;
            } else if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return nums[r];
    }
};
