/*
 * @Author: LetMeFly
 * @Date: 2022-08-04 10:44:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-04 10:45:43
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int s = 0;
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
        }
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> ans;
        int nowSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(nums[i]);
            nowSum += nums[i];
            if (nowSum > s - nowSum)
                break;
        }
        return ans;
    }
};