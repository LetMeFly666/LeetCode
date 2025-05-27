/*
 * @Author: LetMeFly
 * @Date: 2025-05-27 23:28:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-27 23:34:08
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;

class Solution {
public:
    ll maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll odd = LLONG_MIN, even = 0;
        for (int t : nums) {
            ll newO = max(odd + t, even + (t ^ k));
            ll newE = max(even + t, odd + (t ^ k));
            odd = newO, even = newE;
        }
        return even;
    }
};