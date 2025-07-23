/*
 * @Author: LetMeFly
 * @Date: 2025-07-23 10:31:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-23 13:26:19
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> had;
        int ans = 0, cnt = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            while (had.count(nums[r])) {
                had.erase(nums[l]);
                cnt -= nums[l++];
            }
            had.insert(nums[r]);
            cnt += nums[r];
            // printf("l = %d, r = %d, cnt = %d\n", l, r, cnt);
            ans = max(ans, cnt);
        }
        return ans;
    }
};

/*
[187,470,25,436,538,809,441,167,477,110,275,133,666,345,411,459,490,266,987,965,429,166,809,340,467,318,125,165,809,610,31,585,970,306,42,189,169,743,78,810,70,382,367,490,787,670,476,278,775,673,299,19,893,817,971,458,409,886,434]
9252
16911
*/