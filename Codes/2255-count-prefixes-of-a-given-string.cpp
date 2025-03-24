/*
 * @Author: LetMeFly
 * @Date: 2025-03-24 17:41:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-24 17:51:42
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int ans = 0;
        for (string& word : words) {
            ans += s.find(word) == 0;
        }
        return ans;
    }
};