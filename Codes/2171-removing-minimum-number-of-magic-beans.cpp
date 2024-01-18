/*
 * @Author: LetMeFly
 * @Date: 2024-01-18 19:20:51
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-01-18 19:30:51
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        long long all = accumulate(beans.begin(), beans.end(), 0);
        long long ans = all;
        for (int i = 0; i < beans.size(); i++) {
            ans = min(ans, all - ((long long)beans.size() - i) * beans[i]);
        }
        return ans;
    }
};