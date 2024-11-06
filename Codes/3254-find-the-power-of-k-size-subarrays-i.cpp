/*
 * @Author: LetMeFly
 * @Date: 2024-11-06 16:37:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-06 16:46:26
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // WA: 题目要求的是“连续”且上升，不能只上升
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans(nums.size() - k + 1);
        for (int i = 0; i + k <= nums.size(); i++) {
            int thisAns = nums[i];
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] <= nums[j - 1]) {
                    thisAns = -1;
                    goto loop;
                }
                thisAns = max(thisAns, nums[j]);
            }
            loop:
                ans[i] = thisAns;
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans(nums.size() - k + 1);
        for (int i = 0; i + k <= nums.size(); i++) {
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] != nums[j - 1] + 1) {
                    ans[i] = -1;
                    break;
                }
            }
            if (ans[i] != -1) {
                ans[i] = nums[i + k - 1];
            }
        }
        return ans;
    }
};
#endif  // FirstTry