/*
 * @Author: LetMeFly
 * @Date: 2026-04-21 23:10:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-04-21 23:11:41
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline void put(int node, vector<int>& source, vector<int>& target, vector<bool>& visited, unordered_map<int, int>& diff, queue<int>& q) {
        q.push(node);
        visited[node] = true;
        diff[source[node]]++;
        diff[target[node]]--;
    }

    int trace(int from, vector<int>& source, vector<int>& target, vector<vector<int>>& graph, vector<bool>& visited) {
        int ans = 0;
        queue<int> q;
        unordered_map<int, int> diff;
        
        put(from, source, target, visited, diff, q);
        while (q.size()) {
            int from = q.front();
            q.pop();
            for (int to : graph[from]) {
                if (!visited[to]) {
                    put(to, source, target, visited, diff, q);
                }
            }
        }

        for (auto [_, d] : diff) {
            ans += abs(d);
        }
        return ans;
    }
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<vector<int>> graph(n);
        for (vector<int>& s : allowedSwaps) {
            graph[s[0]].push_back(s[1]);
            graph[s[1]].push_back(s[0]);
        }
        int ans = 0;
        vector<bool> visited(n);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans += trace(i, source, target, graph, visited);
            }
        }
        return ans;
    }
};
