/*
 * @Author: LetMeFly
 * @Date: 2025-06-15 22:35:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-17 23:42:32
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline bool isIn(string s, char c) {
        for (char t : s) {
            if (t == c) {
                return true;
            }
        }
        return false;
    }

    inline string replace(string s, char a, char b) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == a) {
                s[i] = b;
            }
        }
        return s;
    }
public:
    int maxDiff(int num) {
        int ans = 0;
        string s = to_string(num);
        for (int a = 0; a < 10; a++) {
            if (!isIn(s, '0' + a)) {
                continue;
            }
            for (int b = 0; b < 10; b++) {
                string x = replace(s, '0' + a, '0' + b);
                for (int c = 0; c < 10; c++) {
                    if (!isIn(x, '0' + c)) {
                        continue;
                    }
                    for (int d = 0; d < 10; d++) {
                        string y = replace(x, '0' + c, '0' + d);
                        ans = max(ans, abs(atoi(x.c_str()) - atoi(y.c_str())));
                    }
                }
            }
        }
        return ans;
    }
};