/*
 * @Author: LetMeFly
 * @Date: 2026-10-09 08:25:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-09 08:28:21
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minInsertions(const string& s) {
        int diff = 0;
        int ans = 0;
        for (char c : s) {
            if (c == '(') {
                diff += 2;
            } else if (diff) {
                diff--;
            } else {
                diff++;
                ans++;
            }
        }
        return ans + diff;
    }
};
