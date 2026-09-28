/*
 * @Author: LetMeFly
 * @Date: 2026-09-28 08:10:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-28 08:11:07
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxDepth(const string& s) {
        int ans = 0;
        for (int i = 0, n = s.size(), layer = 0; i < n; i++) {
            if (s[i] == '(') {
                layer++;
                ans = max(ans, layer);
            } else if (s[i] == ')') {
                layer--;
            }
        }
        return ans;
    }
};
