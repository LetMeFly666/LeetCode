/*
 * @Author: LetMeFly
 * @Date: 2022-06-12 09:05:46
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-12 09:10:54
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (string& word : words) {
            unordered_map<char, char> ma1, ma2;
            bool can = true;
            for (int i = 0; i < word.size(); i++) {
                if (ma1.count(pattern[i]) && word[i] != ma1[pattern[i]]) {
                    can = false;
                    break;
                }
                if (ma2.count(word[i]) && pattern[i] != ma2[word[i]]) {
                    can = false;
                    break;
                }
                ma1[pattern[i]] = word[i];
                ma2[word[i]] = pattern[i];
            }
            if (can)
                ans.push_back(word);
        }
        return ans;
    }
};