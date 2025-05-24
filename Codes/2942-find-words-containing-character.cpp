/*
 * @Author: LetMeFly
 * @Date: 2025-05-24 21:30:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-24 21:32:53
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for (string& word : words) {
            if (word.find(x) != string::npos) {
                
            }
        }
    }
};