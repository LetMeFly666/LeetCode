/*
 * @Author: LetMeFly
 * @Date: 2024-11-02 17:28:26
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-02 17:50:47
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> degree(edges.size() + 1);
        vector<vector<int>> graph(edges.size() + 1);
        for (vector<int>& edge : edges) {
            degree[edge[0]]++;
            degree[edge[1]]++;
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        for (int i = 1; i <= edges.size(); i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        while (q.size()) {
            int thisNode = q.front();
            q.pop();
            for (int nextNode : graph[thisNode]) {
                degree[nextNode]--;
                if (degree[nextNode] == 1) {
                    q.push(nextNode);
                }
            }
        }
        unordered_set<int> reservedNodes;
        for (int i = 1; i <= edges.size(); i++) {
            if (degree[i] > 1) {
                reservedNodes.insert(i);
            }
        }
        // for (vector<vector<int>>::iterator it = edges.rbegin(); it != edges.rend(); it++)
        for (int i = edges.size() - 1; i >= 0; i--) {
            if (reservedNodes.count(edges[i][0]) && reservedNodes.count(edges[i][1])) {
                return edges[i];
            }
        }
        return {};  // FAKE RETURN
    }
};