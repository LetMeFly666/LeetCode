/*
 * @Author: LetMeFly
 * @Date: 2026-09-17 13:14:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-17 13:26:14
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> minL(n + 1, 1e7);
        int ans = 1e7;
        for (int l = 0, r = 0, cnt = 0; r < n; r++) {
            cnt += arr[r];
            while (cnt > target) {
                cnt -= arr[l++];
            }
            minL[r + 1] = minL[r];
            if (cnt == target) {
                minL[r + 1] = min(minL[r + 1], r - l + 1);
                ans = min(ans, minL[l] + r - l + 1);
            }
        }
        return ans > n ? -1 : ans;
    }
};
