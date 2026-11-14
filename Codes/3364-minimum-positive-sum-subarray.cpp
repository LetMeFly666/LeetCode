/*
 * @Author: LetMeFly
 * @Date: 2026-11-14 12:58:04
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-14 16:35:50
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
            for (int len = 0; len < l - 1 && i + len < n; len++) {
                cnt += nums[i + len];
            }
            for (int len = l - 1; len < r && i + len < n; len++) {
                cnt += nums[i + len];
                if (cnt > 0) {
                    ans = min(ans, cnt);
                }
            }
        }
        return ans == 1000000 ? -1 : ans;
    }
};
