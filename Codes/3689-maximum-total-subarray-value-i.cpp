/*
 * @Author: LetMeFly
 * @Date: 2026-06-10 00:27:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-10 00:27:32
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll maxTotalValue(vector<int>& nums, ll k) {
        int m = nums[0], M = m;
        for (int t : nums) {
            m = min(m, t);
            M = max(M, t);
        }
        return (M - m) * k;
    }
};
