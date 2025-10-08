/*
 * @Author: LetMeFly
 * @Date: 2025-10-08 21:37:50
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-08 22:17:48
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

/*
a * b >= success
a >= success/b
s b s/b a
6 2  3  3
6 3  2  2
6 4 1.5 2
6 5 1.x 2
a >= ⌈s/b⌉
a >= ⌊(s+b-1)/b⌋
*/
typedef long long ll;
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        for (int& s : spells) {
            ll target = (success + s - 1) / s;
            if (target > 100000) {
                s = 0;
            } else {
                s = potions.end() - lower_bound(potions.begin(), potions.end(), target);
            }
        }
        return spells;
    }
};