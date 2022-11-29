/*
 * @Author: LetMeFly
 * @Date: 2022-11-29 22:55:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-29 22:56:38
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minOperations(string& s) {
        int oneZero = 0;  // 101010...
        int n = s.size();
        for (int i = 0; i < n; i++) {
            oneZero += (s[i] != '0' + i % 2);
        }
        return min(oneZero, n - oneZero);
    }
};