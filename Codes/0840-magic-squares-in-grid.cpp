#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline bool is(vector<vector<int>>& grid, int i, int j) {
        int mask = 0;
        int rowCnt[3] = {0}, colCnt[3] = {0};
        for (int di = 0; di < 3; di++) {
            for (int dj = 0; dj < 3; dj++) {
                int v = grid[i - di][j - dj];
                mask |= 1 << v;
                rowCnt[di] += v;
                colCnt[dj] += v;
            }
        }
        if (mask != (1 << 10) - 2) {  // (1<<10)-1：1111111111（10个1）而mask没有或上1<<0所以再-1
            return false;
        }

        int cnt = rowCnt[0];
        for (int d = 0; d < 3; d++) {
            if (rowCnt[d] != cnt || colCnt[d] != cnt) {
                return false;
            }
        }
        if (grid[i][j] + grid[i - 1][j - 1] + grid[i - 2][j - 2] != cnt) {
            return false;
        }
        if (grid[i - 2][j] + grid[i - 1][j - 1] + grid[i][j - 2] != cnt) {
            return false;
        }
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 2; i < n; i++) {
            for (int j = 2; j < m; j++) {
                ans += is(grid, i, j);
            }
        }
        return ans;
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
[[4,3,8,4],[9,5,1,9],[2,7,6,2]]

1
*/
void dbg1to9() {
    int mask = 0;
    for (int i = 1; i < 10; i++) {
        mask |= 1 << i;
    }
    cout << mask << endl;  // 1022不是1023，因为mask没有或上1<<0
}

int main() {
    dbg1to9();

    string s;
    while (cin >> s) {
        Solution sol;
        vector<vector<int>> v = stringToVectorVector(s);
        cout << sol.numMagicSquaresInside(v) << endl;
    }
    return 0;
}
#endif