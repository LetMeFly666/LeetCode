/*
 * @Author: LetMeFly
 * @Date: 2023-04-01 09:32:32
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-04-01 09:40:57
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string maskPII(string s) {
        bool isemail = false;
        for (char c : s) {
            if (c == '@' || c == '.') {
                isemail = true;
                break;
            }
        }
        string ans;
        if (isemail) {
            ans += tolower(s[0]);
            ans += "*****";
            int locAt = 0;
            while (s[locAt] != '@') {
                locAt++;
            }
            ans += tolower(s[locAt - 1]);
            while (locAt < s.size()) {
                if (isupper(s[locAt])) {
                    ans += tolower(s[locAt]);
                }
                else {
                    ans += s[locAt];
                }
                locAt++;
            }
        }
        else {
            int cntNum = 0;
            for (char c : s) {
                cntNum += isdigit(c);
            }
            if (cntNum == 10) {
                ans = "***-***-";
            }
            else if (cntNum == 11) {
                ans = "+*-***-***-";
            }
            else if (cntNum == 12) {
                ans = "+**-***-***-";
            }
            else {
                ans = "+***-***-***-";
            }
            int cntTail = 0;
            char tail[4];
            for (int i = s.size() - 1; cntTail < 4; i--) {
                if (isdigit(s[i])) {
                    tail[cntTail++] = s[i];
                }
            }
            for (int i = 3; i >= 0; i--) {
                ans += tail[i];
            }
        }
        return ans;
    }
};