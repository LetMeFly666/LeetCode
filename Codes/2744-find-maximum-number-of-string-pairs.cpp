/*
 * @Author: LetMeFly
 * @Date: 2024-01-17 22:37:26
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-01-17 22:47:56
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string, int> ma;
        int ans = 0;
        for (string& word : words) {
            ans += ma[string(1, word[1]) + word[0]];
            ma[word]++;
        }
        return ans;
    }
};