/*
 * @Author: LetMeFly
 * @Date: 2026-06-08 20:32:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-08 20:34:51
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n, pivot);
        int l = 0, r = n - 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                ans[l++] = nums[i];
            } else if (nums[i] > pivot) {
                ans[r--] = nums[i];
            }
        }
        reverse(ans.begin() + r + 1, ans.end());
        return ans;
    }
};
