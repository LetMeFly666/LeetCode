/*
 * @Author: LetMeFly
 * @Date: 2022-04-21 11:18:43
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-21 11:35:18
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int loc = m + n - 1;
        int loc1 = m - 1, loc2 = n - 1;
        while (loc1 >= 0 && loc2 >= 0) {
            if (nums1[loc1] >= nums2[loc2]) {
                nums1[loc--] = nums1[loc1--];
            }
            else{
                nums1[loc--] = nums2[loc2--];
            }
        }
        if (loc1 >= 0) {
            assert(loc == loc1);
        }
        else {
            while (loc2 >= 0) {
                nums1[loc--] = nums2[loc2--];
            }
        }
    }
};

#ifdef _WIN32
int main() {
    string s1, s2;
    int m, n;
    while (cin >> s1 >> m >> s2 >> n) {
        Solution sol;
        vector<int> v1 = stringToVector(s1);
        vector<int> v2 = stringToVector(s2);
        sol.merge(v1, m, v2, n);
        debug(v1);
    }
    return 0;
}
#endif