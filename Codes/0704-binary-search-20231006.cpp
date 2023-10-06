/*
 * @Author: LetMeFly
 * @Date: 2023-10-06 12:44:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-06 13:03:43
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] > target) {
                r = mid;
            }
            else if (nums[mid] < target) {
                l = mid + 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
};