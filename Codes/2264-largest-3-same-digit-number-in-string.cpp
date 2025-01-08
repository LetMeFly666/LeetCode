/*
 * @Author: LetMeFly
 * @Date: 2025-01-08 15:25:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-08 15:33:22
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // WA - 必须是子字符串
class Solution {
public:
    string largestGoodInteger(string num) {
        int bin[10] = {0};
        for (char c : num) {
            bin[c - '0']++;
        }
        for (int i = 9; i >= 0; i--) {
            if (bin[i] >= 3) {
                return to_string(i) + to_string(i) + to_string(i);
            }
        }
        return "";
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    string largestGoodInteger(string& num) {
        char M = '/';  // ASCII在0前一个
        for (int i = 2; i < num.size(); i++) {
            if (num[i] == num[i - 1] && num[i] == num[i - 2]) {
                M = max(M, num[i]);
            }
        }
        return M == '/' ? string() : string(3, M);
    }
};
#endif  // FirstTry