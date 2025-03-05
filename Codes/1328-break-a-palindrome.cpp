/*
 * @Author: LetMeFly
 * @Date: 2025-03-05 12:55:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-05 12:56:14
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string breakPalindrome(string palindrome) {
        if (palindrome.size() == 1) {
            return "";
        }
        for (int i = 0; i < palindrome.size() / 2; i++) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome.back() = 'b';
        return palindrome;
    }
};