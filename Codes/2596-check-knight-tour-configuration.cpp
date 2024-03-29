/*
 * @Author: LetMeFly
 * @Date: 2023-09-13 08:49:02
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-09-13 09:56:57
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif


#ifdef FirstTry
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
            if (abs(nextX - nowX) * abs(nextY -nowY) != 2) {
                return false;
            }
            nowX = nextX, nowY = nextY;
        }
        return true;
    }
};
#else  // FirstTry
// SecondTry
typedef pair<int, int> pii;
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pii> indices(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                indices[grid[i][j]] = {i, j};
            }
        }
        int nowX = -2, nowY = -1;
        for (int i = 0; i < n * n; i++) {
            int nextX =indices[i].first, nextY = indices[i].second;
            if (abs(nowX - nextX) * abs(nowY - nextY) != 2) {
                return false;
            }
            nowX = nextX, nowY = nextY;
        }
        return true;
    }
};
#endif  // FirstTry

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