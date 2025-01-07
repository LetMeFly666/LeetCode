/*
 * @Author: LetMeFly
 * @Date: 2025-01-07 13:03:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-07 13:08:37
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countKeyChanges(string& s) {
        int ans = 0;
        for (int i = 1; i < s.size(); i++) {
            ans += tolower(s[i]) != tolower(s[i - 1]);
        }
        return ans;
    }
};