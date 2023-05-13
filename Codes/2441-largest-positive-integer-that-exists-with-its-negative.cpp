/*
 * @Author: LetMeFly
 * @Date: 2023-05-13 13:17:38
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-05-13 13:18:54
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> se(nums.begin(), nums.end());
        int ans = -1;
        for (int num : nums) {
            if (num > 0 && se.count(-num)) {
                ans = max(ans, num);
            }
        }
        return ans;
    }
};