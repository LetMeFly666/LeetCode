/*
 * @Author: LetMeFly
 * @Date: 2025-02-09 08:44:41
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-09 08:48:30
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 1;
        for (int fast = 2; fast < nums.size(); fast++) {
            if (nums[fast] != nums[slow - 1]) {
                nums[++slow] = nums[fast];
            }
        }
        return min((int)nums.size(), slow + 1);
    }
};