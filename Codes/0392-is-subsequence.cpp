/*
 * @Author: LetMeFly
 * @Date: 2022-10-12 11:03:16
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-12 11:04:24
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isSubsequence(string& s, string& t) {
        int loct = 0;
        for (int locs = 0; locs < s.size(); locs++) {
            while (loct < t.size() && t[loct] != s[locs])
                loct++;
            if (loct == t.size())
                return false;
            loct++;
        }
        return true;
    }
};