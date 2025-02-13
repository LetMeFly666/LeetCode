/*
 * @Author: LetMeFly
 * @Date: 2025-02-13 13:37:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-13 13:42:15
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool check(vector<int>& v, int m, int n) {
        for (int t : v) {
            m -= (t - 1) / n;
        }
        return m >= 0;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int m = (l + r) >> 1;
            if (check(nums, maxOperations, m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return r;
    }
};