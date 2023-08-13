/*
 * @Author: LetMeFly
 * @Date: 2023-08-13 07:58:57
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-08-13 08:42:58
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    void merge(vector<int>& nums1, int l1, vector<int>& nums2, int l2) {
        int n = l1 + l2 - 1;
        l1--, l2--;
        while (l2 >= 0) {
            while (l1 >= 0 && nums1[l1] > nums2[l2]) {
                nums1[n--] = nums1[l1--];
            }
            nums1[n--] = nums2[l2--];
        }
    }
};

#ifdef _WIN32
/*
[1,2,3,0,0,0]
3
[2,5,6]
3


*/
int main() {
    string s1, s2;
    int n1, n2;
    while (cin >> s1 >> n1 >> s2 >> n2) {
        vector<int> v1 = stringToVector(s1);
        vector<int> v2 = stringToVector(s2);
        Solution sol;
        sol.merge(v1, n1, v2, n2);
        debug(v1);
    }
}
#endif