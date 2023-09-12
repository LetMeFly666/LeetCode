/*
 * @Author: LetMeFly
 * @Date: 2023-09-12 09:35:38
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-09-12 10:01:01
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // 建图
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
        for (vector<int>& ab : prerequisites) {
            graph[ab[0]].push_back(ab[1]);
            indegree[ab[1]]++;
        }

        // 初始化队列
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (!indegree[i]) {
                q.push(i);
            }
        }

        // 预处理（拓扑排序）
        vector<vector<bool>> isPre(numCourses, vector<bool>(numCourses, false));
        while (q.size()) {
            int thisCourse = q.front();
            q.pop();
            for (int nextCourse : graph[thisCourse]) {
                indegree[nextCourse]--;
                if (!indegree[nextCourse]) {
                    q.push(nextCourse);
                }
                isPre[thisCourse][nextCourse] = true;
                for (int i = 0; i < numCourses; i++) {
                    isPre[i][nextCourse] = isPre[i][nextCourse] | isPre[i][thisCourse];  // vector不支持|=
                }
            }
        }

        // 查询
        vector<bool> ans;
        for (vector<int>& q : queries) {
            ans.push_back(isPre[q[0]][q[1]]);
        }
        return ans;
    }
};

#ifdef _WIN32
// vector没有|=、+=
int main() {
    bool t = true, f = false;
    cout << (t | f) << endl;
    t |= f;
    cout << t << endl;

    cout << "************" << endl;
    vector<bool> v(2);
    v[0] = false, v[1] = true;
    cout << (v[0] | v[1]) << endl;
    // v[0] |= v[1];  // 报错！！

    cout << "************" << endl;
    vector<int> v2(2);
    v2[0] = 2, v2[1] = 3;
    cout << (v2[0] | v2[1]) << endl;
    // v2[0] |= v2[1];  // 报错！！

    cout << "************" << endl;
    vector<int> v3(2);
    v3[0] = 2, v3[1] = 3;
    cout << (v3[0] + v3[1]) << endl;
    // v3[0] += v3[1];  // 报错！！

    cout << "************" << endl;
    vector<int> v4(2);
    v4[0] = 2, v4[1] = 3;
    cout << (v4[0] + v4[1]) << endl;
    // (v4.begin()) += (v4.begin() + 1);  // 报错！！
    
    return 0;
}
#endif