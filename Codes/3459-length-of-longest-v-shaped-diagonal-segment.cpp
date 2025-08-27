/*
 * @Author: LetMeFly
 * @Date: 2025-08-27 23:08:01
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-27 23:53:17
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    const int directions[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    vector<vector<int>> grid;
    unordered_map<int, int> cache;

    inline bool canContinue(int i, int j, int ni, int nj) {
        int thisVal = grid[i][j], nextVal = grid[ni][nj];
        return (thisVal == 1 && nextVal != 1) || (thisVal != 1 && nextVal != 1 && thisVal != nextVal);
    }

    /*
    >>> 500 * 500
    250000
    >>> 500 * 500 * 4 * 2
    2000000
    >>> 500 * 4 * 2
    4000
    >>> 4 * 2
    8
    */
    inline int getCacheKey(int i, int j, int d, int times) {
        return i * 4000 + j * 8 + d * 2;
    }

    int dfs(int i, int j, int d, int times) {
        int cacheKey = getCacheKey(i, j, d, times);
        if (cache.count(cacheKey)) {
            return cache[cacheKey];
        }
        int toAdd = 0;
        int ni = i + directions[d][0], nj = j + directions[d][1];
        if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size()) {
            if (canContinue(i, j, ni, nj)) {
                toAdd = dfs(ni, nj, d, times);
            }
        }
        if (times == 0) {
            for (int nd = 0; nd < 4; nd++) {
                if (abs(nd - d) == 2) {
                    continue;
                }
                int ni = i + directions[nd][0], nj = j + directions[nd][1];
                if (!(ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size())) {
                    continue;
                }
                if (canContinue(i, j, ni, nj)) {
                    toAdd = max(toAdd, dfs(ni, nj, nd, 1));
                }
            }
        }
        return cache[cacheKey] = 1 + toAdd;
    }
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        this->grid = move(grid);
        int ans = 0;
        for (int i = 0; i < this->grid.size(); i++) {
            for (int j = 0; j < this->grid[i].size(); j++) {
                if (this->grid[i][j] != 1) {
                    continue;
                }
                for (int d = 0; d < 4; d++) {
                    ans = max(ans, dfs(i, j, d, 0));
                }
            }
        }
        return ans;
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
[[2,2,1,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]

5
*/
int main() {
    string s;
    while (cin >> s) {
        vector<vector<int>> v = stringToVectorVector(s);
        Solution sol;
        cout << sol.lenOfVDiagonal(v) << endl;
    }
    return 0;
}
#endif