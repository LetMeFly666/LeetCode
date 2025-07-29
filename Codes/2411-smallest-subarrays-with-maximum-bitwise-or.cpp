/*
 * @Author: LetMeFly
 * @Date: 2025-07-29 23:42:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-29 23:51:37
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> ans(nums.size());
        vector<int> lastPos(31, -1);
        for (int i = nums.size() - 1; i >= 0; i--) {
            int last = i;
            for (int j = 0; j < 31; j++) {
                if (nums[i] >> j & 1) {
                    lastPos[j] = i;
                    continue;
                }
                if (lastPos[j] != -1) {
                    last = max(last, j);
                }
            }
            ans[i] = max(ans[i], last - i + 1);
        }
        return ans;
    }
};