/*
 * @Author: LetMeFly
 * @Date: 2026-09-23 18:44:45
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-23 18:46:33
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int allVal = accumulate(nums.begin(), nums.end(), 0);
        x = allVal - x;
        int ans = 10000000;
        for (int l = 0, r = 0, n = nums.size(), cnt = 0; r < n; r++) {
            cnt += nums[r];
            while (cnt > x) {
                cnt -= nums[l++];
            }
            if (cnt == x) {
                ans = min(ans, n - (r - l + 1));
            }
        }
        return ans == 10000000 ? -1 : ans;
    }
};
