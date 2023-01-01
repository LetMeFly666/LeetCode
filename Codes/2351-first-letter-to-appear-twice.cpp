/*
 * @Author: LetMeFly
 * @Date: 2023-01-01 09:22:41
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-01-01 09:22:42
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    char repeatedCharacter(string s) {
        bool appeared[26] = {false};
        for (char c : s) {
            if (appeared[c - 'a'])
                return c;
            appeared[c - 'a'] = true;
        }
        return 0;  // FakeReturn
    }
};