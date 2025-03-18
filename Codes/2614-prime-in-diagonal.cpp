/*
 * @Author: LetMeFly
 * @Date: 2025-03-18 23:40:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-18 23:43:36
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool isPrime(int n) {
        if (n < 2) {
            return false;
        }
        int k = sqrt(n);
        for (int i = 2; i <= k; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (isPrime(nums[i][i])) {
                ans = max(ans, nums[i][i]);
            }
            if (isPrime(nums[i][nums.size() - i - 1])) {
                ans = max(ans, nums[i][nums.size() - i - 1]);
            }
        }
        return ans;
    }
};