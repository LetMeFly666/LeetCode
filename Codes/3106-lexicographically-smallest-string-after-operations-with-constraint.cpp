/*
 * @Author: LetMeFly
 * @Date: 2024-07-27 22:58:03
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-27 22:59:54
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string getSmallestString(string s, int k) {
        for (char &c : s) {
            int left = c - 'a', right = 'z' - c + 1;
            if (k >= right && right < left) {
                c = 'a';
                k -= right;
            }
            else {
                int move = min(left, k);
                c -= move;
                k -= move;
            }
            if (k == 0) {
                break;
            }
        }
        return s;
    }
};