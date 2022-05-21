/*
 * @Author: LetMeFly
 * @Date: 2022-04-20 15:13:05
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-20 15:17:20
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string freqAlphabets(string s) {
        string ans;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '#') {
                ans = (char)((s[i - 2] - '0') * 10 + (s[i - 1] - '1') + 'a') + ans;
                i -= 2;
            }
            else {
                ans = (char)(s[i] - '1' + 'a') + ans;
            }
        }
        return ans;
    }
};