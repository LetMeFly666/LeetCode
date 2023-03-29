/*
 * @Author: LetMeFly
 * @Date: 2023-03-29 10:23:51
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-29 11:03:51
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // dp: 小复杂的dp
class Solution {
public:
    int countVowelStrings(int n) {
        int dp[5] = {1, 1, 1, 1, 1};
        for (int i = 2; i <= n; i++) {
            int newDp[5] = {0, 0, 0, 0, 0};
            for (int j = 0; j < 5; j++) {
                for (int i = 0; i <= j; i++) {
                    newDp[j] += dp[i];
                }
            }
            swap(dp, newDp);
        }
        return dp[0] + dp[1] + dp[2] + dp[3] + dp[4];
    }
};
#else  // FirstTry
#ifdef SecondTry  // dp：小简化
class Solution {
public:
    int countVowelStrings(int n) {
        int dp[5] = {1, 1, 1, 1, 1};
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < 5; j++) {
                dp[j] += dp[j - 1];
            }
        }
        return accumulate(dp, dp + 5, 0);
    }
};
#else  // SecondTry
// ThirdTry  // 排列组合
// n小球放入5个盒子中，允许为空
// C_{n - 1}^{4}为n小球放入5盒子且不空的情况，C_{n + 4}^{4}为n + 5小球放入5盒子且不空的情况（n + 5个小球放入5个盒子且不空，相当于先将多出的5个虚拟小球放入盒子中，其余n个小球随便放，可空）
class Solution {
public:
    int countVowelStrings(int n) {
        return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
    }
};
#endif  // SecondTry
#endif  // FirstTry