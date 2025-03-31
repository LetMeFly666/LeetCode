/*
 * @Author: LetMeFly
 * @Date: 2025-03-31 14:31:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-31 14:32:48
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        for (int i = 0, j = 0; i < s.size(); i++) {
            if (j < spaces.size() && spaces[j] == i) {
                ans += ' ';
                j++;
            }
            ans += s[i];
        }
        return ans;
    }
};