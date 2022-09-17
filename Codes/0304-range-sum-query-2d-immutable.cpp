/*
 * @Author: LetMeFly
 * @Date: 2022-09-17 10:36:13
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-17 10:56:47
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class NumMatrix {
private:
    vector<vector<int>> prefix;

    void init(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        prefix.resize(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefix[i + 1][j + 1] = prefix[i + 1][j] + prefix[i][j + 1] - prefix[i][j] + a[i][j];
            }
        }
    }
public:
    NumMatrix(vector<vector<int>>& matrix) {
        init(matrix);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2 + 1][col2 + 1] - prefix[row1][col2 + 1] - prefix[row2 + 1][col1] + prefix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */