/*
 * @Author: LetMeFly
 * @Date: 2024-09-12 20:51:39
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-12 21:21:00
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // WA, 反例：[1, 2, 4]
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int l = 0, r = nums.size() / 2; r < nums.size(); r++) {
            if (nums[l] * 2 <= nums[r]) {
                ans += 2, l++;
            }
        }
        return ans;
    }
};
/*
[57,40,57,51,90,51,68,100,24,39,11,85,2,22,67,29,74,82,10,96,14,35,25,76,26,54,29,44,63,49,73,50,95,89,43,62,24,88,88,36,6,16,14,2,42,42,60,25,4,58,23,22,27,26,3,79,64,20,92]
上面长度为59，但方法一计算出来结果为60
*/
#else  // FirstTry
// SecondTry
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int l = 0, r = (nums.size() + 1) / 2; r < nums.size(); r++) {
            if (nums[l] * 2 <= nums[r]) {
                ans += 2, l++;
            }
        }
        return ans;
    }
};
#endif