/*
 * @Author: LetMeFly
 * @Date: 2023-11-10 14:17:25
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-10 14:23:41
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, ll success) {
        sort(potions.begin(), potions.end());
        for (int& t : spells) {
            ll toFind = success / t;
            if (toFind * t < success) {
                toFind++;
            }
            t = potions.end() - lower_bound(potions.begin(), potions.end(), toFind);
        }
        return spells;
    }
};