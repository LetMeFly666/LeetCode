/*
 * @Author: LetMeFly
 * @Date: 2022-06-02 10:50:41
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-02 11:00:22
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.size() == t.size()) {
            int diffNum = 0;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] != t[i]) {
                    diffNum++;
                    if (diffNum > 1) {
                        return false;
                    }
                }
            }
            return diffNum == 1;
        }
        if (s.size() == t.size() + 1) {
            swap(s, t);
        }
        if (s.size() + 1 == t.size()) {
            int diffNum = 0;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] != t[i + diffNum]) {
                    diffNum++;
                    i--;
                    if (diffNum > 1) {
                        return false;
                    }
                }
            }
            return true;
        }
        return false;
    }
};