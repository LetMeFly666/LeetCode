/*
 * @Author: LetMeFly
 * @Date: 2025-03-11 13:47:26
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-11 13:52:04
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        vector<int> M(nums.size()), m(nums.size());
        int now = 0;
        for (int i = 0; i < nums.size(); i++) {
            M[i] = now = max(now, nums[i]);
        }
        now = 1000000;
        for (int i = nums.size() - 1; i >= 0; i--) {
            m[i] = now = min(now, nums[i]);
        }
        int ans = 0;
        for (int i = 1; i < nums.size() - 1; i++) {
            // printf("M[%d] = %d, nums[%d] = %d, m[%d] = %d\n", i - 1, M[i - 1], i, nums[i], i + 1, m[i + 1]);  // ********
            if (M[i - 1] < nums[i] && nums[i] < m[i + 1]) {
                ans += 2;
            } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                ans++;
            }
        }
        return ans;
    }
};