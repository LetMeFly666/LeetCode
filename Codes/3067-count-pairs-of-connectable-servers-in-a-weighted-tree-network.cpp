/*
 * @Author: LetMeFly
 * @Date: 2024-06-04 21:34:22
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-04 21:44:11
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    vector<vector<pair<int, int>>> graph;
    int signalSpeed;

    int dfs(int from, int to, int cntDistance) {
        int ans = cntDistance % signalSpeed == 0;
        for (auto [nextNode, nextDistance] : graph[to]) {
            if (nextNode == from) {
                continue;
            }
            ans += dfs(to, nextNode, cntDistance + nextDistance);
        }
        return ans;
    }
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        // init
        graph.resize(edges.size() + 1);
        this->signalSpeed = signalSpeed;
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        // calculate
        vector<int> ans(edges.size() + 1);
        for (int c = 0; c < ans.size(); c++) {
            vector<int> ab;  // c为根的每个边上有多少ab节点
            for (auto [to, distance] : graph[c]) {
                ab.push_back(dfs(c, to, distance));
            }
            for (int i = 0; i < ab.size(); i++) {
                for (int j = i + 1; j < ab.size(); j++) {
                    ans[c] += ab[i] * ab[j];
                }
            }
        }
        return ans;
    }
};