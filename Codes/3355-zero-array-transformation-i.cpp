/*
 * @Author: LetMeFly
 * @Date: 2025-05-21 23:06:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-21 23:14:28
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> diff(nums.size() + 1);
        for (vector<int>& q : queries) {
            diff[q[0]]++;
            diff[q[1] + 1]--;
        }
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt += diff[i];
            if (nums[i] > cnt) {
                return false;
            }
        }
        return true;
    }
};