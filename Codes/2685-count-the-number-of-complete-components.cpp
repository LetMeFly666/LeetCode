/*
 * @Author: LetMeFly
 * @Date: 2026-07-11 08:34:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-11 08:40:46
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef pair<int, int> pii;
class Solution {
private:
    vector<bool> visited;
    vector<vector<int>> graph;

    pii dfs(int from) {
        visited[from] = true;
        int edge = 0, node = 1;
        for (int to : graph[from]) {
            edge++;
            if (!visited[to]) {
                auto [next_edge, next_node] = dfs(to);
                edge += next_edge;
                node += next_node;
            }
        }
        return {edge, node};
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        visited.resize(n);
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                auto [edge, node] = dfs(i);
                ans += edge == node * (node - 1);  // no need to /2
            }
        }
        return ans;
    }
};
