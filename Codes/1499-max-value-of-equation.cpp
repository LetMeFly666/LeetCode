/*
 * @Author: LetMeFly
 * @Date: 2023-07-21 08:04:03
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-07-21 08:16:42
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif


/*
yi + yj + |xi - xj| = (yi - xi) + (xj + yj)
队列中放从大到小的(yi - xi)
*/
typedef pair<int, int> pii;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans = INT_MIN;
        deque<pii> q;
        for (vector<int>& point : points) {
            int x = point[0], y = point[1];
            while (q.size() && x - q.front().second > k) {
                q.pop_front();
            }
            if (q.size()) {
                ans = max(ans, x + y + q.front().first);
            }
            while (q.size() && y - x >= q.back().first) {
                q.pop_back();
            }
            q.push_back({y - x, x});
        }
        return ans;
    }
};