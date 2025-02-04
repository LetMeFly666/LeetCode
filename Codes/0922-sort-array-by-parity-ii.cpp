/*
 * @Author: LetMeFly
 * @Date: 2025-02-04 22:15:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-04 22:23:51
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // RE - i+=2后可能会超出边界
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        for (int i = 0, j = 1; i < nums.size() && j < nums.size(); i += 2, j += 2) {
            while (i < nums.size() && nums[i] % 2 == 0) {
                i += 2;
            }
            while (j < nums.size() && nums[j] % 2) {
                j += 2;
            }
            swap(nums[i], nums[j]);
        }
        return nums;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        for (int i = 0, j = 1; i < nums.size();) {
            if (nums[i] % 2 == 0) {
                i += 2;
            } else if (nums[j] % 2) {
                j += 2;
            } else {
                swap(nums[i], nums[j]);
                i += 2;
                j += 2;
            }
        }
        return nums;
    }
};
#endif  // FirstTry