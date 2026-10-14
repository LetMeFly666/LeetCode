/*
 * @Author: LetMeFly
 * @Date: 2026-10-14 19:25:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-14 19:31:00
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (num * 9 < sum) {
            return "";
        }
        string ans;
        ans.reserve(num);
        for (int i = 0, to = sum / 9; i < to; i++) {
            ans.push_back('9');
        }
        if (sum != 9 * num) {
            ans.push_back('0' + sum % 9);
        }
        for (int i = sum / 9 + 1; i < num; i++) {
            ans.push_back('0');
        }
        return ans;
    }
};
