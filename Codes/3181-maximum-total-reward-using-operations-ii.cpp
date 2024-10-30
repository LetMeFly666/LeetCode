/*
 * @Author: LetMeFly
 * @Date: 2024-10-28 21:52:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-30 10:24:21
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        bitset<100000> dp = 1;  // 2 * (50000)
        for (int x : rewardValues) {
            // [0, x - 1]
            // dp |= dp << (100000 - x) >> (100000 - x) << x;
            dp |= dp << (100000 - x) >> (100000- 2 * x);
        }
        int ans = rewardValues.back() * 2 - 1;
        while (!dp.test(ans)) {
            ans--;
        }
        return ans;
    }
};