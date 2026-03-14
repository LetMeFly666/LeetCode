/*
 * @Author: LetMeFly
 * @Date: 2026-03-14 22:56:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-14 23:21:37
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string getHappyString(int n, int k) {
        int remain = 1 << (n - 1);
        if (k > 3 * remain) {
            return "";
        }
        
        k--;
        char toChoose[3] = {'a', 'b', 'c'};
        string ans;
        ans.push_back(toChoose[k / remain]);
        for (int i = 1; i < n; i++) {
            k %= remain;
            remain >>= 1;
            int th = k / remain;
            if (toChoose[th] >= ans.back()) {
                th++;
            }
            ans.push_back(toChoose[th]);
        }
        return ans;
    }
};