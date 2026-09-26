/*
 * @Author: LetMeFly
 * @Date: 2026-05-14 05:27:02
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-14 05:40:27
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0, n = nums.size(); i < n - 1; i++) {
            if (nums[i] != i + 1) {
                return false;
            }
        }
        if (nums.back() != nums.size() - 1) {
            return false;
        }
        return true;
    }
};
