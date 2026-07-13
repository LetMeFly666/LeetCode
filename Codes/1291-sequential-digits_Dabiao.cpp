/*
 * @Author: LetMeFly
 * @Date: 2026-07-13 21:54:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-13 21:59:27
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

vector<int> good;

int _ = [] {
    for (int i = 1; i <= 9; i++) {
        int v = i;
        for (int j = i + 1; j <= 9; j++) {
            v = v * 10 + j;
            good.push_back(v);
        }
    }
    sort(good.begin(), good.end());
    return 0;
}();

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for (int t : good) {
            if (low <=t && t <- high) {
                ans.push_back(t);
            }
        }
        return ans;
    }
};
