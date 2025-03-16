/*
 * @Author: LetMeFly
 * @Date: 2025-03-16 23:04:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-16 23:33:11
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        for (; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                break;
            }
        }
        cout << i << endl;
        if (!i) {
            reverse(nums.begin(), nums.end());
            return;
        }
        i--;
        int j = nums.size();
        while (nums[--j] <= nums[i]) {
            cout << j << (nums[j] <= nums[i]) << endl;
        };
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};