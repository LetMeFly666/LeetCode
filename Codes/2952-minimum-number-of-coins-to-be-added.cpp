/*
 * @Author: LetMeFly
 * @Date: 2024-03-30 22:26:11
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-30 22:29:11
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int ans = 0, to = 0, i = 0;
        while (to < target) {
            if (i < coins.size() && coins[i] <= to + 1) {
                to += coins[i];
                i++;
            }
            else {
                to += to + 1;
                ans++;
            }
        }
        return ans;
    }
};