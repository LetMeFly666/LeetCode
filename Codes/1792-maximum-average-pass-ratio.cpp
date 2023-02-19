/*
 * @Author: LetMeFly
 * @Date: 2023-02-19 20:40:21
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-02-19 21:17:02
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif


/*  // 不用这么计算也可
a+1      a       b-a
---  -  ---  =  ------
b+1      b      b(b+1)

*/
typedef pair<double, double> pii;

inline double getScore(pii& a) {
    return (a.first + 1) / (a.second + 1) - a.first / a.second;
}

struct cmp {
    bool operator() (pii& a, pii& b) {
        return getScore(a) < getScore(b);
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pii, vector<pii>, cmp> pq;
        for (auto& c : classes) {
            pq.emplace(c[0], c[1]);
        }
        while (extraStudents--) {
            auto [a, b] = pq.top();
            // cout << "a = " << a << ", b = " << b << endl;  //**********
            pq.pop();
            pq.emplace(a + 1, b + 1);
        }
        double total = 0;
        while (pq.size()) {
            total += pq.top().first / pq.top().second;
            pq.pop();
        }
        return total / classes.size();
    }
};