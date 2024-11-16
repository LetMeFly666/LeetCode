/*
 * @Author: LetMeFly
 * @Date: 2024-11-16 13:12:39
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-16 13:14:05
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < m / 2; j++) {
                int cnt1 = grid[i][j] + grid[i][m - j - 1] + grid[n - i - 1][j] + grid[n - i - 1][m - j - 1];
                ans += min(cnt1, 4 - cnt1);
            }
        }
        if (n % 2 && m % 2) {
            ans += grid[n / 2][m / 2];
        }
        int cnt11 = 0, cnt0110 = 0;
        if (n % 2 == 1) {
            for (int j = 0; j < m / 2; j++) {
                if (grid[n / 2][j] == grid[n / 2][m - j - 1]) {
                    if (grid[n / 2][j] == 1) {
                        cnt11++;
                    }
                } else {
                    cnt0110++;
                }
            }
        }
        if (m % 2 == 1) {
            for (int i = 0; i < n / 2; i++) {
                if (grid[i][m / 2] == grid[n - i - 1][m / 2]) {
                    if (grid[i][m / 2] == 1) {
                        cnt11++;
                    }
                } else {
                    cnt0110++;
                }
            }
            
        }
        ans += cnt0110;
        if (cnt11 % 2 == 0 || cnt0110 > 0) {
            return ans;
        } else {
            return ans + 2;
        }
        return ans;
    }
};