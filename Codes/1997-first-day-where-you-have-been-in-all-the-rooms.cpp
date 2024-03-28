/*
 * @Author: LetMeFly
 * @Date: 2024-03-28 11:49:40
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-28 12:08:39
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
const ll MOD = 1e9 + 7;
class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        vector<ll> firstVisit(nextVisit.size());
        for (int i = 1; i < nextVisit.size(); i++) {
            firstVisit[i] = (firstVisit[i - 1] * 2 - firstVisit[nextVisit[i - 1]] + 2 + MOD) % MOD;  // 记得先加个MOD再对MOD取模，否则可能是负结果。
        }
        return firstVisit.back();
    }
};