/*
 * @Author: LetMeFly
 * @Date: 2024-05-16 20:17:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-16 20:18:40
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;

class Solution {
public:
    ll numberOfWeeks(vector<int>& milestones) {
        ll cnt = 0, M = 0;
        for (int t : milestones) {
            cnt += t;
            M = max(M, (ll)t);
        }
        return M * 2 <= cnt ? cnt : (cnt - M) * 2 + 1;
    }
};