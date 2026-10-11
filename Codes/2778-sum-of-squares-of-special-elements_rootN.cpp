/*
 * @Author: LetMeFly
 * @Date: 2026-10-11 09:11:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-11 09:16:18
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans = 0;
        size_t n = nums.size();
        size_t root = sqrt(n);
        for (int i = 1; i < root; i++) {
            if (n % i == 0) {
                ans += nums[i - 1] * nums[i - 1] + nums[n - i] * nums[n - i];
            }
        }
        if (root * root == n) {
            ans += nums[root - 1] * nums[root - 1];
        }
        return ans;
    }
};
