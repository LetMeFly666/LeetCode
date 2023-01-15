/*
 * @Author: LetMeFly
 * @Date: 2023-01-15 08:34:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-01-15 08:37:04
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        vector<int> newNum;
        int loc = 0;
        bool isMin = true;
        while (loc < nums.size()) {
            if (isMin) {
                newNum.push_back(min(nums[loc++], nums[loc++]));
                isMin = false;
            }
            else {
                newNum.push_back(max(nums[loc++], nums[loc++]));
                isMin = true;
            }
        }
        return minMaxGame(newNum);
    }
};