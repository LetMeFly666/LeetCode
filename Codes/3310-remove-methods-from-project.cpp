/*
 * @Author: LetMeFly
 * @Date: 2026-08-05 21:36:13
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-05 21:57:08
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    vector<bool> visited;
    vector<vector<int>> graph;

    void dfs(int from) {
        visited[from] = true;
        for (int to : graph[from]) {
            if (!visited[to]) {
                dfs(to);
            }
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        graph.resize(n);
        for (vector<int>& i : invocations) {
            graph[i[0]].push_back(i[1]);
        }

        visited.resize(n);
        dfs(k);

        for (vector<int>& i : invocations) {
            if (!visited[i[0]] && visited[i[1]]) {
                vector<int> ans(n);
                iota(ans.begin(), ans.end(), 0);
                return ans;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
