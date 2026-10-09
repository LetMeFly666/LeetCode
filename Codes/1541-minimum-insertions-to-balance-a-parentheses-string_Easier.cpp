/*
 * @Author: LetMeFly
 * @Date: 2026-10-09 10:51:40
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-09 10:56:49
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minInsertions(const string& s) {
        int ans = 0;
        int diff = 0;
        for (size_t i = 0, n = s.size(); i < n; i++) {
            if (s[i] == '(') {
                diff++;
            } else {
                if (diff) {
                    diff--;
                } else {
                    ans++;
                }
                if (i + 1 < n && s[i + 1] == ')') {
                    i++;
                } else {
                    ans++;
                }
            }
        }
        return ans;
    }
};
