/*
 * @Author: LetMeFly
 * @Date: 2024-03-05 14:30:57
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-05 14:58:26
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
const ll MOD = 1e9 + 7;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n);
        for (vector<int>& road : roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }
        vector<ll> way(n);
        way[0] = 1;
        vector<ll> dis(n, 1e18);
        dis[0] = 0;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.push({0, 0});
        while (pq.size()) {
            auto [thisDistance, thisNode] = pq.top();
            pq.pop();
            if (thisDistance > dis[thisNode]) {  // 有更优解了
                continue;
            }
            for (auto [nextNode, nextDistance] : graph[thisNode]) {
                if (thisDistance + nextDistance < dis[nextNode]) {
                    dis[nextNode] = thisDistance + nextDistance;
                    way[nextNode] = way[thisNode];
                    pq.push({dis[nextNode], nextNode});
                }
                else if (thisDistance + nextDistance == dis[nextNode]) {
                    way[nextNode] = (way[nextNode] + way[thisNode]) % MOD;
                }
            }
        }
        return way.back();
    }
};