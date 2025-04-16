/*
 * @Author: LetMeFly
 * @Date: 2025-04-16 19:45:53
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-16 20:25:23
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;

class Solution {
public:
    ll countGood(vector<int>& nums, int k) {
        ll ans = 0;
        unordered_map<int, int> ma;
        ll now = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            now += ma[nums[r]]++;
            while (now >= k) {
                now -= --ma[nums[l++]];
            }
            ans += l;
        }
        return ans;
    }
};