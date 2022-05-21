/*
 * @Author: LetMeFly
 * @Date: 2022-05-14 09:53:44
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-14 10:18:13
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = target.size();
        int ans[1 << n];
        memset(ans, -1, sizeof(ans));
        ans[0] = 0;

        /* 求得生成mask所需的最少剪切次数，其中mask的第i位如果为1说明需要target的第i个字符 */
        function<void(int)> getBestAns = [&](int mask) {
            if (ans[mask] != -1)
                return;
            ans[mask] = 1e7;
            for (string& sticker : stickers) {
                int have[26] = {0};
                for (char& c : sticker) {
                    have[c - 'a']++;
                }
                int left = mask;
                for (int i = 0; i < n; i++) {
                    if (left & (1 << i)) {
                        if (have[target[i] - 'a']) {
                            have[target[i] - 'a']--;
                            left ^= (1 << i);
                        }
                    }
                }
                if (left < mask) {
                    getBestAns(left);
                    ans[mask] = min(ans[mask], ans[left] + 1);
                }
            }
        };
        getBestAns((1 << n) - 1);
        return ans[(1 << n) - 1] > n ? -1 : ans[(1 << n) - 1];
    }
};