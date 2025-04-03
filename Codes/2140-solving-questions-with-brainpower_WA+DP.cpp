/*
 * @Author: LetMeFly
 * @Date: 2025-04-03 22:29:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-03 23:01:43
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif


#ifdef FirstTry  // WA  // 不可：将当前经验值直接累加到后面
/*
 [[1,1],[2,2],[3,3],[4,4],[5,5]]
cnt 0    0      1      1    1+2
dp  1    2      4      5     8

real ans: 7
*/
typedef long long ll;

class Solution {
public:
    ll mostPoints(vector<vector<int>>& questions) {
        vector<ll> dp(questions.size());
        ll cnt = 0;
        for (int i = 0; i < questions.size(); i++) {
            cnt += dp[i];
            dp[i] = cnt + questions[i][0];
            if (i + questions[i][1] + 1 < questions.size()) {
                dp[i + questions[i][1] + 1] += questions[i][0];
            }
        }
        return dp.back();
    }
};
#else  // FirstTry
// SecondTry
typedef long long ll;

class Solution {
public:
    ll mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> dp(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            int j = min(i + questions[i][1] + 1, n);
            dp[i] = max(dp[i + 1], dp[j] + questions[i][0]);
        }
        return dp[0];
    }
};
#endif  // FirstTry