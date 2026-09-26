/*
 * @Author: LetMeFly
 * @Date: 2026-05-14 05:27:02
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-14 05:42:41
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

// THIS CANNOT BE ACCEPTED
// THIS IS FOR n只出现1次的全排列
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        for (int t : nums) {
            t = t < 0 ? -t : t;
            if (t > n || t == 0) {
                return false;
            }
            if (nums[t - 1] < 0) {
                return false;
            }
            nums[t - 1] = -nums[t - 1];
        }
        return true;
    }
};
