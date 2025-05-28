/*
 * @Author: LetMeFly
 * @Date: 2025-05-28 21:43:27
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-28 22:51:21
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    vector<vector<int>> buildTree(vector<vector<int>>& edges) {
        vector<vector<int>> graph(edges.size() + 1);
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return graph;
    }

    int dfs(vector<vector<int>>& graph, int lastNode, int thisNode, int k) {
        if (k == 0) {
            return 0;
        }
        int ans = 1;
        for (int nextNode : graph[thisNode]) {
            if (nextNode == lastNode) {
                continue;
            }
            ans += dfs(graph, thisNode, nextNode, k);
        }
        return ans;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<vector<int>> graph2 = buildTree(edges2);
        int add = 0;
        for (int i = 0; i <= edges2.size(); i++) {
            add = max(add, dfs(graph2, -1, i, k));
        }
        vector<vector<int>> graph1 = buildTree(edges1);
        vector<int> ans(graph1.size());
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = dfs(graph1, -1, i, k) + add;
        }
        return ans;
    }
};