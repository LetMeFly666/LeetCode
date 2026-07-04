/*
 * @Author: LetMeFly
 * @Date: 2026-07-04 10:58:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-04 11:02:17
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int ans;
    vector<bool> visited;
    vector<vector<pair<int, int>>> graph;

    void dfs(int from) {
        visited[from] = true;
        for (auto [to, dis] : graph[from]) {
            ans = min(ans, dis);
            if (!visited[to]) {
                dfs(to);
            }
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        visited = vector<bool> (n + 1);
        graph = vector<vector<pair<int, int>>>(n + 1);
        for (vector<int>& road : roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }

        ans = 100000;
        dfs(1);
        return ans;
    }
};
