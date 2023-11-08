/*
 * @Author: LetMeFly
 * @Date: 2023-11-08 18:55:09
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-08 18:57:52
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int cnt[2] = {0, 0};
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i] - '0']++;
            if (i && s[i] < s[i - 1]) {
                return 0;
            }
        }
        return cnt[0] == cnt[1];
    }
};