/*
 * @Author: LetMeFly
 * @Date: 2024-07-01 14:19:06
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-01 14:32:31
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int ans, maxTime;
    vector<bool> visited;
    vector<int> values;
    vector<vector<pair<int, int>>> graph;  // graph[i]: [<neighbor, distance>, ...]

    void dfs(int root, int time, int value) {
        if (!root) {
            ans = max(ans, value);
        }
        for (auto [next, distance] : graph[root]) {
            if (time + distance > maxTime) {
                continue;
            }
            if (!visited[next]) {
                visited[next] = true;
                dfs(next, time + distance, value + values[next]);
                visited[next] = false;
            }
            else {
                dfs(next, time + distance, value);
            }
        }
    }
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        ans = 0;
        this->maxTime = maxTime;
        visited.resize(values.size(), false);
        this->values = values;
        graph.resize(values.size());
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        visited[0] = true;  // 别忘了
        dfs(0, 0, values[0]);
        return ans;
    }
};