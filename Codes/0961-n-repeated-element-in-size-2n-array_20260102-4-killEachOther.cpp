/*
 * @Author: LetMeFly
 * @Date: 2026-01-02 13:29:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-02 14:22:57
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        if (nums[0] == nums[1]) {
            return nums[0];
        }
        int now = -1, hp = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[0]) {
                return nums[0];
            }
            if (hp == 0) {
                hp = 1;
                now = nums[i];
            } else if (now == nums[i]) {
                hp++;  // 其实也可以直接return了
            } else {
                hp--;
            }
        }
        return now;
    }
};