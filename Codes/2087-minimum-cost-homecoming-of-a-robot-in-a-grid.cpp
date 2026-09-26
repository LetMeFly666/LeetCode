/*
 * @Author: LetMeFly
 * @Date: 2026-04-04 13:57:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-04-04 14:05:23
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int ans = 0;
        for (int from = startPos[0], to = homePos[0], direction = to > from ? 1 : -1; from != to; from += direction) {
            ans += rowCosts[from + direction];
        }
        for (int from = startPos[1], to = homePos[1], direction = to > from ? 1 : -1; from != to; from += direction) {
            ans += colCosts[from + direction];
        }
        return ans;
    }
};