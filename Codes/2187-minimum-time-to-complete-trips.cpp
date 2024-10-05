/*
 * @Author: LetMeFly
 * @Date: 2024-10-05 17:33:12
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-05 17:39:55
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
private:
    bool check(vector<int>& times, ll totalTrips, ll timeCnt) {
        for (int t : times) {
            totalTrips -= timeCnt / t;
        }
        return totalTrips <= 0;
    }
public:
    ll minimumTime(vector<int>& times, int totalTrips) {
        ll l = 1, r = 1e14 + 1;
        while (l < r) {
            ll mid = (l + r) >> 1;
            if (check(times, totalTrips, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};