/*
 * @Author: LetMeFly
 * @Date: 2024-11-10 16:42:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-10 17:28:09
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (mid == nums.size() - 1 || nums[mid] != nums[mid ^ 1]) {  // 问题出在mid及其之前
                if ((mid == 0 || nums[mid] != nums[mid - 1]) && (mid == nums.size() - 1 || nums[mid] != nums[mid + 1])) {
                    return nums[mid];
                }
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        // printf("l = %d\n", l);  //************
        return nums[l];
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == nums[mid ^ 1]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
};
#endif  // FirstTry