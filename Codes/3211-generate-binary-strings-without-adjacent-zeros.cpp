/*
 * @Author: LetMeFly
 * @Date: 2024-10-29 23:01:28
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-29 23:25:33
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // RE，不是求种类数
class Solution {
public:
    vector<string> validStrings(int n) {
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = dp[0][1] = 1;
        for (int i = 1; i < n; i++) {
            dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][0] = dp[i - 1][1];
        }
        return dp[n - 1][0] + dp[n - 1][1];
    }
};
#else  // FirstTry
// SecondTry
/*
(1 << n) - 1  ---  低n位全为1

*/
class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        int mask = (1 << n) - 1;
        for (int i = 0; i < (1 << n); i++) {
            int x = i ^ mask;  // 取反
            if (!(x & (x >> 1))) {
                ans.push_back(bitset<18>(i).to_string().substr(18 - n));
            }
        }
        return ans;
    }
};
#endif  // FirstTry