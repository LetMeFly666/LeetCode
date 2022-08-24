/*
 * @Author: LetMeFly
 * @Date: 2022-08-24 10:56:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-24 11:00:31
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif
// Half，先不写了
class Solution {
public:
    int rob(vector<int>& nums) {
        int robThis = nums[0];
        int notRob = 0;
        for (int i = 0; i + 1 < nums.size(); i++) {
            int lastRob = robThis, lastNot = notRob;
            robThis = max(lastRob, lastNot + nums[i]);
            notRob = max(lastRob, lastNot);
        }

    }
};