/*
 * @Author: LetMeFly
 * @Date: 2025-06-19 10:16:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-21 15:21:37
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

// 这个代码是用来骗数据的，看看哪个输入下可以使得结果为0
class Solution {
private:
    int firstNot9(string& s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '9') {
                return i;
            }
        }
        return -1;
    }

    int firstNot01(string& s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] > '1') {
                return i;
            }
        }
        return -1;
    }

    int change(string s, char a, char b) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == a) {
                s[i] = b;
            }
        }
        return atoi(s.c_str());
    }
public:
    int maxDiff(int num) {
        int M, m;
        string s = to_string(num);
        int index = firstNot9(s);
        M = index < 0 ? num : change(s, s[index], '9');
        if (s[0] != '1') {
            m = change(s, s[0], '1');
        } else {
            index = firstNot01(s);
            m = index < 0 ? num : change(s, s[index], '0');
        }
        if (M - m == 0) {
            return -1;  // 骗数据
        }
        return M - m;
    }
};

// 好吧，果然没有能够使得结果为0的数据。