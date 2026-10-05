/*
 * @Author: LetMeFly
 * @Date: 2026-10-05 16:38:39
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-05 16:39:47
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int scoreOfParentheses(const string& s) {
        int ans = 0;
        for (int i = 0, n = s.size(), layer = 0; i < n; i++) {
            if (s[i] == '(') {
                layer++;
            } else {
                layer--;
                if (s[i - 1] == '(') {
                    ans += 1 << layer;
                }
            }
        }
        return ans;
    }
};
