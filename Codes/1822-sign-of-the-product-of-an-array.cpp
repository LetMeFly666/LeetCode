/*
 * @Author: LetMeFly
 * @Date: 2022-10-27 08:13:19
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-27 08:13:20
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for (int& num : nums) {
            if (num < 0)
                ans *= -1;
            else if (!num)
                return 0;
        }
        return ans;
    }
};