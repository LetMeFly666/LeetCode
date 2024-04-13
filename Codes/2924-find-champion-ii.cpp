/*
 * @Author: LetMeFly
 * @Date: 2024-04-13 09:29:05
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-13 09:30:45
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n);
        for (vector<int>& edge : edges)  {
            indegree[edge[1]]++;
        }
        int cntWinner = 0, winner;
        for (int i = 0; i < n; i++) {
            if (!indegree[i]) {
                cntWinner++;
                winner = i;
            }
        }
        return cntWinner == 1 ? winner : -1;
    }
};