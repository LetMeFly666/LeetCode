/*
 * @Author: LetMeFly
 * @Date: 2024-06-22 16:45:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-22 16:57:14
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*

abcz - abda
*/
class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        s.back() += 1;
        char maxChar = k + 'a';
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] > k) {  // 需要进位
                if (i == 0) {  // 无法继续进位
                    return "";
                }
                s[i] = 'a';
                s[i - 1]++;
            }
            if (s[i] == s[i + 1])
        }
    }
};