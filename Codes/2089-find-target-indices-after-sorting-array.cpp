/*
 * @Author: LetMeFly
 * @Date: 2026-10-19 21:41:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-19 21:43:44
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less = 0, equal = 0;
        for (int t : nums) {
            if (t < target) {
                less++;
            } else if (t == target) {
                equal++;
            }
        }
        vector<int> ans(equal);
        ranges::iota(ans, less);
        return ans;
    }
};
