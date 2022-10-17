/*
 * @Author: LetMeFly
 * @Date: 2022-10-17 10:48:47
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-17 10:50:04
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int longestPalindrome(string& s) {
        int cnt[256] = {0};
        for (char& c : s) {
            cnt[c]++;
        }
        bool hasOdd = false;
        int ans = 0;
        for (int i = 0; i < 256; i++) {
            if (cnt[i] % 2) {
                hasOdd = true;
                ans += cnt[i] - 1;
            }
            else {
                ans += cnt[i];
            }
        }
        ans += hasOdd;
        return ans;
    }
};