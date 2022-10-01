/*
 * @Author: LetMeFly
 * @Date: 2022-10-01 09:31:35
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-01 09:31:36
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            swap(s[i], s[n - i - 1]);
        }
    }
};