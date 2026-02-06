/*
 * @Author: LetMeFly
 * @Date: 2026-02-06 19:05:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-06 19:12:17
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
private:
    int getLastRIndex(vector<int>& nums, int k) {
        if (nums[0] * k > INT_MAX) {
            return nums.size() - 1;
        }
        vector<int>::iterator it = upper_bound(nums.begin(), nums.end(), nums[0] * k);
        return min((long)nums.size() - 1, it - nums.begin());
    }
public:
    int minRemoval(vector<int>& nums, ll k) {
        sort(nums.begin(), nums.end());
        int keep = 1;

        for (int l = 0, r = getLastRIndex(nums, k); ; l++) {
            while (r < nums.size() && nums[r] <= nums[l] * k) {
                r++;
            }
            keep = max(keep, r - l);
            if (r == nums.size()) {
                break;
            }
        }
        return nums.size() - keep;
    }
};