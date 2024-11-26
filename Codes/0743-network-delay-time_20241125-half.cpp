/*
 * @Author: LetMeFly
 * @Date: 2024-11-25 18:33:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-25 18:39:53
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    void dfs(int root, vector<int>& when) {
        
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);  // graph[i]: [i->a, i->b, i->c]
        for (vector<int>& thisRoad : times) {
            graph[thisRoad[0]].push_back({thisRoad[1], thisRoad[2]});
        }
        vector<int> when(n + 1, 1e9);
        when[0] = when[k] = 0;
        dfs(k, when);
        return *max_element(when.begin(), when.end());
    }
};