/*
 * @Author: LetMeFly
 * @Date: 2024-05-06 17:11:07
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-06 21:16:46
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 两次dfs，ERROR!
/*
不能“走两次最优路线”

1 1 0
0 1 1
1 1 0
0 1 1

若走两次最优路线，则第一次将为：

1 1
  1
  1
  1 1

之后变成：

0 0 0
0 0 1
1 0 0
0 0 0

无法一次摘完。

一个最优解为：

1 1
  1 1
    0
    1

之后变成：

0 0 0
0 0 0
1 1 0
0 1 0

第二次走：

0
0
1 1
  1 0

这样的话所有樱桃都能摘到。
*/
class Solution {
private:
    vector<vector<int>> cnt;
    vector<vector<bool>> direction;  // true↑false←

    void dp(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (grid[i][j] == -1) {
                    cnt[i][j] = -1000000;
                    continue;
                }
                else {
                    cnt[i][j] = grid[i][j];
                }
                if (i && j) {
                    if (cnt[i - 1][j] > cnt[i][j - 1]) {
                        cnt[i][j] += cnt[i - 1][j];
                        direction[i][j] = true;
                    }
                    else {
                        cnt[i][j] += cnt[i][j - 1];
                        direction[i][j] = false;
                    }
                }
                else if (i) {
                    cnt[i][j] += cnt[i - 1][j];
                    direction[i][j] = true;
                }
                else if (j) {
                    cnt[i][j] += cnt[i][j - 1];
                    direction[i][j] = false;
                }
            }
        }
    }

    void pickupCherry(vector<vector<int>>& grid) {
        int i = grid.size() - 1, j = grid[0].size() - 1;
        while (i || j) {
            // printf("i = %d, j = %d\n", i, j);  //***************
            grid[i][j] = 0;
            if (direction[i][j]) {
                i--;
            }
            else {
                j--;
            }
        }
        grid[0][0] = 0;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        cnt.resize(grid.size(), vector<int>(grid[0].size()));
        direction.resize(grid.size(), vector<bool>(grid[0].size()));
        dp(grid);
        if (cnt.back().back() < 0) {
            return 0;
        }
        int ans = cnt.back().back();
        pickupCherry(grid);
        dp(grid);
        ans += cnt.back().back();
        return ans;
    }
};
#else  // FirstTry
// SecondTry
// 时隔2年，没想到再次Copy
// https://github.com/LetMeFly666/LeetCode/commit/4bab0d05423be7ebcb3e041fd29fd3fbf1a33381#diff-f535e47050eb4b8f79b29a9d0237894f2025c3ed755684387b97dd0768234f94R23-R63
class Solution {
public:
    int cherryPickup(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<vector<vector<int>>> f(n * 2 - 1, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        f[0][0][0] = grid[0][0];
        for (int k = 1; k < n * 2 - 1; ++k) {
            for (int x1 = max(k - n + 1, 0); x1 <= min(k, n - 1); ++x1) {
                int y1 = k - x1;
                if (grid[x1][y1] == -1) {
                    continue;
                }
                for (int x2 = x1; x2 <= min(k, n - 1); ++x2) {
                    int y2 = k - x2;
                    if (grid[x2][y2] == -1) {
                        continue;
                    }
                    int res = f[k - 1][x1][x2]; // 都往右
                    if (x1) {
                        res = max(res, f[k - 1][x1 - 1][x2]); // 往下，往右
                    }
                    if (x2) {
                        res = max(res, f[k - 1][x1][x2 - 1]); // 往右，往下
                    }
                    if (x1 && x2) {
                        res = max(res, f[k - 1][x1 - 1][x2 - 1]); // 都往下
                    }
                    res += grid[x1][y1];
                    if (x2 != x1) { // 避免重复摘同一个樱桃
                        res += grid[x2][y2];
                    }
                    f[k][x1][x2] = res;
                }
            }
        }
        return max(f.back().back().back(), 0);
    }
};
#endif  // FirstTry

#ifdef _WIN32
/*
[[0,1,-1],[1,0,-1],[1,1,1]]

5
*/

/*
[[1,1,1,1,0,0,0],[0,0,0,1,0,0,0],[0,0,0,1,0,0,1],[1,0,0,1,0,0,0],[0,0,0,1,0,0,0],[0,0,0,1,0,0,0],[0,0,0,1,1,1,1]]

15

1 1 1 1 0 0 0
0 0 0 1 0 0 0
0 0 0 1 0 0 1
1 0 0 1 0 0 0
0 0 0 1 0 0 0
0 0 0 1 0 0 0
0 0 0 1 1 1 1
*/

int main() {
    string s;
    while (cin >> s) {
        vector<vector<int>> v = stringToVectorVector(s);
        Solution sol;
        cout << sol.cherryPickup(v) << endl;
    }
    return 0;
}
#endif