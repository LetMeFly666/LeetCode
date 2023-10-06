/*
 * @Author: LetMeFly
 * @Date: 2023-10-06 12:44:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-06 13:28:44
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {  // [l, r]不空
        int mid = (l + r) / 2;
        if (nums[mid] > target) r = mid - 1;  // 新区间[l, mid - 1]
        if (nums[mid] < target) l = mid + 1;  // 新区间[mid + 1, r]
        if (nums[mid] == target) return mid;
    }
        return -1;
    }
};