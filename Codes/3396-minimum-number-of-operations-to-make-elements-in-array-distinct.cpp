/*
 * @Author: LetMeFly
 * @Date: 2025-04-08 21:52:04
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-08 21:54:03
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> se;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (se.count(nums[i])) {
                return min((int)nums.size(), i / 3 + 1);
            }
            se.insert(nums[i]);
        }
        return 0;
    }
};