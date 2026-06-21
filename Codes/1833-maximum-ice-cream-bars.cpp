/*
 * @Author: LetMeFly
 * @Date: 2026-06-21 09:24:40
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-21 09:26:59
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

#define MAX 100000
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int bin[MAX + 1];
        for (int t : costs) {
            bin[t]++;
        }

        int ans = 0;
        for (int i = 1; i <= MAX && coins >= i; i++) {
            int num = min(coins / i, bin[i]);
            ans += num;
            coins -= i * num;
        }
        return ans;
    }
};
