/*
 * @Author: LetMeFly
 * @Date: 2021-12-27 09:00:07
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-12-27 09:07:32
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

int a[121];
class Solution {
public:
    // age[y] * 2 <= age[x] + 14
    int numFriendRequests(vector<int>& ages) {
        for (int i = 0; i < 121; i++)
            a[i] = 0;
        for (int& t : ages)
            a[t]++;
        int ans = 0;
        for (int y = 1; y <= 120; y++) {
            for (int x = y; x <= 120; x++) {
                if (y * 2 <= x + 14 || (y > 100 && x < 100))
                    continue;
                ans += x == y ? a[x] * (a[x] - 1) : a[x] * a[y];
            }
        }
        return ans;
    }
};