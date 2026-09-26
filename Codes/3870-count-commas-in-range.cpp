/*
 * @Author: LetMeFly
 * @Date: 2026-09-08 12:33:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-08 12:36:37
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int cal(int n) {
        int len = 0;
        while (n) {
            len++;
            n /= 10;
        }
        return (len - 1) / 3;
    }
public:
    int countCommas(int n) {
        int ans = 0;
        for (int i = 1000; i <= n; i++) {
            ans += cal(i);
        }
        return ans;
    }
};
