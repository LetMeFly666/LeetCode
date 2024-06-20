/*
 * @Author: LetMeFly
 * @Date: 2024-06-20 09:07:14
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-20 09:09:34
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline int getFirst(int n) {
        while (n >= 10) {
            n /= 10;
        }
        return n;
    }
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (__gcd(getFirst(nums[i]), nums[j] % 10) == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};