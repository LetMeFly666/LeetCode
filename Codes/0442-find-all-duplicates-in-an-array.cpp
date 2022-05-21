/*
 * @Author: LetMeFly
 * @Date: 2022-05-08 09:44:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-08 09:49:49
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int n = abs(nums[i]);
            if (nums[n - 1] < 0)
                ans.push_back(n);
            else
                nums[n - 1] *= -1;
        }
        return ans;
    }
};