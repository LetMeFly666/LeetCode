/*
 * @Author: LetMeFly
 * @Date: 2024-01-20 23:18:28
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-01-20 23:22:03
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;
        for (string& word : words) {
            int last = -1;
            for (int i = 0; i <= word.size(); i++) {
                if (i == word.size() || word[i] == separator) {
                    if (i - last > 1) {
                        ans.push_back(word.substr(last + 1, i - last - 1));
                    }
                    last = i;
                }
            }
        }
        return ans;
    }
};