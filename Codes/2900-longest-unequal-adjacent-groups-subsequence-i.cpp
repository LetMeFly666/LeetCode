/*
 * @Author: LetMeFly
 * @Date: 2025-05-15 10:32:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-15 10:36:32
 * @Description: AC,100.00%,97.33%
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        for (int i = 0; i < groups.size(); i++) {
            if (!i || groups[i] != groups[i - 1]) {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};