/*
 * @Author: LetMeFly
 * @Date: 2023-07-22 09:02:40
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-07-22 09:04:56
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int _5 = 0, _10 = 0;
        for (int bill : bills) {
            if (bill == 5) {
                _5++;
            }
            else if (bill == 10) {
                if (_5) {
                    _5--;
                    _10++;
                }
                else {
                    return false;
                }
            }
            else {
                if (_10 && _5) {
                    _10--, _5--;
                }
                else if (_5 >= 3) {
                    _5 -= 3;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};