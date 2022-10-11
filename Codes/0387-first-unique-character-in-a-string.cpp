/*
 * @Author: LetMeFly
 * @Date: 2022-10-11 13:54:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-11 13:55:24
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int firstUniqChar(string& s) {
        int cnt[26] = {0};
        for (char& c : s)
            cnt[c - 'a']++;
        for (int i = 0; i < s.size(); i++) {
            if (cnt[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};