/*
 * @Author: LetMeFly
 * @Date: 2023-04-15 12:09:12
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-04-15 12:16:53
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> ans(n);
        vector<vector<int>> graph(n);
        for (vector<int>& path : paths) {
            graph[path[0] - 1].push_back(path[1] - 1);
            graph[path[1] - 1].push_back(path[0] - 1);
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!ans[i]) {
                ans[i] = 1;
                q.push(i);
                while (q.size()) {
                    int thisPoint = q.front();
                    q.pop();
                    for (int& toPoint : graph[thisPoint]) {
                        if (!ans[toPoint]) {
                            
                        }
                    }
                }
            }
        }
        return ans;
    }
};