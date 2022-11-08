/*
 * @Author: LetMeFly
 * @Date: 2022-11-08 08:54:11
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-08 09:04:10
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countConsistentStrings(string& allowed, vector<string>& words) {
        bool bin[26] = {false};
        for (char& c : allowed)
            bin[c - 'a'] = true;
        int ans = 0;
        for (string& s : words) {
            bool ok = true;
            for (char& c : s) {
                if (!bin[c - 'a']) {
                    ok = false;
                    break;
                }
            }
            ans += ok;
        }
        return ans;
    }
};