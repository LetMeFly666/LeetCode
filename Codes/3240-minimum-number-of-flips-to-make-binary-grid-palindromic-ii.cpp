/*
 * @Author: LetMeFly
 * @Date: 2024-11-16 12:47:41
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-16 13:09:36
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
step1: 先不考虑4的倍数个1，计算最小翻转次数

step2: 再考虑1的个数问题：

偶数行偶数列：(1必定是4的倍数个)直接返回
奇数行偶数列：看中间那一行有多少对11和多少对10/01
    + 偶数对11：(step1时可以把所有01/10变成00)直接返回
    + 奇数对11：看有无10/01：
        + 有10/01：(step1时把中间这一行的其中一对10/01变成11)直接返回
        + 无10/01：(step2必须把一对11变成00)step1结果+2后返回
偶数行奇数列：和奇数行偶数列同理
奇数行奇数列：要看“最中心元素”和“中间行中间列除最中间元素外的部分”两部分
    + 最中心元素：
        + 若为1：(必须变为0)step1+1
        + 若为0：step1不变
    + 中间行中间列除最中间元素外的部分：类似奇数行偶数列，统计这些元素中所有的11对和10/01对，之后同理
*/
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
        if (n % 2 == 0 && m % 2 == 0) {
            return ans;
        } else if (n % 2 == 1 && m % 2 == 0) {
            int cnt11 = 0, cnt0110 = 0;
            for (int j = 0; j < m / 2; j++) {
                if (grid[n / 2][j] == grid[n / 2][m - j - 1]) {
                    if (grid[n / 2][j] == 1) {
                        cnt11++;
                    }
                } else {
                    cnt0110++;
                }
            }
            ans += cnt0110;
            if (cnt11 % 2 == 0 || cnt0110 > 0) {
                return ans;
            } else {
                return ans + 2;
            }
        } else if (n % 2 == 0 && m % 2 == 1) {
            int cnt11 = 0, cnt0110 = 0;
            for (int i = 0; i < n / 2; i++) {
                if (grid[i][m / 2] == grid[n - i - 1][m / 2]) {
                    if (grid[i][m / 2] == 1) {
                        cnt11++;
                    }
                } else {
                    cnt0110++;
                }
            }
            ans += cnt0110;
            if (cnt11 % 2 == 0 || cnt0110 > 0) {
                return ans;
            } else {
                return ans + 2;
            }
        } else {
            if (grid[n / 2][m / 2]) {
                ans++;
            }
            int cnt11 = 0, cnt0110 = 0;
            for (int j = 0; j < m / 2; j++) {
                if (grid[n / 2][j] == grid[n / 2][m - j - 1]) {
                    if (grid[n / 2][j] == 1) {
                        cnt11++;
                    }
                } else {
                    cnt0110++;
                }
            }
            for (int i = 0; i < n / 2; i++) {
                if (grid[i][m / 2] == grid[n - i - 1][m / 2]) {
                    if (grid[i][m / 2] == 1) {
                        cnt11++;
                    }
                } else {
                    cnt0110++;
                }
            }
            ans += cnt0110;
            if (cnt11 % 2 == 0 || cnt0110 > 0) {
                return ans;
            } else {
                return ans + 2;
            }
        }
    }
};