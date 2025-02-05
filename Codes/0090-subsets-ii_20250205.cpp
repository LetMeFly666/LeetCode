/*
 * @Author: LetMeFly
 * @Date: 2025-02-05 12:22:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-05 12:24:34
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < (1 << nums.size()); i++) {
            vector<int> thisAns;
            for (int j = 0; j < nums.size(); j++) {
                if (i >> j & 1) {
                    thisAns.push_back(nums[j]);
                }
            }
            if (find(ans.begin(), ans.end(), thisAns) == ans.end()) {
                ans.push_back(thisAns);
            }
        }
        return ans;
    }
};