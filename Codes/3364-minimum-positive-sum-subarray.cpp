/*
 * @Author: LetMeFly
 * @Date: 2026-11-14 12:58:04
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-14 12:59:55
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = 1000000;
        for (int i = 0, n = nums.size(); i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < l && i + j < n; j++) {
                cnt += nums[i + j];
            }
            for (int len = l; len <= r && i + len < n; len++) {
                cnt += nums[i + len];
                if (cnt > 0) {
                    ans = min(ans, cnt);
                }
            }
        }
        return ans == 1000000 ? -1 : ans;
    }
};
