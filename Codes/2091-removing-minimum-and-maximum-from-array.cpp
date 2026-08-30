/*
 * @Author: LetMeFly
 * @Date: 2026-08-30 09:41:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-30 09:44:30
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int m = nums[0], M = m;
        int im = 0, iM = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] < m) {
                m = nums[i];
                im = i;
            }
            if (nums[i] > M) {
                M = nums[i];
                iM = i;
            }
        }

        if (im > iM) {
            swap(im, iM);
        }
        return min(im + 1 + n - iM, min(iM + 1, n - im));
    }
};
