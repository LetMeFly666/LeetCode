/*
 * @Author: LetMeFly
 * @Date: 2023-12-14 14:43:45
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-14 19:00:26
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int h, int w) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> prefix(n + 1, vector<int>(m + 1)), diff(n + 2, vector<int>(m + 2));
        // prefix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefix[i + 1][j + 1] = grid[i][j] + prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j];
            }
        }
        // stamp
        for (int i = 0; i + h - 1 < n; i++) {
            for (int j = 0; j + w - 1 < m; j++) {
                // (i, j) -> (i + h - 1, j + w - 1)
                if (!grid[i][j] && !(prefix[i + h][j + w] - prefix[i + h][j] - prefix[i][j + w] + prefix[i][j])) {
                    diff[i + 1][j + 1]++;
                    diff[i + 1][j + w + 1]--;
                    diff[i + h + 1][j + 1]--;
                    diff[i + h + 1][j + w + 1]++;
                }
            }
        }
        // un-diff
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                diff[i + 1][j + 1] += diff[i][j + 1] + diff[i + 1][j] - diff[i][j];
                if (!grid[i][j] && !diff[i + 1][j + 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};

#ifdef _WIN32
/*
[[0,0,0,0,0],[0,0,0,0,0],[0,0,1,0,0],[0,0,0,0,1],[0,0,0,1,1]] 2 2

false
0 0 0 0 0
0 0 0 0 0
0 0 1 0 0
0 0 0 0 1
0 0 0 1 1
*/
/*
[[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0]] 4 3

*/
int main() {
    string s;
    int a, b;
    Solution sol;
    while (cin >> s >> a >> b) {
        vector<vector<int>> v = stringToVectorVector(s);
        cout << sol.possibleToStamp(v, a, b) << endl;
    }
    return 0;
}
#endif