/*
 * @Author: LetMeFly
 * @Date: 2026-09-03 13:14:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-03 13:21:50
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

const int INF = 1e9 + 1;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INF, minEven = INF;
        for (int t : nums1) {
            if (t % 2) {
                minOdd = min(minOdd, t);
            } else {
                minEven = min(minEven, t);
            }
        }
        if (minOdd == INF || minEven == INF) {
            return true;
        }
        return minOdd < minEven;
    }
};
