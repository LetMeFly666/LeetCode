/*
 * @Author: LetMeFly
 * @Date: 2022-02-26 20:41:55
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-02-26 20:46:27
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTryOn_n
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                ans = max(ans, nums[j] - nums[i]);
        return ans ? ans : -1;
    }
};
#else
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = 0, m = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < m) 
                m = nums[i];
            else 
                ans = max(ans, nums[i] - m);
        }
        return ans ? ans : -1;
    }
};
#endif