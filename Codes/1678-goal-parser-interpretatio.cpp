/*
 * @Author: LetMeFly
 * @Date: 2022-11-06 08:05:18
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-06 08:07:52
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string interpret(string& command) {
        string ans;
        for (int i = 0; i < command.size(); i++) {
            if (command[i] == 'G') {
                ans += 'G';
            }
            else {  // (
                if (command[i + 1] == ')')  // ()
                    ans += 'o', i += 1;
                else  // (al)
                    ans += "al", i += 3;
            }
        }
        return ans;
    }
};