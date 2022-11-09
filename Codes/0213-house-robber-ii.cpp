/*
 * @Author: LetMeFly
 * @Date: 2022-08-24 10:56:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-25 09:14:23
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif
#ifdef FirstTry
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
#else  // FirstTry
// Copy
class Solution {
public:
    int robRange(vector<int>& nums, int start, int end) {
        int first = nums[start], second = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }

    int rob(vector<int>& nums) {
        int length = nums.size();
        if (length == 1) {
            return nums[0];
        } else if (length == 2) {
            return max(nums[0], nums[1]);
        }
        return max(robRange(nums, 0, length - 2), robRange(nums, 1, length - 1));
    }
};
#endif  // FirstTry