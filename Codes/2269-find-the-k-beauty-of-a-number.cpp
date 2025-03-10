/*
 * @Author: LetMeFly
 * @Date: 2025-03-10 12:36:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-10 12:41:03
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int ans = 0;
        string s = to_string(num);
        for (int i = 0; i + k <= s.size(); i++) {
            int thisNum = 0;
            for (int j = 0; j < k; j++) {
                thisNum = thisNum * 10 + s[i + j] - '0';
            }
            ans += thisNum && (num % thisNum == 0);
        }
        return ans;
    }
};