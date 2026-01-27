/*
 * @Author: LetMeFly
 * @Date: 2026-01-27 23:03:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-27 23:38:15
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(n);  // graph[from]: [<to, cost>, ...]
        for (vector<int>& edge: edges) {
            int from = edge[0], to = edge[1], cost = edge[2];
            graph[from].push_back({to, cost});
            graph[to].push_back({from, 2 * cost});
        }
        vector<int> costs(n, INT_MAX);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0});
        costs[0] = 0;
        while (pq.size()) {
            auto [cost, to] = pq.top();
            pq.pop();
            if (cost > costs[to]) {
                continue;
            }
            if (to == n - 1) {
                return cost;
            }
            for (auto[nextTo, nextCost] : graph[to]) {
                nextCost += cost;
                if (nextCost >= costs[nextTo]) {
                    continue;
                }
                costs[nextTo] = nextCost;
                pq.push({nextCost, nextTo});
            }
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