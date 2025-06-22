/*
 * @Author: LetMeFly
 * @Date: 2025-06-22 12:43:34
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-22 20:42:15
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        for (int i = 0; i < s.size(); i += k) {
            if (s.size() - i < k) {
                ans.push_back(s.substr(i, s.size() - i) + string(k - (s.size() - i), fill));
            } else {
                ans.push_back(s.substr(i, k));
            }
        }
        return ans;
    }
};