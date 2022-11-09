/*
 * @Author: LetMeFly
 * @Date: 2022-10-27 08:57:14
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-27 10:17:18
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error  // 不是中位数。。。
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int midLoc = k / 2;
        vector<double> ans;
        for (int i = k; i <= nums.size(); i++, midLoc++) {
            if (k % 2) {
                ans.push_back(nums[midLoc]);
            }
            else {
                ans.push_back(1. * (nums[midLoc] + nums[midLoc + 1]) / 2);
            }
        }
        return ans;
    }
};
#else  // FirstTry
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        // Copy了
    }
};
#endif  // FirstTry