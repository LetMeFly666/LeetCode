/*
 * @Author: LetMeFly
 * @Date: 2022-02-14 12:05:25
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-02-14 12:06:27
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            mid -= mid & 1;
            if (nums[mid] == nums[mid + 1]) {
                l = mid + 2;
            }
            else {
                r = mid;
            }
        }
        return nums[l];
    }
};