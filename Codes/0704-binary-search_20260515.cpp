/*
 * @Author: LetMeFly
 * @Date: 2026-05-15 21:30:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-15 21:31:25
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int m = (l + r) >> 1;
            if (nums[m] < target) {
                l = m + 1;
            } else if (nums[m] == target) {
                return m;
            } else {
                r = m;
            }
        }
        return -1;
    }
};
