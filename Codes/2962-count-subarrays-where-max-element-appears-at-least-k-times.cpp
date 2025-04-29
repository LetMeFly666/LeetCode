/*
 * @Author: LetMeFly
 * @Date: 2025-04-29 13:19:27
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-29 21:19:24
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = nums[0];
        for (int t : nums) {
            mx = max(mx, t);
        }
        ll ans = 0;
        for (int l = 0, r = 0, cnt = 0; r < nums.size(); r++) {
            cnt += nums[r] == mx;
            while (cnt == k) {
                cnt -= nums[l++] == mx;
            }
            ans += l;
        }
        return ans;
    }
};