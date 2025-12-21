/*
 * @Author: LetMeFly
 * @Date: 2025-12-20 22:44:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-20 22:48:32
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        int ans = 0;
        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                if (strs[i][j] < strs[i - 1][j]) {  // 好吧，相同相邻字符是合法的
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};