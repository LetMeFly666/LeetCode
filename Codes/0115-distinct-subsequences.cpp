/*
 * @Author: LetMeFly
 * @Date: 2022-07-16 14:27:18
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-16 15:11:10
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#define FirstTry

#ifdef FirstTry
class Solution {
public:
    int numDistinct(string s, string t) {
        /* dp[i][j]：```s的前i个字符的子串```的子序列中，```t的前j个字符的子串```出现的次数 */
        vector<vector<unsigned int>> dp(s.size() + 1, vector<unsigned int>(t.size() + 1, 0));
        for (int i = 0; i < s.size() + 1; i++) {  // T为空的时候，方案数为1
            dp[i][0] = 1;
        }
        for (int i = 1; i < s.size() + 1; i++) {
            for (int j = 1; j < t.size() + 1; j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp.back().back();
    }
};
#else  // FirstTry
// SecondTry  // 原地滚动  // Error
class Solution {
public:
    int numDistinct(string s, string t) {
        /* dp[i][j]：```s的前i个字符的子串```的子序列中，```t的前j个字符的子串```出现的次数 */
        vector<unsigned int> dp(s.size() + 1, 1);
        for (int i = 1; i < s.size() + 1; i++) {
            for (int j = 1; j < t.size() + 1; j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i] += dp[i - 1];
            }
        }
        return dp.back();
    }
};
#endif  // FirstTry

#ifdef isJava
class Solution {
    public int numDistinct(String s, String t) {
        int[][] dp = new int[t.length() + 1][s.length() + 1];
        for (int j = 0; j < s.length() + 1; j++) dp[0][j] = 1;
        for (int i = 1; i < t.length() + 1; i++) {
            for (int j = 1; j < s.length() + 1; j++) {
                if (t.charAt(i - 1) == s.charAt(j - 1)) dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                else dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[t.length()][s.length()];
    }
}
#endif