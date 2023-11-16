/*
 * @Author: LetMeFly
 * @Date: 2023-11-16 19:59:29
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-16 20:04:32
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0;
        int nowCnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nowCnt) {
                if (nums[i] <= threshold && nums[i] % 2 != nums[i - 1] % 2) {
                    nowCnt++;
                }
                else {
                    ans = max(ans, nowCnt);
                    nowCnt = 0;
                }
            }
            if (!nowCnt && nums[i] <= threshold && nums[i] % 2 == 0) {
                nowCnt = 1;
            }
        }
        return max(ans, nowCnt);
    }
};