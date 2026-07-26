/*
 * @Author: LetMeFly
 * @Date: 2026-07-26 18:46:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-26 19:04:58
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


*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        vector<int> pos, neg;
        for (int t : nums) {
            if (t < 0) {

            }
        }
    }
};
