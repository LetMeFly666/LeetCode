/*
 * @Author: LetMeFly
 * @Date: 2026-07-04 10:47:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-04 10:58:26
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<int>> graph(n + 1);
        vector<int> m(n + 1, 100000);

        for (vector<int>& road : roads) {
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
            m[road[0]] = min(m[road[0]], road[2]);
            m[road[1]] = min(m[road[1]], road[2]);
        }
        
        int ans = 100000;
        vector<bool> visited(n + 1);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        while (q.size()) {
            int a = q.front();
            q.pop();
            for (int b: graph[a]) {
                if (!visited[b]) {
                    visited[b] = true;
                    q.push(b);
                    ans = min(ans, m[b]);
                }
            }
        }
        return ans;
    }
};
