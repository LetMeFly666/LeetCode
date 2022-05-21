/*
 * @Author: LetMeFly
 * @Date: 2022-04-14 13:37:47
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-14 13:46:53
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string longestPalindrome(string s) {
        int M = 0;
        int left, length;
        for (int middle = 0; middle < s.size(); middle++) {
            int expand = 0;
            while (middle - expand >= 0 && middle + expand < s.size() && s[middle - expand] == s[middle + expand]) {
                expand++;
            }
            if (expand * 2 - 1 > M) {
                M = expand * 2 - 1;
                left = middle - expand + 1;
                length = expand * 2 - 1;
            }
            expand = 0;
            while (middle - expand >= 0 && middle + expand + 1 < s.size() && s[middle - expand] == s[middle + expand + 1]) {
                expand++;
            }
            if (expand * 2 > M) {
                M = expand * 2;
                left = middle - expand + 1;
                length = expand * 2;
            }
        }
        return s.substr(left, length);
    }
};