/*
 * @Author: LetMeFly
 * @Date: 2025-03-15 10:26:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-15 10:27:59
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;
        for (int i = 1; i < s.size(); i++) {
            ans += abs(s[i] - s[i - 1]);
        }
        return ans;
    }
};