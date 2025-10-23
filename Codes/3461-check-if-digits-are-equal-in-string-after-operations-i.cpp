/*
 * @Author: LetMeFly
 * @Date: 2025-10-23 23:05:13
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-23 23:23:01
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

/*
>>> ord('0')
48
>>> ord('0') * 2
96
>>> chr(96)   
'`'
>>> ord('`')
96
*/
class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string newS;
            for (int i = 1; i < s.size(); i++) {
                cout << '(' << s[0] << '+' << s[1] << " - '`') % 10 + '0' = " << char((s[0] + s[1] - '`') % 10 + '0') << endl;
                newS.push_back((s[0] + s[1] - '`') % 10 + '0');
            }
            s = move(newS);
            cout << s << endl;
        }
        return s[0] == s[1];
    }
};