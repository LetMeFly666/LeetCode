/*
 * @Author: LetMeFly
 * @Date: 2024-05-26 09:21:42
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-26 09:26:34
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        vector<vector<int>> prefix(matrix.size() + 1, vector<int>(matrix[0].size() + 1));
        vector<int> vals;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                prefix[i + 1][j + 1] = prefix[i + 1][j] ^ prefix[i][j + 1] ^ prefix[i][j] ^ matrix[i][j];
                vals.push_back(prefix[i + 1][j + 1]);
            }
        }
        sort(vals.begin(), vals.end());
        return vals[vals.size() - k];
    }
};