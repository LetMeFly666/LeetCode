/*
 * @Author: LetMeFly
 * @Date: 2023-11-11 22:29:48
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-11 22:40:00
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int ans = 0;
        vector<vector<int>> graph(row.size() / 2);
        for (int i = 0; i < row.size(); i += 2) {
            graph[row[i] / 2].push_back(row[i + 1] / 2);
            graph[row[i + 1] / 2].push_back(row[i] / 2);
        }
        vector<bool> visited(row.size() / 2, false);
        queue<int> q;
        for (int i = 0; i < row.size() / 2; i++) {
            if (visited[i]) {
                continue;
            }
            q.push(i);
            visited[i] = true;
            int thisCnt = 0;
            while (q.size()) {
                thisCnt++;
                int thisPeople = q.front();
                q.pop();
                for (int nextPeople : graph[thisPeople]) {
                    if (!visited[nextPeople]) {
                        visited[nextPeople] = true;
                        q.push(nextPeople);
                    }
                }
            }
            ans += thisCnt - 1;
        }
        return ans;
    }
};