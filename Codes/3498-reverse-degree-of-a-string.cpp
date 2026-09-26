/*
 * @Author: LetMeFly
 * @Date: 2026-09-20 10:25:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-20 10:27:58
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int reverseDegree(const string& s) {
        int ans = 0;
        for (int i = 0, n = s.size(); i < n; i++) {
            // cout << (27 - s[i] + 'a') << " * " << i + 1 << endl;
            ans += (i + 1) * (26 - s[i] + 'a');
        }
        return ans;
    }
};
