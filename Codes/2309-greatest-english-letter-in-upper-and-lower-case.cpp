/*
 * @Author: LetMeFly
 * @Date: 2023-01-27 09:53:43
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-01-27 10:01:37
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error  // 不是第一个出现了大写和小写的“最好”，而是所有的出现了大写和小写的字母中字典序最大的“最好”
class Solution {
public:
    string greatestLetter(string s) {
        bool se[256] = {false};
        for (char c : s) {
            se[c] = true;
            if (se[c ^ 32]) {
                return string(1, isupper(c) ? c : (c ^ 32));
            }
        }
        return "";
    }
};
#else  // FirstTry
class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char> se(s.begin(), s.end());
        for (int i = 25; i >= 0; i--) {
            if (se.count('a' + i) && se.count('A' + i)) {
                return string(1, 'A' + i);
            }
        }
        return "";
    }
};
#endif  // FirstTry