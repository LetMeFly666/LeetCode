/*
 * @Author: LetMeFly
 * @Date: 2026-06-13 23:16:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-13 23:18:21
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for (string& word : words) {
            int cnt = 0;
            for (char c : word) {
                cnt += weights[c - 'a'];
            }
            ans += 'a' + (25 - cnt % 26);
        }
        return ans;
    }
};
