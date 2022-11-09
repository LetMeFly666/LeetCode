/*
 * @Author: LetMeFly
 * @Date: 2022-10-08 12:29:52
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-08 12:43:32
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef pair<int, int> pii;
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<pii> tempNums2(n);
        for (int i = 0; i < n; i++) {
            tempNums2[i] = {nums2[i], i};
        }
        sort(tempNums2.begin(), tempNums2.end());
        sort(nums1.begin(), nums1.end());
        vector<int> ans(n);
        int loc1 = 0;
        vector<int> unused;
        for (int i = 0; i < n; i++) {
            while (loc1 < n && nums1[loc1] <= tempNums2[i].first) {
                unused.push_back(nums1[loc1]);
                loc1++;
            }
            if (loc1 == n) {
                int locUnused = 0;
                while (i < n) {
                    ans[tempNums2[i++].second] = unused[locUnused++];
                }
                break;
            }
            ans[tempNums2[i].second] = nums1[loc1++];
        }
        return ans;
    }
};