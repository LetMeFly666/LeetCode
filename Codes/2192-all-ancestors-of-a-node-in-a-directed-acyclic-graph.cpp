/*
 * @Author: LetMeFly
 * @Date: 2024-04-04 15:11:23
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-04 15:21:44
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> father(n);
        vector<int> degree(n);
        vector<vector<int>> graph(n);
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            degree[edge[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!degree[i]) {
                q.push(i);
            }
        }
        while (q.size()) {
            int thisNode = q.front();
            q.pop();
            for (int nextNode : graph[thisNode]) {
                father[nextNode].insert(thisNode);
                for (int thisFather : father[thisNode]) {
                    father[nextNode].insert(thisFather);
                }
                degree[nextNode]--;
                if (!degree[nextNode]) {
                    q.push(nextNode);
                }
            }
        }
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++) {
            for (int t : father[i]) {
                ans[i].push_back(t);
            }
            sort(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};