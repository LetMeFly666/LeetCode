/*
 * @Author: LetMeFly
 * @Date: 2025-08-25 18:56:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-25 22:09:04
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int n = mat.size(), m = mat[0].size();
        for (int k = 0; k < m + n - 1; k++) {
            if (k % 2) {
                for (int j = min(k, m - 1), i = k - j; j >= 0 && i < n; i++, j--) {
                    ans.push_back(mat[i][j]);
                }
            } else {
                for (int i = min(k, n - 1), j = k - i; i >= 0 && j < m; i--, j++) {
                    ans.push_back(mat[i][j]);
                }
            }
        }
        return ans;
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
[[1,2,3],[4,5,6],[7,8,9]]

[1,2,4,7,5,3,6,8,9]
*/
int main() {
    string s;
    while (cin >> s) {
        vector<vector<int>> v = stringToVectorVector(s);
        Solution sol;
        debug(sol.findDiagonalOrder(v));
    }
    return 0;
}
#endif