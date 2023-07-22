/*
 * @Author: LetMeFly
 * @Date: 2023-07-22 09:02:40
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-07-22 09:25:43
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        return all_of(bills.begin(), bills.end(), [_5 = 0, _10 = 0](int bill)mutable {return bill == 5 ? ++_5 : bill == 10 ? (_5-- && ++_10) : _10 ? (_10-- && _5--) : ((_5 -= 3) >= 0);});
    }
};