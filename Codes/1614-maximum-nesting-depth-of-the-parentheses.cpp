/*
 * @Author: LetMeFly
 * @Date: 2022-01-07 11:10:16
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-01-07 11:12:34
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int depth = 0;
        for (char& c : s) {
            if (c == '(') {
                depth++;
                ans = max(ans, depth);
            }
            else if (c == ')') {
                depth--;
            }
        }
        return ans;
    }
};
