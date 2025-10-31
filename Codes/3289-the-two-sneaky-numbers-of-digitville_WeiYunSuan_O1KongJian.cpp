/*
 * @Author: LetMeFly
 * @Date: 2025-10-31 22:40:51
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-31 22:49:15
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int xored = 0;
        for (int t : nums) {
            xored ^= t;
        }
        for (int i = 0; i < nums.size() - 2; i++) {
            xored ^= i;
        }
        // now xored is x^y

        int lowbit = xored & -xored;
        int ans1 = 0, ans2 = 0;

        for (int t : nums) {
            if (t & lowbit) {
                ans1 ^= t;
            } else {
                ans2 ^= t;
            }
        }
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i & lowbit) {
                ans1 ^= i;
            } else {
                ans2 ^= i;
            }
        }
        return {ans1, ans2};
    }
};