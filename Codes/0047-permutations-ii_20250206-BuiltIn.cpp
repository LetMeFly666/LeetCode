/*
 * @Author: LetMeFly
 * @Date: 2025-02-06 13:52:38
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-06 13:53:41
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        do {
            ans.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return ans;
    }
};