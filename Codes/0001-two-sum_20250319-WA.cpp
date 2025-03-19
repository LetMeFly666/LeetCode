/*
 * @Author: LetMeFly
 * @Date: 2025-03-19 20:39:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-19 20:41:02
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> se;
        for (int t : nums) {
            if (se.count(target - t)) {
                return {t, target - t};
            }
            se.insert(t);
        }
        return {};  // Fake return
    }
};