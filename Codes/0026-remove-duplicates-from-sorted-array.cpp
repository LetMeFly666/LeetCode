/*
 * @Author: LetMeFly
 * @Date: 2022-05-13 14:52:42
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-13 14:53:59
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = nums.size();
        int moveTo = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                ans--;
            }
            else {
                nums[moveTo++] = nums[i];
            }
        }
        return ans;
    }
};