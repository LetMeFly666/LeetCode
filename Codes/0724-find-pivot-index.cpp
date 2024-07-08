/*
 * @Author: LetMeFly
 * @Date: 2024-07-08 13:15:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-08 13:15:16
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int nowSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sum - nums[i] == nowSum * 2) {
                return i;
            }
            nowSum += nums[i];
        }
        return -1;
    }
};