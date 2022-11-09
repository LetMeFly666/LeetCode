/*
 * @Author: LetMeFly
 * @Date: 2022-07-26 11:45:03
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-26 11:47:33
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> se;
        for (string& s : wordDict) {
            se.insert(s);
        }
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && se.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};