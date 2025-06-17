/*
 * @Author: LetMeFly
 * @Date: 2025-06-15 22:35:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-17 10:49:41
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
            
            for (int b = 0; b < 10; b++) {
                for (int c = 0; c < 10; c++) {
                    for (int d = 0; d < 10; d++) {
                        
                    }
                }
            }
        }
        return ans;
    }
};