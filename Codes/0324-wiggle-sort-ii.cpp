/*
 * @Author: LetMeFly
 * @Date: 2022-06-28 16:21:41
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-28 16:40:58
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

// // 易想效率较低的方法
// class Solution {
// public:
//     void wiggleSort(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         vector<int> ans(nums.size());
//         // int l = 0, r = nums.size() - 1;
//         // for (int i = 0; i < nums.size(); i++) {
//         //     if (i % 2) {
//         //         ans[i] = nums[r--];
//         //     }
//         //     else {
//         //         ans[i] = nums[l++];
//         //     }
//         // }
//         int l = 0, r = nums.size() / 2 + nums.size() % 2;
//         for (int i = 0; i < nums.size(); i++) {
//             if (i % 2) {
//                 ans[i] = nums[r++];
//             }
//             else {
//                 ans[i] = nums[l++];
//             }
//         }
//         nums = ans;
//     }
// };

// Copy
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        int x = (n + 1) / 2;
        for (int i = 0, j = x - 1, k = n - 1; i < n; i += 2, j--, k--) {
            nums[i] = arr[j];
            if (i + 1 < n) {
                nums[i + 1] = arr[k];
            }
        }
    }
};