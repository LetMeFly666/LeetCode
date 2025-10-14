/*
 * @Author: LetMeFly
 * @Date: 2025-10-14 20:14:45
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-14 20:18:02
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline bool isOk(vector<int>& nums, int i, int k) {
        while (--k) {
            if (nums[i] >= nums[++i]) {
                return false;
            } 
        }
        return true;
    }
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i + 2 * k <= n; i++) {
            if (isOk(nums, i, k) && isOk(nums, i + k, k)) {
                return true;
            }
        }
        return false;
    }
};