/*
 * @Author: LetMeFly
 * @Date: 2024-07-16 23:24:41
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-16 23:26:12
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        vector<int> ans(2);
        for (int t : nums1) {
            ans[0] += s2.count(t);
        }
        for (int t : nums2) {
            ans[1] += s1.count(t);
        }
        return ans;
    }
};