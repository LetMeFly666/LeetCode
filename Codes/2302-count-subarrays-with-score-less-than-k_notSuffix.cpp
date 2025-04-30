/*
 * @Author: LetMeFly
 * @Date: 2025-04-30 10:29:37
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-30 10:34:24
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        ll ans = 0, cnt = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            cnt += nums[r];
            while (cnt * (r - l + 1) >= k) {
                cnt -= nums[l++];
            }
            ans += (r - l + 1);
        }
        return ans;
    }
};