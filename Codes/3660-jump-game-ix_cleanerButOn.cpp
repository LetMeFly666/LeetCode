/*
 * @Author: LetMeFly
 * @Date: 2026-05-07 22:10:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-07 22:12:17
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> maximum(n);
        maximum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            maximum[i] = max(maximum[i - 1], nums[i]);
        }
        
        vector<int> ans(n);
        int minimum = nums.back();
        ans.back() = maximum.back();
        for (int i = n - 2; i >= 0; i--) {
            if (maximum[i] > minimum) {
                ans[i] = maximum[i + 1];
            } else {
                ans[i] = maximum[i];
            }
            minimum = min(minimum, nums[i]);
        }
        return maximum;
    }
};
