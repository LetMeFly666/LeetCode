/*
 * @Author: LetMeFly
 * @Date: 2026-07-12 09:27:04
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-12 09:50:55
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> b = arr;
        sort(b.begin(), b.end());
        unordered_map<int, int> ma;
        int last = b[0] + 1, num = 0;
        for (int t : b) {
            if (t != last) {
                ma[t] = ++num;
                last = t;
            }
        }
        // trick直接给原始数组覆盖了
        for (int& t : arr) {
            t = ma[t];
        }
        return arr;
    }
};
