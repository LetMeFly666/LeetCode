/*
 * @Author: LetMeFly
 * @Date: 2026-09-23 18:34:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-23 18:40:09
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int, int> prefix;
        for (int i = 0, cnt = 0, n = nums.size(); i < n && cnt < x; i++) {
            cnt += nums[i];
            prefix[cnt] = i;
        }
        prefix[0] = -1;
        int ans = prefix.count(x) ? prefix[x] + 1 : nums.size() + 1;
        for (int n = nums.size(), i = n - 1, cnt = 0; i >= 0 && cnt < x; i--) {
            cnt += nums[i];
            if (prefix.count(x - cnt)) {
                ans = min(ans, prefix[x - cnt] + n - i + 1);
            }
        }
        return ans > nums.size() ? -1 : ans;
    }
};
