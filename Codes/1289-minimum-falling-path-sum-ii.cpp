/*
 * @Author: LetMeFly
 * @Date: 2023-08-10 07:57:31
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-08-10 08:17:54
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error, 相邻行的列可以不相邻！
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 1; i < n; i++) {
            grid[i][0] += grid[i - 1][1];
            grid[i][m - 1] += grid[i - 1][m - 2];
            for (int j = 1; j < m - 1; j++) {
                grid[i][j] += min(grid[i - 1][j - 1], grid[i - 1][j + 1]);
            }
        }
        return *min_element(grid.back().begin(), grid.back().end());
    }
};
#else  // FirstTry
// SecondTry
class Solution {
private:
    pair<int, int> findMin2(vector<int>& v) {  // 只接收长度大于等于2的v
        pair<int, int> ans;
        int m = v[0], loc = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] < m) {
                m = v[i], loc = i;
            }
        }
        ans.first = loc;
        loc = ans.first ? 0 : 1, m = v[loc];  // 如果第一个元素是最小的，那么找第二个最小元素的时候就从上一行的第二个元素开始
        for (int i = 0; i < v.size(); i++) {
            if (v[i] < m && i != ans.first) {
                m = v[i], loc = i;
            }
        }
        ans.second = loc;
        return ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 1; i < n; i++) {
            pair<int, int> last2min = findMin2(grid[i - 1]);  // i >= 1说明grid[i - 1].size() >= 2
            for (int j = 0; j < n; j++) {
                grid[i][j] += (j == last2min.first ? grid[i - 1][last2min.second] : grid[i - 1][last2min.first]);
            }
        }
        return *min_element(grid.back().begin(), grid.back().end());
    }
};
#endif  // FirstTry

/*
[2,2,1,2,2]
[2,2,1,2,2]
[2,2,1,2,2]
[2,2,1,2,2]
[2,2,1,2,2]
*/