/*
 * @Author: LetMeFly
 * @Date: 2026-09-04 18:29:59
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-04 18:37:18
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
            mini[i] = min(mini[i], mini[i + 1]);
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
