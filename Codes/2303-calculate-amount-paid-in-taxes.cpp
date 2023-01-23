/*
 * @Author: LetMeFly
 * @Date: 2023-01-23 09:57:26
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-01-23 10:00:13
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int ans = 0;
        int lastUpper = 0;
        for (auto& v : brackets) {
            ans +=  (min(income, v[0]) - lastUpper) * v[1];
            lastUpper = v[0];
            if (v[0] >= income)
                break;
        }
        return (double)ans / 100;
    }
};