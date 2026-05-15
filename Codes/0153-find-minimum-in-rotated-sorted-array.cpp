/*
 * @Author: LetMeFly
 * @Date: 2026-05-15 21:04:02
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-15 22:00:30
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size();  // 左闭右开
        while (l < r) {
            int m = (l + r) >> 1;
            if (nums[m] > nums.back()) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
};
