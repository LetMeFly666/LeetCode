/*
 * @Author: LetMeFly
 * @Date: 2022-09-08 10:18:21
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-08 10:21:02
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n);
        int l = 1, r = n;
        for (int i = 0; i < k; i++) {
            if (i % 2) {
                ans[i] = r--;
            }
            else {
                ans[i] = l++;
            }
        }
        int toLoc = k;
        if (k % 2) {
            while (l <= r) {
                ans[toLoc++] = l++;
            }
        }
        else {
            while (l <= r) {
                ans[toLoc++] = r--;
            }
        }
        return ans;
    }
};