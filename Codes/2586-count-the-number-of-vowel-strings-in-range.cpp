/*
 * @Author: LetMeFly
 * @Date: 2023-11-07 22:28:58
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-07 22:31:31
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline int can(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    int vowelStrings(vector<string>& words, int l, int r) {
        int ans = 0;
        for (int i = l; i <= r; i++) {
            ans += can(words[i][0]) && can(words[i].back());
        }
        return ans;
    }
};