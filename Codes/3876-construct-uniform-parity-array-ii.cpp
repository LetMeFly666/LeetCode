/*
 * @Author: LetMeFly
 * @Date: 2026-09-03 13:14:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-03 13:16:53
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int maxOdd = -1, maxEven = -1;
        for (int t : nums1) {
            if (t % 2) {
                maxOdd = max(maxOdd, t);
            } else {
                maxEven = max(maxEven, t);
            }
        }
        if (maxOdd == -1 || maxEven == -1) {
            return true;
        }
        return maxOdd > maxEven;
    }
};
