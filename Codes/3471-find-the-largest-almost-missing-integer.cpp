/*
 * @Author: LetMeFly
 * @Date: 2026-08-18 16:23:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-18 16:43:59
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == k || k == 1) {
            return *max_element(nums.begin(), nums.end());
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
