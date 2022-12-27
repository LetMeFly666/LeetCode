/*
 * @Author: LetMeFly
 * @Date: 2022-12-27 11:06:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-27 11:06:33
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumMoves(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'X') {
                ans++;
                i += 2;
            }
        }
        return ans;
    }
};