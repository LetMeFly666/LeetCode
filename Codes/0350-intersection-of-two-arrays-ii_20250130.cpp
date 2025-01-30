/*
 * @Author: LetMeFly
 * @Date: 2025-01-30 08:10:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-30 08:17:11
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 编译错误，不可用nums1.begin(), nums1.end()初始化unordered_multimap
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_multimap<int, int> ma(nums1.begin(), nums1.end());
        vector<int> ans;
        for (int t : nums2) {
            if (ma.count(t)) {
                ans.push_back(t);
                ma.erase(ma.find(t));
            }
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_multiset<int> se(nums1.begin(), nums1.end());
        vector<int> ans;
        for (int t : nums2) {
            unordered_multiset<int>::iterator it = se.find(t);
            if (it != se.end()) {
                ans.push_back(t);
                se.erase(it);
            }
        }
        return ans;
    }
};
#endif  // FirstTry