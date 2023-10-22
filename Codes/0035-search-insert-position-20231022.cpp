/*
 * @Author: LetMeFly
 * @Date: 2023-10-22 16:42:06
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-22 16:45:46
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] < target) {
                l = mid + 1;
            }
            else if (nums[mid] > target) {
                r = mid;
            }
            else {
                return mid;
            }
        }
        return l;
    }
};