/*
 * @Author: LetMeFly
 * @Date: 2022-06-12 09:22:59
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-12 09:33:12
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> D(n + 1, vector<int>(m + 1));
        for (int i = 0; i <= n; i++)
            D[i][0] = i;
        for (int j = 0; j <= m; j++) 
            D[0][j] = j;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                D[i][j] = min(min(D[i - 1][j], D[i][j - 1]) + 1, word1[i - 1] == word2[j - 1] ? D[i - 1][j - 1] : D[i - 1][j - 1] + 1);  // word的下标是从0开始的
            }
        }
        return D[n][m];
    }
};