/*
 * @Author: LetMeFly
 * @Date: 2022-08-26 08:52:42
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-26 08:56:24
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        return (nums[0] - 1) * (nums[1] - 1);
    }
};
#else  // FirstTry
// SecondTry  // 两次遍历，O(n)+O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0, locMax1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max1) {
                max1 = nums[i];
                locMax1 = i;
            }
        }
        int max2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max2 && i != locMax1) {
                max2 = nums[i];
            }
        }
        return (max1 - 1) * (max2 - 1);
    }
};
#endif  // FirstTry