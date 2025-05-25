/*
 * @Author: LetMeFly
 * @Date: 2025-05-25 23:39:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-26 00:04:19
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int cnt[26][26] = {0};
        for (string& word : words) {
            cnt[word[0] - 'a'][word[1] - 'a']++;
        }
        int ans = 0, middle = 0;
        for (int i = 0; i < 26; i++) {
            ans += cnt[i][i] / 2 * 2;
            middle |= cnt[i][i] % 2;
            for (int j = i + 1; j < 26; j++) {
                ans += min(cnt[i][j], cnt[j][i]) * 2;
            }
        }
        return (ans + middle) * 2;
    }
};