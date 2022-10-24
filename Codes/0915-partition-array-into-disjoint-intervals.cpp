/*
 * @Author: LetMeFly
 * @Date: 2022-10-24 18:31:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-24 19:24:02
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int M = nums[0], lM = M, ans = 1;
        for (int i = 1; i < n; i++) {
            M = max(M, nums[i]);
            if (nums[i] < lM) {
                lM = M, ans = i + 1;
            }
        }
        return ans;
    }
};