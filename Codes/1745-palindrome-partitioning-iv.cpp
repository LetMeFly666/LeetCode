/*
 * @Author: LetMeFly
 * @Date: 2025-03-04 10:18:19
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-04 10:28:38
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> isok(n, vector<bool>(n, true));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                isok[i][j] = s[i] == s[j] && isok[i + 1][j - 1];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                if (isok[0][i] && isok[i + 1][j] && isok[j + 1][n - 1]) {
                    return true;
                }
            }
        }
        return false;
    }
};