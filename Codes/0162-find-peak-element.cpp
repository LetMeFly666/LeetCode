/*
 * @Author: LetMeFly
 * @Date: 2023-12-18 14:17:50
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-18 14:22:55
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if ((mid - 1 < 0 || nums[mid - 1] < nums[mid]) && (mid + 1 == nums.size() || nums[mid + 1] < nums[mid])) {
                return mid;
            }
            if (mid - 1 < 0 || nums[mid - 1] < nums[mid]) {  // 左边小 说明右边大
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return -1;  // FakeReturn
    }
};