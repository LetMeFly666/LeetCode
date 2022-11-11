/*
 * @Author: LetMeFly
 * @Date: 2022-11-11 08:57:22
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-11 09:00:24
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool YuanYin(char c) {  // 只接受小写字母
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    bool halvesAreAlike(string& s) {
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (i < n / 2)
                cnt += YuanYin(tolower(s[i]));
            else
                cnt -= YuanYin(tolower(s[i]));
        }
        return !cnt;
    }
};