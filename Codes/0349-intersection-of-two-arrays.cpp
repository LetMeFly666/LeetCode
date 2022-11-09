/*
 * @Author: LetMeFly
 * @Date: 2022-10-02 09:04:56
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-02 09:07:45
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> se;
        for (int& t : nums1) {
            se.insert(t);
        }
        sort(nums2.begin(), nums2.end());
        auto end = unique(nums2.begin(), nums2.end());
        vector<int> ans;
        for (auto it = nums2.begin(); it < end; it++) {
            if (se.count(*it))
                ans.push_back(*it);
        }
        return ans;
    }
};