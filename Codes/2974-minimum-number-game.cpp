/*
 * @Author: LetMeFly
 * @Date: 2024-07-12 00:22:23
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-12 00:23:39
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i + 1 < nums.size(); i += 2) {
            swap(nums[i], nums[i + 1]);
        }
        return nums;
    }
};