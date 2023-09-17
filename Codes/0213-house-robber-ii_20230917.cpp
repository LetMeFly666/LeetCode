/*
 * @Author: LetMeFly
 * @Date: 2023-09-17 15:56:41
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-09-17 16:01:23
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int realRob(vector<int>& nums, int l, int r) {
        int lastRob = nums[l], lastNot = 0;
        for (int i = l + 1; i < r; i++) {
            int newRob = lastNot + nums[i], newNot = max(lastRob, lastNot);
            lastRob = newRob, lastNot = newNot;
        }
        return max(lastRob, lastNot);
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        return max(realRob(nums, 0, nums.size() - 1), realRob(nums, 1, nums.size()));
    }
};