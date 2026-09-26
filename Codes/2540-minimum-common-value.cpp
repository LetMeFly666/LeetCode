/*
 * @Author: LetMeFly
 * @Date: 2026-05-19 17:59:01
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-19 18:00:07
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
            if (nums1[i] == nums2[j]) {
                return nums1[i];
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return -1;
    }
};
