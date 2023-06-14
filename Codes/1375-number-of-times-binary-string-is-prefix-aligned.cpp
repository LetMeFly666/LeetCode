/*
 * @Author: LetMeFly
 * @Date: 2023-06-14 17:12:39
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-06-14 17:55:02
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int M = 0;
        int ans = 0;
        for (int i = 0; i < flips.size(); i++) {
            M = max(flips[i], M);
            ans += (M == i + 1);
        }
        return ans;
    }
};