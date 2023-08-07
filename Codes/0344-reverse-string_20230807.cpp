/*
 * @Author: LetMeFly
 * @Date: 2023-08-07 07:56:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-08-07 07:56:11
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0; i < s.size() / 2; i++) {
            swap(s[i], s[s.size() - i - 1]);
        }
    }
};