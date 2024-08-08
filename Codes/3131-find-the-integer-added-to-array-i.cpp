/*
 * @Author: LetMeFly
 * @Date: 2024-08-08 22:14:37
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-08 22:14:37
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        return *min_element(nums2.begin(), nums2.end()) - *min_element(nums1.begin(), nums1.end());
    }
};