/*
 * @Author: LetMeFly
 * @Date: 2023-02-27 09:22:36
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-02-27 09:34:59
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int ansOdd = 0, ansEven = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2) {
                ansOdd += max(0, max(nums[i] - nums[i - 1] + 1, i + 1 < nums.size() ? nums[i] - nums[i + 1] + 1 : 0));
            }
            else {
                ansEven += max(0, max(i - 1 >= 0 ? nums[i] - nums[i - 1] + 1 : 0, i + 1 < nums.size() ? nums[i] - nums[i + 1] + 1 : 0));
            }
        }
        return min(ansEven, ansOdd);
    }
};