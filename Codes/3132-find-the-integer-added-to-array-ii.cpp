/*
 * @Author: LetMeFly
 * @Date: 2024-08-09 23:06:18
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-09 23:12:11
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool isOk(vector<int>& nums1, vector<int>& nums2, int x) {
        int skip = 0;
        int n1 = 0, n2 = 0;
        while (n1 < nums1.size() && n2 < nums2.size()) {
            if (nums1[n1] + x == nums2[n2]) {
                n1++, n2++;
            }
            else {
                n1++, skip++;
                if (skip > 2) {
                    return false;
                }
            }
        }
        return n2 == nums2.size();
    }
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (int i = 2; i >= 0; i--) {
            if (isOk(nums1, nums2, nums2[0] - nums1[i])) {
                return nums2[0] - nums1[i];
            }
        }
        return -1;  // Fake Return
    }
};