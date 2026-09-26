/*
 * @Author: LetMeFly
 * @Date: 2026-08-04 11:01:37
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-04 11:08:22
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int m = nums[0], M = nums.back(), n = nums.size();
        vector<int> ans;
        ans.reserve(M - m + 1 - n);
        for (int i = m, idx = 0; i <= M; i++) {
            if (idx == n || nums[idx] != i) {
                ans.push_back(i);
            } else {
                idx++;
            }
        }
        return ans;
    }
};
