/*
 * @Author: LetMeFly
 * @Date: 2022-04-28 08:57:21
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-28 09:02:45
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry
// 开了一个新数组
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans(nums.size());
        int O = 0, J = nums.size() - 1;
        for (int& t : nums) {
            if (t % 2) {
                ans[J--] = t;
            }
            else {
                ans[O++] = t;
            }
        }
        return ans;
    }
};
#else
// 原地交换
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            while (nums[l] % 2 == 0 && l < r) {
                l++;
            }
            while (nums[r] % 2 && l < r) {
                r--;
            }
            swap(nums[l], nums[r]);
        }
        return nums;
    }
};
#endif