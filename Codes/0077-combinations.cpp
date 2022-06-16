/*
 * @Author: LetMeFly
 * @Date: 2022-06-16 11:07:32
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-16 11:14:50
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> a(k);
        for (int i = 0; i < (1 << n); i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    cnt++;
                }
            }
            if (cnt != k)
                continue;
            int loc = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    a[loc++] = j + 1;
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};