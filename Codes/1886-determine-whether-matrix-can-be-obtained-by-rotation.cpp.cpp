/*
 * @Author: LetMeFly
 * @Date: 2026-03-22 23:35:27
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-22 23:44:12
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

// THIS CANNOT BE ACCEPTED
class Solution {
private:
    int n = 0;
    vector<vector<int>>& rotate(vector<vector<int>>& original) {
        if (!n) {
            n = original.size();
        }
        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = original[j][n - i - 1];
            }
        }
        return ans;
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if (mat == target) {
            return true;
        }
        for (int _ = 0; _ < 3; _++) {
            mat = rotate(mat);
            if (mat == target) {
                return true;
            }
        }
        return false;
    }
};