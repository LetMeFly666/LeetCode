/*
 * @Author: LetMeFly
 * @Date: 2026-05-07 21:58:53
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-07 22:10:01
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
        
        int minimum = nums.back();
        for (int i = n - 2; i >= 0; i--) {
            if (maximum[i] > minimum) {
                maximum[i] = maximum[i + 1];
            }
            minimum = min(minimum, nums[i]);
        }
        return maximum;
    }
};
