/*
 * @Author: LetMeFly
 * @Date: 2022-05-12 09:23:24
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-12 09:25:53
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        int n = strs.size(), m = strs[0].size();  // strs.size() >= 1
        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                if (strs[i][j] < strs[i - 1][j]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};