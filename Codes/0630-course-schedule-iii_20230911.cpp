/*
 * @Author: LetMeFly
 * @Date: 2023-09-11 14:11:14
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-09-11 14:16:11
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        priority_queue<int> pq;
        int totalTime = 0;
        for (vector<int>& c : courses) {
            if (c[1] - c[0] >= totalTime) {
                totalTime += c[0];
                pq.push(c[0]);
            }
            else if (pq.size() && pq.top() > c[0]) {
                totalTime = totalTime + c[0] - pq.top();
                pq.pop();
                pq.push(c[0]);
            }
        }
        return pq.size();
    }
};