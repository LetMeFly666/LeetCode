/*
 * @Author: LetMeFly
 * @Date: 2022-02-10 10:26:43
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-02-10 10:27:51
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (__gcd(i, j) == 1) {
                    ans.push_back(to_string(j) + "/" + to_string(i));
                }
            }
        }
        return ans;
    }
};