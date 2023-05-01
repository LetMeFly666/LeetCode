/*
 * @Author: LetMeFly
 * @Date: 2023-05-01 21:00:21
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-05-01 21:03:38
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    unordered_map<int, int> ma;

    int getTime(int node, vector<int>& manager, vector<int>& informTime) {
        if (ma.count(node)) {
            return ma[node];
        }
        return ma[node] = getTime(manager[node], manager, informTime) + informTime[manager[node]];
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans = 0;
        ma[headID] = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, getTime(i, manager, informTime));
        }
        return ans;
    }
};