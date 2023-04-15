/*
 * @Author: LetMeFly
 * @Date: 2023-04-15 12:09:12
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-04-15 12:18:36
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
        for (int i = 0; i < n; i++) {
            bool already[5] = {false, false, false, false, false};
            for (int toPoint : graph[i]) {
                already[ans[toPoint]] = true;
            }
            for (int j = 1; j < 5; j++) {
                if (!already[j]) {
                    ans[i] = j;
                    break;
                }
            }
        }
        return ans;
    }
};