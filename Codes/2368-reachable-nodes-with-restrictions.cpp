/*
 * @Author: LetMeFly
 * @Date: 2024-03-02 16:13:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-02 16:17:41
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int ans;
    unordered_set<int> unachieveable;
    vector<vector<int>> graph;

    void dfs(int n) {
        unachieveable.insert(n);
        ans++;
        for (int next : graph[n]) {
            if (!unachieveable.count(next)) {
                dfs(next);
            }
        }
    }
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        ans = 0;
        graph.resize(n);
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        for (int t : restricted) {
            unachieveable.insert(t);
        }
        dfs(0);
        return ans;
    }
};