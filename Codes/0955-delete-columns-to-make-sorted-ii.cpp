/*
 * @Author: LetMeFly
 * @Date: 2025-12-21 20:40:47
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-21 20:46:33
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        int n = strs.size(), m = strs[0].size();
        int totalSkip = 1;  // 第一行不用校验
        vector<bool> canSkip(n);
        for (int j = 0; j < m; j++) {
            bool can = true;
            for (int i = 1; i < n; i++) {
                if (canSkip[i]) {
                    continue;
                }
                if (strs[i][j] < strs[i-1][j]) {
                    can = false;
                    break;
                }
            }
            if (can) {
                for (int i = 1; i < n; i++) {
                    if (strs[i][j] != strs[i-1][j] && !canSkip[i]) {
                        canSkip[i] = true;
                        totalSkip++;
                        if (totalSkip == n) {
                            return ans;
                        }
                    }
                }
            } else {
                ans++;
            }
        }
        return ans;
    }
};