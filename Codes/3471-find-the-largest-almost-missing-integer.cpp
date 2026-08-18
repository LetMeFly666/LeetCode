/*
 * @Author: LetMeFly
 * @Date: 2026-08-18 16:23:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-18 16:46:31
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == k) {
            return *max_element(nums.begin(), nums.end());
        }

        if (k == 1) {
            ranges::sort(nums);
            for (int i = n - 1; i >= 0; i--) {
                if (i - 1 && nums[i - 1] == nums[i]) {
                    continue;
                }
                if (i + 1 < n && nums[i + 1] == nums[i]) {
                    continue;
                }
                return nums[i];
            }
            return -1;
        }
        
        int first = nums[0], last = nums.back();
        if (first == last) {
            return -1;
        }
        bool another1 = false, another2 = false;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] == first) {
                another1 = true;
            }
            if (nums[i] == last) {
                another2 = true;
            }
        }
        if (another1 && another2) {
            return -1;
        }
        if (!another1 && !another2) {
            return max(first, last);
        }
        return another1 ? last : first;
    }
};
