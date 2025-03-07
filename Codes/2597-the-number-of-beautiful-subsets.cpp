/*
 * @Author: LetMeFly
 * @Date: 2025-03-07 23:32:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-07 23:39:31
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int l = 0, r = 0; l < nums.size(); l++) {
            while (r + 1 < nums.size() && nums[r + 1] - nums[l] <= k) {
                r++;
            }
            printf("l = %d, r = %d, 1 << (r - l) = %d\n", l, r, 1 << (r - l));  //*****
            ans += 1 << (r - l);
        }
        return ans;
    }
};

/*
[2,4,6]
2

4

l = 0, r = 1, 1 << (r - l) = 2  2、2 4
l = 1, r = 2, 1 << (r - l) = 2  4、4 6
l = 2, r = 2, 1 << (r - l) = 1  6

*/