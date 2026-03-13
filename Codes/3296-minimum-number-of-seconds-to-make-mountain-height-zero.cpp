/*
 * @Author: LetMeFly
 * @Date: 2026-03-13 22:49:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-13 22:57:56
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> pq;
        for (int t : workerTimes) {
            pq.push({t, 1, t});
        }
        ll ans = 0;
        while (mountainHeight--) {
            auto[now, times, once] = pq.top();
            pq.pop();
            ans = now;
            pq.push({now + ++times * once, times, once});
        }
        return ans;
    }
};