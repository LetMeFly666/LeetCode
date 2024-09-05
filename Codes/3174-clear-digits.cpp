/*
 * @Author: LetMeFly
 * @Date: 2024-09-05 09:30:39
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-05 09:32:25
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string clearDigits(string s) {
        string ans;
        int cntDigit = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (isdigit(s[i])) {
                cntDigit++;
            }
            else if (cntDigit) {
                cntDigit--;
            }
            else {
                ans += s[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};