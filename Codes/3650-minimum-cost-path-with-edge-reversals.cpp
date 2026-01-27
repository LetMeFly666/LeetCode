/*
 * @Author: LetMeFly
 * @Date: 2026-01-27 23:03:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-27 23:24:36
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline void go(int to, int nowCost, vector<bool>& visited, unordered_map<int, vector<pair<int, int>>> graph, priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>>& pq) {
        for (pair<int, int>& toInfo : graph[to]) {
            int nextTo = toInfo.first, w = toInfo.second;
            if (visited[nextTo]) {
                continue;
            }
            visited[nextTo] = true;
            pq.push({nowCost + w, to, nextTo});
        }
    }
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (vector<int>& edge : edges) {
            int from = edge[0], to = edge[1], w = edge[2];
            graph[from].push_back({to, w});
            graph[to].push_back({from, 2 * w});
        }
        vector<bool> visited(n);
        visited[0] = true;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;  // <cost, from, to>
        go(0, 0,  visited, graph, pq);
        while (pq.size()) {
            auto[cost, from, to] = pq.top();
            pq.pop();
            if (to == n - 1) {
                return cost;
            }
            go(to, cost, visited, graph, pq);
        }
        return -1;  // FAKE RETURN
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
4
[[0,1,3],[3,1,1],[2,3,4],[0,2,2]]

*/
int main() {
    int n;
    string s;
    while (cin >> n >> s) {
        Solution sol;
        vector<vector<int>> v = stringToVectorVector(s);
        cout << sol.minCost(n, v) << endl;
    }
    return 0;
}
#endif