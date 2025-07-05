/*
 * @Author: LetMeFly
 * @Date: 2025-07-03 21:31:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-06 00:06:51
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> idx(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            idx[i] = i;
        }
        sort(idx.begin(), idx.end(), [&nums](int i, int j) {
            return nums[i] > nums[j];
        });
        idx.resize(k);
        sort(idx.begin(), idx.end());
        for (int &t : idx) {
            t = nums[t];
        }
        return idx;
    }
};