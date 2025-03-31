/*
 * @Author: LetMeFly
 * @Date: 2025-03-31 14:21:40
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-31 14:24:26
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline bool isSpace(vector<int>& spaces, int i, int j) {
        if (j == spaces.size()) {
            return false;
        }
        return i == spaces[j];
    }
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        for (int i = 0, j = 0; i < s.size(); i++) {
            if (isSpace(spaces, i, j)) {
                ans += ' ';
                j++;
            }
            ans += s[i];
        }
        return ans;
    }
};