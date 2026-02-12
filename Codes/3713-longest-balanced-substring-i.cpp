/*
 * @Author: LetMeFly
 * @Date: 2026-02-12 22:41:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-12 22:44:27
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool ok(int[] cnt) {
        for (int i = 1; i < 26; i++) {
            if (cnt[i] != cnt[0]) {
                return false;
            }
        }
        return true;
    }
public:
    int longestBalanced(string s) {
        int ans = 0;
        for (int i = 0, n = s.size(); i < n; i++) {
            int cnt[26] = {0};
            for (int j = i; j < n; j++) {
                cnt[s[j] - 'a']++;
                if (ok(cnt)) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};