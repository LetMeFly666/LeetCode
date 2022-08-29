/*
 * @Author: LetMeFly
 * @Date: 2022-08-29 08:33:22
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-29 08:53:25
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(nums.size());
        int p1 = 0, p2 = nums.size() / 2;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2) {
                ans[i] = nums[p2++];
            }
            else {
                ans[i] = nums[p1++];
            }
        }
        return ans;
    }
};

/*
尝试使用双指针原地交换但失败了的尝试

1,2,3,4,5,6,7,8 
1,5,3,4,2,6,7,8
1,5,2,4,3,6,7,8
1,5,2,6,3,4,7,8


1,5,2,6,3,7,4,8
*/