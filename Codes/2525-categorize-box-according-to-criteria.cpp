/*
 * @Author: LetMeFly
 * @Date: 2023-10-20 12:03:20
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-20 12:08:57
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

const string dict[4] = {"Neither", "Heavy", "Bulky", "Both"};

typedef long long ll;
class Solution {
public:
    string categorizeBox(ll length, ll width, ll height, ll mass) {
        bool bulky = length >= 10000 || width >= 10000 || height >= 10000 || length * width * height >= 1000000000;
        bool heavy = mass >= 100;
        return dict[bulky * 2 + heavy];
    }
};