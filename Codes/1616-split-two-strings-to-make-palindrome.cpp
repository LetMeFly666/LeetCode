/*
 * @Author: LetMeFly
 * @Date: 2023-03-18 12:55:53
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-18 13:08:12
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error，还想着要么本身回文，要么两个的前后互为回文
class Solution {
private:
    bool ifSelfPalindrome(string& s) {
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }

    bool ifOk(string& a, string& b) {
        int la = -1, lb = b.size();
        while (lb - la > 2) {
            if (a[++la] != b[--lb]) {
                return false;
            }
        }
        return true;
    }
public:
    bool checkPalindromeFormation(string& a, string& b) {
        return ifSelfPalindrome(a) || ifSelfPalindrome(b) || ifOk(a, b) || ifOk(b, a);
    }
};
#else  // FirstTry
// SecondTry
class Solution {
private:
    bool ifSelfPalindrome(string& s, int l, int r) {  // s[l, r]
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }

    bool ifOk(string& a, string& b) {
        int la = 0, lb = b.size() - 1;
        while (la < lb) {
            if (a[la] != b[lb]) {
                if (ifSelfPalindrome(a, la, lb) || ifSelfPalindrome(b, la, lb)) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                la++, lb--;
            }
        }
        return true;  // la和lb相遇了
    }
public:
    bool checkPalindromeFormation(string& a, string& b) {
        return ifOk(a, b) || ifOk(b, a);
    }
};
#endif