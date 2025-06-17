/*
 * @Author: LetMeFly
 * @Date: 2025-06-15 22:35:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-17 10:44:08
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline bool isIn(char c, string s) {
        for (char t : s) {
            if (t == c) {
                return true;
            }
        }
        return false;
    }
public:
    int maxDiff(int num) {
        int ans = 0;
        string s = to_string(num);
        for (int i = 0; i < 10; i++) {
            if (!isIn('a' + i, s)) {
                continue;
            }
            for (int x = 0; x < 10; x++) {
                string a;
                for (char c : s) {
                    if (c == 'a' + i) {
                        a += 'x' + i;
                    } else {
                        a += c;
                    }
                }
                for (int y = 0; y < 10; y++) {
                    if (!isIn('a' + y, s)) {
                        
                    }
                }
            }
        }
        return ans;
    }
};