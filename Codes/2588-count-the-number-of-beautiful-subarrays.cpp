/*
 * @Author: LetMeFly
 * @Date: 2025-03-06 16:13:50
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-06 16:32:08
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;

class Solution {
private:
    unordered_map<int, int> times;
public:
    ll beautifulSubarrays(vector<int>& nums) {
        times[0] = 1;
        int val = 0;
        ll ans = 0;
        for (int t : nums) {
            val ^= t;
            ans += times[val];
            // printf("val = %d, times[%d] = %d, ans = %d\n", val, val, times[val], ans);  //*******
            times[val]++;
        }
        return ans;
    }
};