/*
 * @Author: LetMeFly
 * @Date: 2025-06-19 10:16:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-19 10:28:35
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

// max->第一个非9的值全改为9
// min->第一位如果是1，将第一个大于1的值全改为0；否则，将第一位的值全改为1
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
        return M - m;
    }
};