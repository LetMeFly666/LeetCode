/*
 * @Author: LetMeFly
 * @Date: 2026-04-04 13:57:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-04-04 13:59:37
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int ans = 0;
        for (int from = min(startPos[0], homePos[0]), to = max(startPos[0], homePos[0]); from + 1 < to; from++) {
            ans += colCosts[from + 1];
        }
        for (int from = min(startPos[1], homePos[1]), to = max(startPos[1], homePos[1]); from + 1 < to; from++) {
            ans += rowCosts[from + 1];
        }
        return ans;
    }
};