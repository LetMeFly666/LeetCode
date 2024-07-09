/*
 * @Author: LetMeFly
 * @Date: 2024-07-10 00:16:30
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-10 00:18:21
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool isOk(vector<int>& nums, int l, int r) {
        int last = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (l <= i && i <= r) {
                continue;
            }
            if (nums[i] <= last) {
                return false;
            }
            last = nums[i];
        }
        return true;
    }
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int ans = 0;
        for (int l = 0; l < nums.size(); l++) {
            for (int r = l; r < nums.size(); r++) {
                ans += isOk(nums, l, r);
            }
        }
        return ans;
    }
};