/*
 * @Author: LetMeFly
 * @Date: 2022-08-12 10:41:08
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-12 10:52:38
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 额外空间
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int add = k / n * n + n;  // >= k
        vector<int> original(nums);
        for (int i = 0; i < n; i++) {
            nums[i] = original[(i - k + add) % n];
        }
    }
};
#else  // FirstTry
// SecondTry  // 数组反转
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
#endif  // FirstTry