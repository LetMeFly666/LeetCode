/*
 * @Author: LetMeFly
 * @Date: 2026-10-08 08:52:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-08 08:58:16
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

#define IFSKIP if (!layer) skip = true

class Solution {
public:
    string removeOuterParentheses(const string& s) {
        string ans;
        for (int i = 0, n = s.size(), layer = 0; i < n; i++) {
            bool skip = false;
            if (s[i] == '(') {
                IFSKIP;
                layer++;
            } else {
                layer--;
                IFSKIP;
            }

            if (!skip) {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
