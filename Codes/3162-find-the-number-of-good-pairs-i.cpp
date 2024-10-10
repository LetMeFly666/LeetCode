/*
 * @Author: LetMeFly
 * @Date: 2024-10-10 12:18:19
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-10 12:18:25
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int ans = 0;
        for (int n1 : nums1) {
            for (int n2 : nums2) {
                ans += n1 % (n2 * k) == 0;
            }
        }
        return ans;
    }
};