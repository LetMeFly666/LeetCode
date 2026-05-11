/*
 * @Author: LetMeFly
 * @Date: 2026-05-11 21:16:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-11 21:16:38
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (nums[i]) {
                ans.push_back(nums[i] % 10);
                nums[i] /= 10;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
