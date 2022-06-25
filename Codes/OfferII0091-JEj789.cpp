/*
 * @Author: LetMeFly
 * @Date: 2022-06-25 10:46:43
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-25 10:49:00
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        for (int i = 1; i < costs.size(); i++) {
            costs[i][0] += min(costs[i - 1][1], costs[i - 1][2]);
            costs[i][1] += min(costs[i - 1][0], costs[i - 1][2]);
            costs[i][2] += min(costs[i - 1][0], costs[i - 1][1]);
        }
        return min(costs[costs.size() - 1][0], min(costs[costs.size() - 1][1], costs[costs.size() - 1][2]));
    }
};