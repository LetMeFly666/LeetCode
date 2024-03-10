/*
 * @Author: LetMeFly
 * @Date: 2024-03-10 11:46:13
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-10 11:50:02
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string getHint(string secret, string guess) {
        int se[10] = {0}, gu[10] = {0};
        int A = 0, AB = 0;
        for (char c : secret) {
            se[c - '0']++;
        }
        for (int i = 0; i < guess.size(); i++) {
            gu[guess[i] - '0']++;
            if (guess[i] == secret[i]) {
                A++;
            }
        }
        for (int i = 0; i < 10; i++) {
            AB += min(se[i], gu[i]);
        }
        return to_string(A) + "A" + to_string(AB - A) + "B";
    }
};