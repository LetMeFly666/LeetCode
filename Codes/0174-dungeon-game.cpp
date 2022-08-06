/*
 * @Author: LetMeFly
 * @Date: 2022-08-06 09:08:15
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-06 09:36:13
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error  // 从左上到右下不满足“无后效性”
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i - 1 >= 0 && j - 1 >= 0) {
                    dungeon[i][j] += max(dungeon[i - 1][j], dungeon[i][j - 1]);
                }
                else if (i - 1 >= 0) {
                    dungeon[i][j] += dungeon[i - 1][j];
                }
                else if (j - 1 >= 0) {
                    dungeon[i][j] += dungeon[i][j - 1];
                }
                ans = max(ans, -dungeon[i][j] + 1);
            }
        }

        return ans;
    }
};
#else  // FirstTry
// SecondTry  // 右下到左上
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        dungeon[n - 1][m - 1] = max(1, 1 - dungeon[n - 1][m - 1]);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i + 1 < n && j + 1 < m) {
                    dungeon[i][j] = max(1, min(dungeon[i + 1][j], dungeon[i][j + 1]) - dungeon[i][j]);
                }
                else if (i + 1 < n) {
                    dungeon[i][j] = max(1, dungeon[i + 1][j] - dungeon[i][j]);
                }
                else if (j + 1 < m) {
                    dungeon[i][j] = max(1, dungeon[i][j + 1] - dungeon[i][j]);
                }
            }
        }
        return dungeon[0][0];
    }
};
#endif  // FirstTry

/*
[[-2,-3,3],[-5,-10,1],[10,30,-5]]

*/
#ifdef _WIN32
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        vector<vector<int>> v = stringToVectorVector(s);
        cout << sol.calculateMinimumHP(v) << endl;
    }
    return 0;
}
#endif