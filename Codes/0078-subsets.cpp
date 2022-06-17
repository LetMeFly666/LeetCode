/*
 * @Author: LetMeFly
 * @Date: 2022-06-17 09:35:20
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-17 09:36:39
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int to = 1 << nums.size();
        for (int i = 0; i < to; i++) {
            vector<int> a;
            for (int j = 0; j < nums.size(); j++) {
                if (i & (1 << j)) {
                    a.push_back(nums[j]);
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};