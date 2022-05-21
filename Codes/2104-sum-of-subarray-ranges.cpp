/*
 * @Author: LetMeFly
 * @Date: 2022-03-04 19:34:36
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-03-04 19:37:07
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
typedef long long ll;
#endif

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        ll ans = 0;
        for (int l = 0; l < nums.size(); l++) {
            int m = nums[l], M = nums[l];
            for (int r = l; r < nums.size(); r++) {  // [l, r]
                m = min(m, nums[r]);
                M = max(M, nums[r]);
                ans += M - m;
            }
        }
        return ans;
    }
};