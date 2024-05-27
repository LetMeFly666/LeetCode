/*
 * @Author: LetMeFly
 * @Date: 2024-05-27 21:34:19
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-27 21:37:36
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int target = mean * (rolls.size() + n);
        for (int t : rolls) {
            target -= t;
        }
        if (target < n || target > n * 6) {
            return {};
        }
        vector<int> ans(n, target / n);
        for (int i = target % n; i > 0; i--) {
            ans[i]++;
        }
        return ans;
    }
};