/*
 * @Author: LetMeFly
 * @Date: 2024-08-24 12:24:08
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-24 12:24:08
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < t.size(); j++) {
                if (t[j] == s[i]) {
                    ans += abs(i - j);
                    break;
                }
            }
        }
        return ans;
    }
};