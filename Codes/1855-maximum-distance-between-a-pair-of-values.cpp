/*
 * @Author: LetMeFly
 * @Date: 2026-04-19 13:34:23
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-04-19 13:38:49
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        for (int i = 0, j = 0, n = nums1.size(), m = nums2.size(); j < m; j++) {
            while (i < n && nums1[i] > nums2[j]) {
                i++;
            }
            if (i == n) {
                break;
            }
            ans = max(ans, j - i);
        }
        return ans;
    }
};