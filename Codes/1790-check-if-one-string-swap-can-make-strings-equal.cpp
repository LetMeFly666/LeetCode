/*
 * @Author: LetMeFly
 * @Date: 2022-04-11 09:13:54
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-11 09:16:37
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> diff;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                if (diff.size() == 2)
                    return false;
                diff.push_back(i);
            }
        }
        if (diff.size() == 1)
            return false;
        if (diff.size() == 0)
            return true;
        if (s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]]) {
            return true;
        }
        return false;
    }
};