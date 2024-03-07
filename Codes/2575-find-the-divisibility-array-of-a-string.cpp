/*
 * @Author: LetMeFly
 * @Date: 2024-03-07 15:47:48
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-07 15:49:11
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans(word.size());
        long long val = 0;
        for (int i = 0; i < word.size(); i++) {
            val = val * 10 + (word[i] - '0');
            val %= m;
            ans[i] = val == 0;
        }
        return ans;
    }
};