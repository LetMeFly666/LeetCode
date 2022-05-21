/*
 * @Author: LetMeFly
 * @Date: 2022-05-09 10:22:32
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-09 10:24:52
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

// 这题很巧
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int to = 0;
        vector<int> ans(s.size() + 1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'I')
                ans[i] = to++;
        }
        ans[s.size()] = to;
        to = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'D')
                ans[i] = to--;
        }
        return ans;
    }
};