/*
 * @Author: LetMeFly
 * @Date: 2025-09-01 21:38:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-01 22:00:19
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

/*
(2, 3), (3, 5), (2, 2)
0.666     0.6     1
0.666>0.6但是(2,3)人少
*/
/*
通过率增量
(a + 1) / (b + 1) - a / b
*/

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto comp = [&classes](int i, int j) {
            return 1. * (classes[i][0] + 1) / (classes[i][1] + 1) - 1. * classes[i][0] / classes[i][1]
                 > 1. * (classes[j][0] + 1) / (classes[j][1] + 1) - 1. * classes[j][0] / classes[j][1];
        };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        for (int i = 0; i < classes.size(); i++) {
            pq.push(i);
        }
        while (extraStudents--) {
            int i = pq.top();
            pq.pop();
            classes[i][0]++;
            classes[i][1]++;
            pq.push(i);
        }
        double ans = 0;
        for (vector<int>& c : classes) {
            ans += 1. * c[0] / c[1];
        }
        return ans / classes.size();
    }
};