/*
 * @Author: LetMeFly
 * @Date: 2022-04-21 10:48:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-21 10:56:23
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string toGoatLatin(string& s) {
        string ans;
        s += '.';
        int l = 0;
        int cnt = 0;
        for (int r = 0; r < s.size(); r++) {
            if (!(s[r] >= 'a' && s[r] <= 'z' || s[r] >= 'A' && s[r] <= 'Z')) {  // [l, r)
                if (cnt)
                    ans += ' ';
                bool yuan = false;
                if (s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u' || s[l] == 'A' || s[l] == 'E' || s[l] == 'I' || s[l] == 'O' || s[l] == 'U') {
                    yuan = true;
                }
                char first = s[l];
                if (yuan)
                    ans += s[l];
                for (l++; l < r; l++) {
                    ans += s[l];
                }
                if (!yuan) {
                    ans += first;
                }
                ans += "ma";
                for (int i = 0; i <= cnt; i++) {
                    ans += 'a';
                }
                cnt++;
                l = r + 1;
            }
        }
        return ans;
    }
};