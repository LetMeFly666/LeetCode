/*
 * @Author: LetMeFly
 * @Date: 2023-09-09 10:03:58
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-09-09 10:13:42
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
        for (vector<int>& ab : prerequisites) {
            graph[ab[1]].push_back(ab[0]);
            indegree[ab[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (!indegree[i]) {
                q.push(i);
            }
        }
        int remain = numCourses;
        while (q.size()) {
            int thisCourse = q.front();
            q.pop();
            remain--;
            for (int to : graph[thisCourse]) {
                indegree[to]--;
                if (!indegree[to]) {
                    q.push(to);
                }
            }
        }
        return !remain;
    }
};