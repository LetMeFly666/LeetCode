/*
 * @Author: LetMeFly
 * @Date: 2025-02-12 22:27:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-12 22:35:27
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool ok(vector<int>& a, int o, int m) {
        int cnt = 0;
        for (int t : a) {
            cnt += (t - 1) / m;
        }
        return cnt <= o;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 0, r = *max_element(nums.begin(), nums.end());
        while (l + 1 < r) {
            int m = (l + r) >> 1;
            (ok(nums, maxOperations, m) ? r : l) = m;
        }
        return r;
    }
};