/*
 * @Author: LetMeFly
 * @Date: 2022-02-13 11:26:21
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-02-13 11:30:59
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int bin[26] = {0};
        for (char& c : text) {
            bin[c - 'a']++;
        }
        int ans = bin[0];
        ans = min(ans, bin[1]);
        ans = min(ans, bin['l' - 'a'] / 2);
        ans = min(ans, bin['o' - 'a'] / 2);
        ans = min(ans, bin['n' - 'a']);
        return ans;
    }
};