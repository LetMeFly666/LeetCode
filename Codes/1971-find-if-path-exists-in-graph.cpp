/*
 * @Author: LetMeFly
 * @Date: 2022-12-19 20:05:39
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-19 20:10:31
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n);
        visited[source] = true;
        queue<int> q;
        q.push(source);
        while (q.size()) {
            int thisNode = q.front();
            q.pop();
            for (int toNode : graph[thisNode]) {
                if (!visited[toNode]) {
                    visited[toNode] = true;
                    q.push(toNode);
                }
            }
        }
        return visited[destination];
    }
};