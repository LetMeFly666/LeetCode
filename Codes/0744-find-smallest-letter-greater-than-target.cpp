/*
 * @Author: LetMeFly
 * @Date: 2026-01-31 13:49:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-31 13:50:40
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<char>::iterator it = upper_bound(letters.begin(), letters.end(), target);
        return it == letters.end() ? letters[0] : *it;
    }
};