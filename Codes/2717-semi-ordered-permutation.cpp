/*
 * @Author: LetMeFly
 * @Date: 2024-12-11 23:16:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-11 23:18:40
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int a, b;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                a = i;
            } else if (nums[i] == nums.size()) {
                b = i;
            }
        }
        return a + (nums.size() - b - 1) - (a > b);
    }
};