/*
 * @Author: LetMeFly
 * @Date: 2022-10-08 16:32:11
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-08 17:34:03
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 原地
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int up(1), down(1);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1])
                up = down + 1;
            else if (nums[i] < nums[i - 1])
                down = up + 1;
        }
        return max(up, down);
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> up(n), down(n);
        // ...
    }
};
#endif  // FirstTry