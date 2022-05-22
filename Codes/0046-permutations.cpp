/*
 * @Author: LetMeFly
 * @Date: 2022-05-22 13:38:55
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-22 13:39:56
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        ans.push_back(nums);
        while (next_permutation(nums.begin(), nums.end())) {
            ans.push_back(nums);
        }
        return ans;
    }
};