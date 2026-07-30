/*
 * @Author: LetMeFly
 * @Date: 2026-07-30 18:53:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-30 18:59:13
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumPushes(string& word) {
        // 1-8: n
        // 9-16: 2n
        // 17-24: 3n
        // 25-26: 4n
        int n = word.size();
        int cnt = 0;
        if (n <= 8) {
            return n;
        }
        cnt += 8;
        if (n <= 16) {
            return cnt + (n - 8) * 2;
        }
        cnt += 8 * 2;
        if (n <= 24) {
            return cnt + (n - 16) * 3;
        }
        cnt += 8 * 3;
        return cnt + (n - 24) * 4;
    }
};
