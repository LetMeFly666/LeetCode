/*
 * @Author: LetMeFly
 * @Date: 2024-09-19 17:50:26
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-19 17:50:45
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 1, nowCnt = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1] + 1) {
                nowCnt++;
                ans = max(ans, nowCnt);
            }
            else {
                nowCnt = 1;
            }
        }
        return ans;
    }
};