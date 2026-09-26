/*
 * @Author: LetMeFly
 * @Date: 2026-08-20 10:12:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-20 10:14:33
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> v1(1, nums[0]), v2(1, nums[1]);
        for (int i = 2, n = nums.size(); i < n; i++) {
            (v1.back() > v2.back() ? v1 : v2).push_back(nums[i]);
        }
        v1.insert(v1.end(), v2.begin(), v2.end());
        return v1;
    }
};
