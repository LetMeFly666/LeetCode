/*
 * @Author: LetMeFly
 * @Date: 2026-01-27 23:03:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-27 23:15:35
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline void go(int to, vector<bool>& visited, unordered_map<int, vector<pair<int, int>>> graph, priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>>& pq) {
        visited[to] = true;
        for (pair<int, int>& toInfo : graph[to]) {
            int nextTo = toInfo.first, w = toInfo.second;
            if (visited[nextTo]) {
                continue;
            }
            pq.push({w, to, nextTo});
        }
    }
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (vector<int>& edge : edges) {
            int from = edge[0], to = edge[1], w = edge[2];
            graph[from].push_back({to, w});
            graph[to].push_back({from, w});
        }
        vector<bool> visited(n);
        vector<int> costs(n);

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;  // <cost, from, to>
        go(0, visited, graph, pq);
        while (pq.size()) {
            auto[cost, from, to] = pq.top();
            pq.pop();
            if (visited[to]) {
                continue;
            }
            costs[to] = min(costs[to], costs[from] + cost);
            go(to, visited, graph, pq);
        }
        return costs[n - 1];
    }
};