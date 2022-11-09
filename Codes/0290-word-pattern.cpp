/*
 * @Author: LetMeFly
 * @Date: 2022-09-16 09:32:01
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-16 09:39:40
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool wordPattern(string& pattern, string& s) {
        unordered_map<char, string> c2s;
        unordered_map<string, char> s2c;
        int th = 0;
        int lastBegin = -1;
        s += ' ';
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                string thisWord = s.substr(lastBegin + 1, i - lastBegin - 1);
                lastBegin = i;
                if (c2s.count(pattern[th])) {
                    if (c2s[pattern[th]] != thisWord) {
                        return false;
                    }
                }
                else {
                    c2s[pattern[th]] = thisWord;
                }
                if (s2c.count(thisWord)) {
                    if (s2c[thisWord] != pattern[th]) {
                        return false;
                    }
                }
                else {
                    s2c[thisWord] = pattern[th];
                }
                th++;
            }
        }
        return th == pattern.size();
    }
};