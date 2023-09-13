/*
 * @Author: LetMeFly
 * @Date: 2023-09-13 08:49:02
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-09-13 09:48:13
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef tuple<int, int, int> iii;

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0]) {
            return false;
        }
        int n = grid.size();
        vector<iii> v(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                v[i * n + j] = {grid[i][j], i, j};
            }
        }
        sort(v.begin(), v.end());
        int nowX = get<1>(v[0]), nowY = get<2>(v[0]);
        for (int i = 1; i < n * n; i++) {
            int nextX = get<1>(v[i]), nextY = get<2>(v[i]);
            int diffX = abs(nextX - nowX), diffY = abs(nextY -nowY);
            if (!(diffX == 2 && diffY == 1 || diffX == 1 && diffY == 2)) {
                return false;
            }
            nowX = nextX, nowY = nextY;
        }
        return true;
    }
};


/*
0 3 6
5 8 1
2 7 4
*/

/*
24 11 22 17 4
21 16 5  12 9
6  23 10 3 18
15 20 1  8 13
0  7  14 19 2
*/