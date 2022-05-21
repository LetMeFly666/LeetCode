/*
 * @Author: LetMeFly
 * @Date: 2022-04-19 10:33:43
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-19 10:43:19
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int& num : nums) {
            if (num <= 0) {
                num = n + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (abs(nums[i]) <= n) {  // 这里是 ≤
                nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);  // 这里外面还有一个abs
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
};