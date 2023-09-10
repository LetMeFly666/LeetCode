/*
 * @Author: LetMeFly
 * @Date: 2023-09-10 13:54:14
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-09-10 14:08:00
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        vector<int> ans;
        while (q.size()) {
            int thisCourse = q.front();
            q.pop();
            ans.push_back(thisCourse);
            for (int to : graph[thisCourse]) {
                indegree[to]--;
                if (!indegree[to]) {
                    q.push(to);
                }
            }
        }
        return ans.size() == numCourses ? ans : vector<int>();
    }
};

#ifdef _WIN32
int main() {
    Solution sol;
    vector<vector<int>> v = {{0, 1}};
    debug(sol.findOrder(2, v));
    return 0;
}
#endif