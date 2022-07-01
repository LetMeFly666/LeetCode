/*
 * @Author: LetMeFly
 * @Date: 2022-07-01 16:32:34
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-01 16:43:33
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isInterleave(string& s1, string& s2, string& s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;
        // bool dp[s3.size() + 1] = {false};
        vector<int> dp(s2.size() + 1, false);  // vector<bool> 没有&=操作
        dp[0] = true;
        for (int i = 0; i <= s1.size(); i++)
            for (int j = 0; j <= s2.size(); j++) {
                if (i > 0)
                    dp[j] &= (s1[i - 1] == s3[i - 1 + j]);
                if (j > 0)
                    dp[j] |= (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        return dp[s2.size()];
    }
};