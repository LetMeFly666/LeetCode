/*
 * @Author: LetMeFly
 * @Date: 2023-06-04 22:13:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-06-04 22:14:57
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> se;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            se.insert(nums[l++] + nums[r--]);
        }
        return se.size();
    }
};