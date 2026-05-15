/*
 * @Author: LetMeFly
 * @Date: 2026-05-15 21:04:02
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-15 21:11:35
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = -1, r = nums.size() - 1;
        while (l + 1 < r) {  // 左右开区间
            int m = (l + r) >> 1;
            if (nums[m] > nums.back()) {
                l = m;
            } else {
                r = m + 1;
            }
        }
    }
};
