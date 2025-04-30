/*
 * @Author: LetMeFly
 * @Date: 2025-04-30 17:23:40
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-30 17:25:14
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline int getLength(int t) {
        int ans = 0;
        while (t) {
            ans++;
            t /= 10;
        }
        return ans;
    }
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int t : nums) {
            ans += getLength(t) % 2 == 0;
        }
        return ans;
    }
};