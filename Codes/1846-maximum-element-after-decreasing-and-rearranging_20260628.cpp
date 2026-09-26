/*
 * @Author: LetMeFly
 * @Date: 2026-06-28 19:58:53
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-28 20:00:21
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans = 0;
        for (int t : arr) {
            ans += t > ans;
        }
        return ans;
    }
};
