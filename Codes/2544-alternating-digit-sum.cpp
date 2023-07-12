/*
 * @Author: LetMeFly
 * @Date: 2023-07-12 08:43:57
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-07-12 08:45:10
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int alternateDigitSum(int n) {
        string s = to_string(n);
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans += (i % 2 ? -1 : 1) * (s[i] - '0');
        }
        return ans;
    }
};