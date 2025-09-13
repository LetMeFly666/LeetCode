/*
 * @Author: LetMeFly
 * @Date: 2025-09-13 16:07:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-13 16:10:22
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline bool isYuan(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    int maxFreqSum(string s) {
        int times[26] = {0};
        for (char c : s) {
            times[c - 'a']++;
        }
        int y = 0, f = 0;
        for (int i = 0; i < 26; i++) {
            if (isYuan('a' + i)) {
                y = max(y, times[i]);
            } else {
                f = max(f, times[i]);
            }
        }
        return y + f;
    }
};