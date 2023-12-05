/*
 * @Author: LetMeFly
 * @Date: 2023-12-05 19:45:03
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-05 19:51:42
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    long long ans;
    vector<vector<int>> graph;
    vector<bool> visited;

    long long dfs(int node, int seats){
        visited[node] = true;
        int cnt = 1;
        for (int toNode  : graph[node]) {
            if (!visited[toNode]) {
                long long peopleFromThatNode = dfs(toNode, seats);
                cnt += peopleFromThatNode;
                ans += (peopleFromThatNode + seats - 1) / seats;
            }
        }
        return cnt;
    }

public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        ans = 0;
        graph = vector<vector<int>>(roads.size() + 1);
        visited = vector<bool>(roads.size() + 1);
        for (auto& road : roads) {
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }
        dfs(0, seats);
        return ans;
    }
};