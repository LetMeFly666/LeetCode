/*
 * @Author: LetMeFly
 * @Date: 2024-05-20 23:34:51
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-20 23:38:38
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int longestAwesome(string s) {
        int mask = 0, ans = 1;
        unordered_map<int, int> ma;
        ma[0] = -1;
        for (int i = 0; i < s.size(); i++) {
            mask ^= (1 << (s[i] - '0'));
            if (ma.count(mask)) {
                ans = max(ans, i - ma[mask]);
            }
            else {
                ma[mask] = i;
            }
            // 一个奇数次字符
            for (int j = 0; j < 10; j++) {
                int mask2 = mask ^ (1 << j);
                if (ma.count(mask2)) {
                    ans = max(ans, i - ma[mask2]);
                }
            }
        }
        return ans;
    }
};