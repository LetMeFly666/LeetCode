/*
 * @Author: LetMeFly
 * @Date: 2026-10-22 08:03:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-23 12:58:43
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        int start = ranges::find(nums, 0) - nums.begin();
        for (int i = 1; i < n; i++) {
            int diff = abs(nums[(start + i) % n] - nums[(start + i - 1) % n]);
            if (diff != 1 && diff != n - 1) {
                return -1;
            }
        }
        
        if (nums[(start + 1) % n] == 1) {
            return min(start, n - start + 2);
        } else {
            return min(start  +2, n - start);
        }
    }
};
