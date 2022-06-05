/*
 * @Author: LetMeFly
 * @Date: 2022-06-05 11:17:24
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-05 11:18:25
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        for (int i = 1; i <= n; i++) {
            s += (char)(i + '0');
        }
        for (int i = 1; i < k; i++) {
            next_permutation(s.begin(), s.end());
        }
        return s;
    }
};