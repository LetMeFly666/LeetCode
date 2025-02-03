/*
 * @Author: LetMeFly
 * @Date: 2025-02-03 08:52:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-03 08:57:47
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool isOk(string& s, int l, int r) {
        for (; l < r; l++, r--) {
            if (s[l] != s[r]) {
                return false;
            }
        }
        return true;
    }
public:
    bool validPalindrome(string& s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return isOk(s, i, j - 1) || isOk(s, i + 1, j);
            }
        }
        return true;
    }
};