/*
 * @Author: LetMeFly
 * @Date: 2026-03-17 21:54:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-17 22:00:41
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

/*
1 3

[0,1]
[0,1]
[1,1]


[[0,1],[0,1],[1,1]]
*/

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        vector<int> heights(n);
        int ans = 0;
        for (vector<int>& row : matrix) {
            for (int i = 0; i < n; i++) {
                heights[i] = row[i] ? heights[i] + 1 : 0;
            }
            vector<int> ordered_heights = heights;
            sort(ordered_heights.begin(), ordered_heights.end());
            for (int i = 0; i < n; i++) {
                ans = max(ans, ordered_heights[i] * (n - i));
            }
        }
        return ans;
    }
};