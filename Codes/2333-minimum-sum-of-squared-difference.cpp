/*
 * @Author: LetMeFly
 * @Date: 2026-10-12 18:27:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-12 19:25:34
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> diffs(nums1.size() + 1);  // 末尾多一个哨兵
        for (int i = 0; i < n; i++) {
            diffs[i] = abs(nums1[i] - nums2[i]);
        }
        ranges::sort(diffs, greater<int>());

        int k = k1 + k2;
        for (int i = 0; i < n; i++) {
            ll per_diff = diffs[i] - diffs[i + 1];
            ll all_need = per_diff * (i + 1);
            if (k >= all_need) {
                k -= all_need;
                continue;
            }
            /*
                不够全部减小到目标值了，看看能减小到多少。
                假设k = 3, i = 1, all_need = 5
                k // 2 = 1，2个数每个减少1
                k % 2 = 1，其中1个数再减少一
            */
            ll all_sub = k / (i + 1);
            ll more_sub_1 = k % (i + 1);
            ll not_more_sub_1 = i + 1 - more_sub_1;
            diffs[i] -= all_sub;
            ll ans = not_more_sub_1 * diffs[i] * diffs[i];
            ans += more_sub_1 * (diffs[i] - 1) * (diffs[i] - 1);
            for (i++; i < n; i++) {
                ans += (ll) diffs[i] * diffs[i];
            }
            return ans;
        }
        return 0;
    }
};
