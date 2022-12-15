/*
 * @Author: LetMeFly
 * @Date: 2022-12-15 21:05:40
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-15 21:08:20
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int getLucky(string& s, int k) {
        int ans = 0;
        for (char c : s) {
            ans += (c - 'a' + 1) / 10 + (c - 'a' + 1) % 10;
        }
        while (--k) {
            int temp = 0;
            while (ans) {
                temp += ans % 10;
                ans /= 10;
            }
            ans = temp;
        }
        return ans;
    }
};