/*
 * @Author: LetMeFly
 * @Date: 2021-12-14 19:28:19
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-12-14 19:33:22
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        priority_queue<int> q;
        int total = 0;
        for (const vector<int>& course : courses) {
            if (total + course[0] <= course[1]) {
                total += course[0];
                q.push(course[0]);
            }
            else if (q.size() && q.top() > course[0]) {
                total -= q.top() - course[0];
                q.pop();
                q.push(course[0]);
            }
        }
        return q.size();
    }
};