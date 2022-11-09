/*
 * @Author: LetMeFly
 * @Date: 2022-10-02 09:52:24
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-02 09:57:07
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // AC,方法一，哈希表，6.90%，15.67%
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ma;
        for (int& t : nums1) {
            ma[t]++;
        }
        vector<int> ans;
        for (int& t : nums2) {
            if (ma[t] > 0) {
                ans.push_back(t);
                ma[t]--;
            }
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry  // AC,方法二，双指针，86.34%，93.57%
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int loc1 = 0, loc2 = 0;
        vector<int> ans;
        while (loc1 < nums1.size() && loc2 < nums2.size()) {
            if (nums1[loc1] == nums2[loc2]) {
                ans.push_back(nums1[loc1]);
                loc1++, loc2++;
            }
            else if (nums1[loc1] < nums2[loc2]) {
                loc1++;
            }
            else {
                loc2++;
            }
        }
        return ans;
    }
};
#endif  // FirstTry