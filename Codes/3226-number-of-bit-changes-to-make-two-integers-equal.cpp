/*
 * @Author: LetMeFly
 * @Date: 2024-11-02 10:43:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-02 10:45:43
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minChanges(int n, int k) {
        int ans = 0;
        for (int i = 0; i < 20; i++) {
            int thisN = n & (1 << i), thisK = k & (1 << i);
            if (thisN && !thisK) {
                ans++;
            } else if (thisN != thisK) {
                return -1;
            }
        }
        return ans;
    }
};