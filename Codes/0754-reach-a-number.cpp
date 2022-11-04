/*
 * @Author: LetMeFly
 * @Date: 2022-11-04 09:29:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-04 10:36:51
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

// class Solution {
// public:
//     int reachNumber(int target) {
//         unsigned to = abs(target);
//         unsigned n = sqrt(to * 2);
//         int diff = n * (n + 1) / 2 - to;
//         if (!diff)
//             return n;
//         if (diff % 2)
//             return n + 2;
//         return n + 1;
//     }
// };

#ifdef FirstTry  // 枚举
class Solution {
public:
    int reachNumber(int target) {
        unsigned to = abs(target);
        unsigned n = 0;
        while (true) {
            unsigned result = n * (n + 1) / 2;
            if (result >= to && (result - to) % 2 == 0)
                return n;
            n++;
        }
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    int reachNumber(int target) {
        unsigned to = abs(target);
        unsigned simN = max((int)sqrt(to * 2) - 2, 0);
        while (true) {
            unsigned result = simN * (simN + 1) / 2;
            if (result >= to && (result - to) % 2 == 0)
                return simN;
            simN++;
        }
    }
};
#endif  // FirstTry