/*
 * @Author: LetMeFly
 * @Date: 2022-04-06 22:48:15
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-06 22:58:13
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (int& t : nums2) {
            nums1.push_back(t);
        }
        sort(nums1.begin(), nums1.end());
        // if (nums1.size() % 2) {
        //     return nums1[nums1.size() / 2];
        // }
        // else {
        //     return 1. * (nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1]) / 2;
        // }
        return nums1.size() % 2 ? nums1[nums1.size() / 2] : 1. * (nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1]) / 2;
    }
};

#ifdef _WIN32
int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        Solution sol;
        vector<int> v1 = stringToVector(s1);
        vector<int> v2 = stringToVector(s2);
        cout << sol.findMedianSortedArrays(v1, v2) << endl;
    }
    return 0;
}
#endif