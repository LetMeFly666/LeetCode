/*
 * @Author: LetMeFly
 * @Date: 2024-12-26 15:37:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-26 15:39:20
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isSubstringPresent(string s) {
        bool visited[26][26] = {false};
        for (int i = 1; i < s.size(); i++) {
            visited[s[i - 1] - 'a'][s[i] - 'a'] = true;
            if (visited[s[i] - 'a'][s[i - 1] - 'a']) {
                return true;
            }
        }
        return false;
    }
};