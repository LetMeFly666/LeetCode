/*
 * @Author: LetMeFly
 * @Date: 2025-06-25 22:30:38
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-25 22:32:27
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (nums[i] == key) {
                for (j = max(j, i - k); j <= i + k; j++) {
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};