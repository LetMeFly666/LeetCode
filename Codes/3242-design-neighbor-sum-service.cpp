/*
 * @Author: LetMeFly
 * @Date: 2024-11-09 09:55:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-09 10:06:29
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

const int adj[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const int dia[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

class NeighborSum {
private:
    vector<pair<int, int>> cache;
public:
    NeighborSum(vector<vector<int>>& grid) {
        int n = grid.size();
        cache.resize(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int cntAdj = 0, cntDia = 0;
                for (int k = 0; k < 4; k++) {
                    int x = i + adj[k][0], y = j + adj[k][1];
                    if (x >= 0 && x < n && y >= 0 && y < n) {
                        cntAdj += grid[x][y];
                    }
                    x = i + dia[k][0], y = j + dia[k][1];
                    if (x >= 0 && x < n && y >= 0 && y < n) {
                        cntDia += grid[x][y];
                    }
                }
                cache[grid[i][j]] = {cntAdj, cntDia};
            }
        }
    }
    
    int adjacentSum(int value) {
        return cache[value].first;
    }
    
    int diagonalSum(int value) {
        return cache[value].second;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */