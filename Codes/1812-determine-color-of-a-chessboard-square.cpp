/*
 * @Author: LetMeFly
 * @Date: 2022-12-08 09:19:05
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-08 09:21:50
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FristTry  // 奇偶判断
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return (coordinates[0] - 'a') % 2 != (coordinates[1] - '1') % 2;
    }
};
#else  // FristTry
// SecondTry  // 小改进，直接不减了
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return coordinates[0] % 2 != coordinates[1] % 2;
    }
};
#endif  // FristTry