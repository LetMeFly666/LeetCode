/*
 * @Author: LetMeFly
 * @Date: 2025-06-25 22:24:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-25 22:28:06
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = max(0, i - k + 1); j <= min(int(nums.size()) - 1, i + k - 1); j++) {
                if (nums[j] == key) {
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
    }
};