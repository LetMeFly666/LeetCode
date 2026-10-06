/*
 * @Author: LetMeFly
 * @Date: 2026-10-06 11:26:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-06 11:26:54
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minAddToMakeValid(const string& s) {
        int ans = 0, diff = 0;
        for (int i = 0, n = s.size(); i < n; i++) {
            if (s[i] == '(') {
                diff++;
            } else {
                if (diff) {
                    diff--;
                } else {
                    ans++;
                }
            }
        }
        return ans + diff;
    }
};
