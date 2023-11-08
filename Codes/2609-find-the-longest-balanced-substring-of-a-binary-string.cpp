/*
 * @Author: LetMeFly
 * @Date: 2023-11-08 18:55:09
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-08 19:06:20
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int ans = 0, index = 0;
        while (index < s.size()) {
            int cnt0 = 0, cnt1 = 0;
            while (index < s.size() && s[index] == '0') {
                cnt0++, index++;
            }
            while (index < s.size() && s[index] == '1') {
                cnt1++, index++;
            }
            ans = max(ans, 2 * min(cnt0, cnt1));
        }
        return ans;
    }
};