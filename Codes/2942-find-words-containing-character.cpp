/*
 * @Author: LetMeFly
 * @Date: 2025-05-24 21:30:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-24 21:34:02
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for (int i = 0; i < words.size(); i++) {
            if (words[i].find(x) != string::npos) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};