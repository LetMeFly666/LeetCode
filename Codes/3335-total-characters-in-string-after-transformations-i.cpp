/*
 * @Author: LetMeFly
 * @Date: 2025-05-13 09:02:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-13 09:10:46
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
// private:
//     void debug(int a[26]) {
//         for (int i = 0; i < 26; i++) {
//             cout << a[i] << ' ';
//         }
//         puts("");
//     }
public:
    int lengthAfterTransformations(string s, int t) {
        int cnt[26] = {0};
        for (char c : s) {
            cnt[c - 'a']++;
        }
        int ans = s.size();
        while (t--) {
            int z = cnt[25];
            for (int i = 24; i >= 0; i--) {  // 这里必须从后往前
                cnt[i + 1] = cnt[i];
            }
            cnt[0] = z;
            cnt[1] += z;
            ans += z;
            // debug(cnt);
        }
        return ans;
    }
};