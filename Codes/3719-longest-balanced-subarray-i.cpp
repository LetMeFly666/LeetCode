/*
 * @Author: LetMeFly
 * @Date: 2026-02-10 22:34:37
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-10 22:35:48
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        for (int i = 0, n = nums.size(); i < n; i++) {
            int diff = 0;
            for (int j = i; j < n; j++) {
                diff += nums[i] % 2 ? 1 : -1;
                if (!diff) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};