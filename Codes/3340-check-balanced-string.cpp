/*
 * @Author: LetMeFly
 * @Date: 2025-03-14 09:30:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-14 09:32:51
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isBalanced(string num) {
        int cnt = 0;
        for (int i = 0; i < num.size(); i++) {
            cnt += i % 2 ? (num[i] - '0') : -(num[i] - '0');
        }
        return cnt == 0;
    }
};