/*
 * @Author: LetMeFly
 * @Date: 2024-07-02 09:26:05
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-02 10:48:14
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline bool isPrime(int n) {
        if (n == 1) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int m = 10000000, M = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (isPrime(nums[i])) {
                m = min(m, i);
                M = max(M, i);
            }
        }
        return M - m;
    }
};