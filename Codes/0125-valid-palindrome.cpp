/*
 * @Author: LetMeFly
 * @Date: 2022-07-20 12:35:30
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-20 12:52:48
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry
class Solution {
private:
    string strip(string& s) {
        string ans;
        for (char& c : s) {
            if (c >= 'a' && c <= 'z')
                ans += c;
            else if (c >= 'A' && c <= 'Z')
                ans += (char)(c + 32);
            else if (c >= '0' && c <= '9')
                ans += c;
        }
        return ans;
    }
public:
    bool isPalindrome(string& s) {
        s = strip(s);
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1])
                return false;
        }
        return true;
    }
};
#else  // FirstTry
class Solution {
private:
    inline bool isCN(char c) {
        if (c >= 'A' && c <= 'Z')
            return true;
        if (c >= 'a' && c <= 'z')
            return true;
        if (c >= '0' && c <= '9')
            return true;
        return false;
    }
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            // 找到下一个字母数字
            while (!isCN(s[l]) && l < r)
                l++;
            while (!isCN(s[r]) && l < r)
                r--;
            // 字母的话统一转为小写
            if (s[l] >= 'A' && s[l] <= 'Z')
                s[l] += 32;
            if (s[r] >= 'A' && s[r] <= 'Z')
                s[r] += 32;
            // printf("l = %d, r = %d, s[%d] = %c, s[%d] = %c\n", l, r, l, s[l], r, s[r]);  //**********
            if (s[l] != s[r])
                return false;
            l++, r--;
        }
        return true;
    }
};
#endif  // FirstTry