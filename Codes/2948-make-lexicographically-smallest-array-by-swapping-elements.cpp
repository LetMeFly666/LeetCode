/*
 * @Author: LetMeFly
 * @Date: 2026-08-29 11:00:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-29 11:27:22
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    void full(vector<int>& ans, vector<int>& nums, vector<int>& idxs, int l, int r) {
        vector<int> pos(r - l);
        for (int i = l, th = 0; i < r; i++, th++) {
            pos[th] = idxs[i];
        }
        ranges::sort(pos);
        for (int i = l, th = 0; i < r; i++, th++) {
            ans[pos[th]] = nums[idxs[i]];
        }
    }
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> idxs(nums.size());
        ranges::iota(idxs, 0);
        sort(idxs.begin(), idxs.end(), [&nums](const int& a, const int& b) { return nums[a] < nums[b]; });

        vector<int> ans(nums.size());
        for (int i = 1, n = nums.size(), last = 0; i <= n; i++) {
            if (i == n || nums[idxs[i]] - nums[idxs[i - 1]] > limit) {
                full(ans, nums, idxs, last, i);
                last = i;
            }
        }
        return ans;
    }
};
