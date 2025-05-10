/*
 * @Author: LetMeFly
 * @Date: 2025-05-10 12:07:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-10 18:56:04
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll s1 = 0, s2 = 0;
        int c1 = 0, c2 = 0;
        for (int t : nums1) {
            s1 += t;
            c1 += t == 0;
        }
        for (int t : nums2) {
            s2 += t;
            c2 += t == 0;
        }
        if (s1 < s2 && c1 == 0 || s1 > s2 && c2 == 0) {
            return -1;
        }
        return min(s1 + c1, s2 + c2);
    }
};