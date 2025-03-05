/*
 * @Author: LetMeFly
 * @Date: 2025-03-05 22:52:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-05 23:01:32
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int l = 0, r = 0; r < nums.size(); l++) {
            while (l < nums.size() && nums[l]) {  // 到第一个0
                l++;
            }
            if (l == nums.size()) {
                break;
            }
            r = l + 1;
            while (r < nums.size() && !nums[r]) {  // 到第一个非零
                r++;
            }
            if (r == nums.size()) {
                break;
            }
            swap(nums[l], nums[r]);
        }
    }
};