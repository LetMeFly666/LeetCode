/*
 * @Author: LetMeFly
 * @Date: 2024-05-23 16:44:56
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-23 16:56:13
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> ma;
        int maxTimes = 1, ans = 1;
        ma[nums[0]]++;
        for (int l = 0, r = 0; r < nums.size(); l++) {
            while (r + 1 < nums.size() && maxTimes + k >= r -  l + 1) {
                // nums[r + 1]加入到窗口中
                ma[nums[r + 1]]++;
                // half... 现在是一个混沌的世界。。。
            }
        }
    }
};