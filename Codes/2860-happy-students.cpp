/*
 * @Author: LetMeFly
 * @Date: 2024-09-04 12:41:59
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-04 12:55:08
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error  // 看错题了
class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 1 + (*min_element(nums.begin(), nums.end()) > 0);
        for (int i = 1; i < nums.size(); i++) {
            ans += i > nums[i - 1] && nums.size() - i < nums[i];
            // if (i > nums[i - 1] && nums.size() - i < nums[i]) {
            //     printf("i = %d, ok!\n", i);
            // }
            if (i == 4) {
                printf("%d > %d && %d < %d: %d\n", i, nums[i - 1], int(nums.size() - i), nums[i], int(i > nums[i - 1] && nums.size() - i < nums[i]));
            }
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 1 + (*min_element(nums.begin(), nums.end()) > 0);
        for (int i = 1; i < nums.size(); i++) {
            ans += i > nums[i - 1] && i < nums[i];
        }
        return ans;
    }
};
#endif  // FirstTry