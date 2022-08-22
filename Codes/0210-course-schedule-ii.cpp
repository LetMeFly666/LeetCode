/*
 * @Author: LetMeFly
 * @Date: 2022-08-22 10:52:05
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-22 10:53:14
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
        vector<int> ans;
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
                ans.push_back(i);
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
                    ans.push_back(toNode);
                }
            }
        }

        if (remainNode) {
            return {};
        }
        else {
            return ans;
        }
    }
};