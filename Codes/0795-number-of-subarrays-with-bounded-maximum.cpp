/*
 * @Author: LetMeFly
 * @Date: 2022-11-24 11:00:12
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-24 15:50:38
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error  // 是“最大元素 在[left, right]”范围内的子数组
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0;
        int lastCannot = -1;
        int n = nums.size();
        for (int i = 0; i <= n; i++) {
            if (i == n || nums[i] < left || nums[i] > right) {
                ans += (1 << (i - lastCannot - 1)) - 1;
                lastCannot = i;
            }
        }
        return ans;
    }
};
#else  // FirstTry
#ifdef SecondTry  // Error 是子数组不是子序列
class Solution {
private:
    int noMoreThan(vector<int>& a, int b) {  // a中的 “所有元素都不大于b 的子数组的个数”
        int ans = 0;
        int lastLoc = -1;
        int n = a.size();
        for (int i = 0; i <= n; i++) {
            if (i == n || a[i] > b) {
                ans += (1 << (i - lastLoc - 1)) - 1;
                lastLoc = i;
            }
        }
        printf("ans = %d\n", ans);
        return ans;
    }
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return noMoreThan(nums, right) - noMoreThan(nums, left - 1);
    }
};
#else  // SecondTry
// ThirdTry
class Solution {
private:
    int noMoreThan(vector<int>& a, int b) {  // a中的 “所有元素都不大于b 的子数组的个数”
        int ans = 0;
        int lastLoc = -1;
        int n = a.size();
        for (int i = 0; i <= n; i++) {
            if (i == n || a[i] > b) {
                ans += (long long)(i - lastLoc - 1) * (i - lastLoc) / 2;
                lastLoc = i;
            }
        }
        return ans;
    }
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return noMoreThan(nums, right) - noMoreThan(nums, left - 1);
    }
};
#endif  // SecondTry
#endif  // FirstTry