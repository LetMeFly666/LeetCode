/*
 * @Author: LetMeFly
 * @Date: 2025-09-01 21:38:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-01 21:47:04
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto comp = [&classes](int i, int j) { return classes[i][0] * classes[j][1] > classes[j][0] * classes[i][1]; };
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
        int i = pq.top();
        return 1. * classes[i][0] / classes[i][1];
    }
};