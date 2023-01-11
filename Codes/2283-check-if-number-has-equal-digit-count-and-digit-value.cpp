/*
 * @Author: LetMeFly
 * @Date: 2023-01-11 22:54:51
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-01-11 22:56:40
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool digitCount(string& num) {
        int cnt[10] = {0};
        for (char c : num) {
            cnt[c - '0']++;
        }
        for (int i = 0; i < num.size(); i++) {
            if (cnt[i] != num[i] - '0')
                return false;
        }
        return true;
    }
};