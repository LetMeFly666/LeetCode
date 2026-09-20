/*
 * @Author: LetMeFly
 * @Date: 2026-09-20 10:25:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-20 10:26:17
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int reverseDegree(const string& s) {
        int ans = 0;
        for (int i = 0, n = s.size(); i < n; i++) {
            ans += (i + 1) * (27 - s[i] + 'a');
        }
        return ans;
    }
};
