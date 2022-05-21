/*
 * @Author: LetMeFly
 * @Date: 2022-02-15 11:19:17
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-02-15 11:34:56
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                // printf("matrix[%d][%d] = %d\n", i, j, matrix[i][j]);  //*******************
                // if (i == 2 && j == 0) {  //*******************
                    // printf("DEBUG: i = 2, j = 0\n");  //*******************
                // }  //*******************
                for (int k = 0; k < matrix[i].size(); k++) {
                    if (matrix[i][j] >= matrix[i][k]) {
                        if (k == j) continue;
                        // printf("k = %d, matrix[%d][%d] = %d, matrix[%d][%d] = %d, goto loop\n", k, i, j, matrix[i][j], i, k, matrix[i][k]);  //*******************
                        goto loop;
                    }
                }
                for (int k = 0; k < matrix.size(); k++) {
                    if (matrix[i][j] <= matrix[k][j]) {
                        if (k == i) continue;
                        // printf("k = %d, goto loop\n", k);  //*******************
                        goto loop;
                    }
                }
                ans.push_back(matrix[i][j]);
                loop:;
            }
        }
        return ans;
    }
};

#ifdef _WIN32
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        vector<vector<int>> v = stringToVectorVector(s);
        debug(v);
        debug(sol.luckyNumbers(v));
    }
    return 0;
}
#endif