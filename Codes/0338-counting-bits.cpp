/*
 * @Author: LetMeFly
 * @Date: 2022-09-28 12:46:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-28 13:17:17
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 内置__builtin_popcount,83.71%,56.81%
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; i++) {
            ans[i] = __builtin_popcount(i);
        }
        return ans;
    }
};
#else  // FirstTry
#ifdef SecondTry  // 不为0时取最低位,7.24%,55.59%
class Solution {
private:
    int __LetMeFly_popcount(int n) {
        int ans = 0;
        while (n) {
            if (n & 1)
                ans++;
            n >>= 1;
        }
        return ans;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; i++) {
            ans[i] = __LetMeFly_popcount(i);
        }
        return ans;
    }
};
#else  // SecondTry
// ThirdTry  // 借助lowbit,83.71%,96.33%
class Solution {
private:
    int __LetMeFly_popcount_byLowbit(int n) {
        int ans = 0;
        while (n) {
            n -= (n & -n);
            ans++;
        }
        return ans;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; i++) {
            ans[i] = __LetMeFly_popcount_byLowbit(i);
        }
        return ans;
    }
};
#endif  // SecondTry
#endif  // FirstTry