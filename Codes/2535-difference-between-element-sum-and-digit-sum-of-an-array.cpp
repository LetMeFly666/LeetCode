/*
 * @Author: LetMeFly
 * @Date: 2024-09-26 18:07:18
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-26 18:08:22
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int getSum(int n) {
        int ans = 0;
        while (n) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
public:
    int differenceOfSum(vector<int>& nums) {
        int x = 0, y = 0;
        for (int t : nums) {
            x += t, y += getSum(t);
        }
        return abs(x - y);
    }
};