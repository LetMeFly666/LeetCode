/*
 * @Author: LetMeFly
 * @Date: 2022-07-08 21:56:30
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-08 21:58:54
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int s = 0;
        for (int &t : position) {
            if (t % 2)
                s++;
        }
        return min(s, (int)position.size() - s);
    }
};