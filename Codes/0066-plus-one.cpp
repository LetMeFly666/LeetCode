/*
 * @Author: LetMeFly
 * @Date: 2026-01-01 15:40:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-01 15:44:13
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int cnt = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i] += cnt;
            cnt = digits[i] / 10;
            digits[i] %= 10;
        }
        if (cnt) {
            digits.insert(digits.begin(), cnt);
        }
        return digits;
    }
};