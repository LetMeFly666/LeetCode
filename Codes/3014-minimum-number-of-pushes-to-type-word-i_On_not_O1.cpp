/*
 * @Author: LetMeFly
 * @Date: 2026-07-30 18:53:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-30 19:00:50
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumPushes(string& word) {
        int ans = 0;
        for (int i = 0, n = word.size(); i < n; i++) {
            ans += i / 8 + 1;
        }
        return ans;
    }
};
