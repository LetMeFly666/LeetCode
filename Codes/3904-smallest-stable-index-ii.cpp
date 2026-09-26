/*
 * @Author: LetMeFly
 * @Date: 2026-09-05 08:24:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-05 08:26:32
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mini(n);
        mini.back() = nums.back();
        for (int i = n - 2; i >= 0; i--) {
            mini[i] = min(mini[i + 1], nums[i]);
        }
        for (int i = 0, M = 0; i < n; i++) {
            M = max(M, nums[i]);
            if (M - mini[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};
