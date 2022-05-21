/*
 * @Author: LetMeFly
 * @Date: 2022-01-01 13:20:05
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-01-01 13:21:17
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        if (m * n != original.size()) 
            return ans;
        int loc = 0;
        for (int i = 0; i < m; i++) {
            vector<int> thisVector;
            for (int j = 0; j < n; j++)
                thisVector.push_back(original[loc++]);
            ans.push_back(thisVector);
        }
        return ans;
    }
};