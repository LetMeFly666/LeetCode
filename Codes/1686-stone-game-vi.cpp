/*
 * @Author: LetMeFly
 * @Date: 2024-02-02 17:06:25
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-02-02 17:27:12
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {  // AC,100.00%,80.77%
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < a.size(); i++) {
            a[i] += b[i];
        }
        sort(a.begin(), a.end(), greater<int>());
        int a_b = -accumulate(b.begin(), b.end(), 0);
        for (int i = 0; i < a.size(); i += 2) {
            a_b += a[i];
        }
        return a_b > 0 ? 1 : a_b ? -1 : 0;
    }
};