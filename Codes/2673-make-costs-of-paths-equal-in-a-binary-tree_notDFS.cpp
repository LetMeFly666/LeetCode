/*
 * @Author: LetMeFly
 * @Date: 2024-02-28 21:12:29
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-02-28 21:14:03
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
   0
 1   2
3 4 5 6
*/

class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        for (int i = n / 2 - 1; i >= 0; i--) {
            ans += abs(cost[i * 2 + 1] - cost[i * 2 + 2]);
            cost[i] += max(cost[i * 2 + 1], cost[i * 2 + 2]);
        }
        return ans;
    }
};