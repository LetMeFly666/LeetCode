/*
 * @Author: LetMeFly
 * @Date: 2023-12-19 13:45:01
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-19 13:50:01
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int l = 0, r = mat.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            int maxLocation = max_element(mat[mid].begin(), mat[mid].end()) - mat[mid].begin();
            if (mid - 1 >= 0 && mat[mid - 1][maxLocation] > mat[mid][maxLocation]) {
                r = mid;
            }
            else if (mid + 1 < mat.size() && mat[mid + 1][maxLocation] > mat[mid][maxLocation]) {
                l = mid + 1;
            }
            else {
                return {mid, maxLocation};
            }
        }
        return {};  // Fake Return
    }
};