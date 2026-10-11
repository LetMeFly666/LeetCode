/*
 * @Author: LetMeFly
 * @Date: 2026-10-11 09:02:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-11 09:03:46
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans = 0;
        for (int i = 0, n = nums.size(); i < n; i++) {
            if (n % (i + 1) == 0) {
                ans += nums[i] * nums[i];
            }
        }
        return ans;
    }
};
