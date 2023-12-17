/*
 * @Author: LetMeFly
 * @Date: 2023-12-17 16:55:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-17 16:56:29
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        for (int i = 2; i < cost.size(); i++) {
            cost[i] += min(cost[i - 1], cost[i - 2]);
        }
        return cost.back();
    }
};