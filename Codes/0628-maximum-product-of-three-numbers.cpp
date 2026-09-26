/*
 * @Author: LetMeFly
 * @Date: 2026-07-26 18:46:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-26 21:59:32
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

/*
全正 / 1负 / 2负 / 全负

+ 全正: 最大3+
+ 1负： 最大1-、最小2+
+ 2负： 最小2-、最大1+
+ 全负: 最大3-

不对，没考虑还有0的情况

---

假设全是负数： 只能选三个最大的
没正数但有0：  选0

算了，这样想有点麻烦

---

选法：不是迫不得已不选三个负数 / 尽量不选0

假设正负数都很充足： 三个最大 / 两个最小负数+一最大正数
没有负数： 三个最大
必须选且只选一个负数：只有一个负数和另外两个数，就三个数没得选
有至少两个负数并且能选非负数：两个最小负数+一最大数
只能全选负数：三个最大负数

要么三个最大，要么两个最小+一最大
*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size();
        return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[n - 1]);
    }
};
