/*
 * @Author: LetMeFly
 * @Date: 2026-07-24 09:50:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-24 09:53:25
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> can2;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                can2.insert(nums[i] ^ nums[j]);
            }
        }

        unordered_set<int> can3;
        for (int a : can2) {
            for (int b : nums) {
                can3.insert(a ^ b);
            }
        }
        return can3.size();
    }
};
