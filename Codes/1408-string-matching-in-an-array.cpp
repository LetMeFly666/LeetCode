/*
 * @Author: LetMeFly
 * @Date: 2022-08-06 08:49:18
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-06 08:50:23
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (words[j].find(words[i]) < words[j].size()) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};