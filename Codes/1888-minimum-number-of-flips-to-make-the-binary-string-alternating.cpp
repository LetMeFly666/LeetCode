/*
 * @Author: LetMeFly
 * @Date: 2026-03-07 17:46:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-07 18:01:06
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif


/*
01001001101
   3次右移
01001101010
   ||
01010101010

相当于
01001001101
      ||
01001010101
  --
01010101010
_         _


01001001101
   1次右移
10010011010


*/
class Solution {
public:
    int minFlips(string s) {
        int o1 = 0, o2 = 0;
        for (int i = 0; i < s.size(); i++) {
            o1 += s[i] % 2 == i % 2;
            o2 += s[i] % 2 != i % 2;
        }
        return min(o1, o2);
    }
};