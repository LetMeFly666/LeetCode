/*
 * @Author: LetMeFly
 * @Date: 2023-12-25 12:13:25
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-25 12:18:23
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
x + y = c
4x + 2y = t
    ↓
2x + 2y = 2c
    ↓
2x = t - 2c
    ↓
x = 0.5t - c
y = c - x = 2c - 0.5t
*/

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int x = 0.5 * tomatoSlices - cheeseSlices, y = cheeseSlices - x;
        if (x < 0 || y < 0 || 4 * x + 2 * y != tomatoSlices) {
            return {};
        }
        return {x, y};
    }
};