/*
 * @Author: LetMeFly
 * @Date: 2023-11-26 18:24:18
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-26 18:26:48
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int uniqueLetterString(string s) {
        vector<int> pos[26];
        for (int i = 0; i < 26; i++) {
            pos[i].push_back(-1);
        }
        for (int i = 0; i < s.size(); i++) {
            pos[s[i] - 'A'].push_back(i);
        }
        for (int i = 0; i < 26; i++) {
            pos[i].push_back(s.size());
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j + 1 < pos[i].size(); j++) {
                ans += (pos[i][j] - pos[i][j - 1]) * (pos[i][j + 1] - pos[i][j]);
            }
        }
        return ans;
    }
};