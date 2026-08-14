/*
 * @Author: LetMeFly
 * @Date: 2026-08-14 09:32:01
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-14 09:33:37
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool ok(int cnt[26]) {
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 2) {
                return false;
            }
        }
        return true;
    }
public:
    int maximumLengthSubstring(string s) {
        int ans = 0;
        for (int i = 0, n = s.size(); i < n; i++) {
            int cnt[26] = {0};
            for (int j = i; j < n; j++) {
                cnt[s[j] - 'a']++;
                if (ok(cnt)) {
                    ans = max(ans, j - i + 1);
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};
