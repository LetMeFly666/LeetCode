/*
 * @Author: LetMeFly
 * @Date: 2024-07-19 16:04:29
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-19 16:07:48
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumLevels(vector<int>& possible) {  // 0减分1加分
        int cnt = 0;
        for (int t : possible) {
            cnt += t == 0 ? -1 : 1;
        }
        int now = 0;
        for (int i = 0; i < possible.size() - 1; i++) {
            now += possible[i] == 0 ? -1 : 1;
            if (now > cnt - now) {
                return i + 1;
            }
        }
        return -1;
    }
};