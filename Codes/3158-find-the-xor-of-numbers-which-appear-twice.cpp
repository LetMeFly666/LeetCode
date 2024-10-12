/*
 * @Author: LetMeFly
 * @Date: 2024-10-12 14:28:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-12 14:29:26
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        long long ma = 0;
        int ans = 0;
        for (int t : nums) {
            if (ma >> t & 1) {
                ans ^= t;
            } else {
                ma |= 1LL << t;
            }
        }
        return ans;
    }
};
