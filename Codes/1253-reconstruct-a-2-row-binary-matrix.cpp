/*
 * @Author: LetMeFly
 * @Date: 2023-06-29 08:09:07
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-06-29 08:20:02
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> ans(2, vector<int>(colsum.size(), 0));
        int cntUpper = 0, cntLower = 0;
        for (int i = 0; i < colsum.size(); i++) {
            if (colsum[i] == 2) {
                ans[0][i] = ans[1][i] = 1;
                cntUpper++, cntLower++;
            }
        }
        for (int i = 0; i < colsum.size(); i++) {
            if (colsum[i] == 1) {
                if (cntUpper < upper) {
                    ans[0][i] = 1;
                    cntUpper++;
                }
                else {
                    ans[1][i] = 1;
                    cntLower++;
                }
            }
        }
        if (cntUpper == upper && cntLower == lower) {
            return ans;
        }
        else {
            return {};
        }
    }
};