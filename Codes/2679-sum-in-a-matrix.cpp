/*
 * @Author: LetMeFly
 * @Date: 2023-07-04 06:53:31
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-07-04 06:55:11
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size();
        for (int i = 0; i < n; i++) {
            sort(nums[i].begin(), nums[i].end());
        }
        int ans = 0;
        for (int j = m - 1; j >= 0; j--) {
            int M = 0;
            for (int i = 0; i < n; i++) {
                M = max(M, nums[i][j]);
            }
            ans += M;
        }
        return ans;
    }
};