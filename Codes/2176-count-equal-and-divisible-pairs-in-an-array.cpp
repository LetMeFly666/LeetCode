/*
 * @Author: LetMeFly
 * @Date: 2025-04-17 20:13:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-17 20:28:40
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j] && i * j % k == 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};