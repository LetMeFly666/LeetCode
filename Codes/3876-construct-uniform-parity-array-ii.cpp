/*
 * @Author: LetMeFly
 * @Date: 2026-09-03 13:14:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-03 13:20:25
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = -1, minEven = -1;
        for (int t : nums1) {
            if (t % 2) {
                minOdd = min(minOdd, t);
            } else {
                minEven = min(minEven, t);
            }
        }
        if (minOdd == -1 || minEven == -1) {
            return true;
        }
        return minOdd < minEven;
    }
};
