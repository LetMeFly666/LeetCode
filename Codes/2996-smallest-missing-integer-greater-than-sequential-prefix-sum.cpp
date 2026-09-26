/*
 * @Author: LetMeFly
 * @Date: 2026-08-11 09:05:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-11 09:20:09
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int cnt = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1] + 1) {
                break;
            }
            cnt += nums[i];
        }
        while (ranges::find(nums, cnt) != nums.end()) {  // 注意≠是存在
            cnt++;
        }
        return cnt;
    }
};
