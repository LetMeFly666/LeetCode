/*
 * @Author: LetMeFly
 * @Date: 2022-04-17 09:52:58
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-17 09:54:44
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int loc = 0;
        for (int& t : nums) {
            if (t)
                nums[loc++] = t;
        }
        while (loc < nums.size())
            nums[loc++] = 0;
    }
};