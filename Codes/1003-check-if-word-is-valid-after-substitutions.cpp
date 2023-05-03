/*
 * @Author: LetMeFly
 * @Date: 2023-05-03 09:37:14
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-05-03 09:38:19
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int endWith(string& s, int startLoc, char startChar) {
        
    }
public:
    bool isValid(string& s) {
        return endWith(s, 0, 'a') == s.size();
    }
};