/*
 * @Author: LetMeFly
 * @Date: 2024-06-07 20:19:32
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-07 20:21:19
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int ans = 1;
        int val = nums[0] + nums[1];
        for (int i = 2; i + 1< nums.size(); i += 2) {
            if (nums[i] + nums[i + 1] != val) {
                break;
            }
            ans++;
        }
        return ans;
    }
};