/*
 * @Author: LetMeFly
 * @Date: 2024-09-13 12:40:50
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-13 13:06:39
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, ll budget) {
        int ans = 0;
        ll sumCosts = 0;
        deque<int> q;
        for (int l = 0, r = 0; r < chargeTimes.size(); r++) {
            while (q.size() && chargeTimes[r] > chargeTimes[q.back()]) {
                q.pop_back();
            }
            q.push_back(r);
            sumCosts += runningCosts[r];

            while (q.size() && chargeTimes[q.front()] + (r - l + 1) * sumCosts > budget) {
                if (q.front() == l) {
                    q.pop_front();
                }
                sumCosts -= runningCosts[l++];
            }

            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};