/*
 * @Author: LetMeFly
 * @Date: 2024-11-14 12:49:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-14 12:55:36
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int ans;
    vector<vector<int>> graph;

    int dfs(int root, int parent=-1) {
        int cnt = 1;
        int oneChild = 0;
        bool thisNodeOk = true;
        for (int nextNode : graph[root]) {
            if (nextNode == parent) {
                continue;
            }
            int nextCnt = dfs(nextNode, root);
            cnt += nextCnt;
            if (oneChild && nextCnt != oneChild) {
                thisNodeOk = false;
            }
            oneChild = nextCnt;
        }
        if (thisNodeOk) {
            ans++;
        }
        return cnt;
    }
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        ans = 0;
        graph.resize(edges.size() + 1);
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        dfs(0);
        return ans;
    }
};