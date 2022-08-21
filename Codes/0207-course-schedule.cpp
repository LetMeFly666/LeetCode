/*
 * @Author: LetMeFly
 * @Date: 2022-08-21 10:41:54
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-21 10:47:42
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
        // 建图
        for (int i = prerequisites.size() - 1; i >= 0; i--) {
            // v[1] -> v[0]
            indegree[prerequisites[i][0]]++;
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        // 拓扑排序
        int remainNode = numCourses;
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (!indegree[i]) {
                remainNode--;
                q.push(i);
            }
        }
        while (q.size()) {
            int thisNode = q.front();
            q.pop();
            for (int& toNode : graph[thisNode]) {
                indegree[toNode]--;
                if (!indegree[toNode]) {
                    remainNode--;
                    q.push(toNode);
                }
            }
        }

        return !remainNode;
    }
};