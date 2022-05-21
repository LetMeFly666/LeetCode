/*
 * @Author: LetMeFly
 * @Date: 2022-04-10 08:46:08
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-10 08:50:36
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> already;
        while (true) {
            int newNum = 0;
            while (n) {
                newNum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = newNum;
            if (n == 1) {
                return true;
            }
            if (already.count(n)) {
                return false;
            }
            already.insert(n);
        }
        return false;  //*****FAKE RETURN;
    }
};