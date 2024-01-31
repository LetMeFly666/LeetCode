/*
 * @Author: LetMeFly
 * @Date: 2024-01-31 11:16:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-01-31 11:18:56
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_set<int> se;
        vector<int> suffix(nums.size() + 1);
        for (int i = nums.size() - 1; i >= 0; i--) {
            se.insert(nums[i]);
            suffix[i] = se.size();
        }
        se.clear();
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            se.insert(nums[i]);
            ans[i] = se.size() - suffix[i + 1];
        }
        return ans;
    }
};