/*
 * @Author: LetMeFly
 * @Date: 2026-10-23 20:28:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-23 20:30:31
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        if (nums[0]) {
            return 0;
        }
        int ans = -1;
        for (int i = 0, n = nums.size(); i < n; i++) {
            if (nums[i] != i) {
                ans &= i;
            }
        }
        return ans == -1 ? 0 : ans;
    }
};
