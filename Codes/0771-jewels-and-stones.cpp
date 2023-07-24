/*
 * @Author: LetMeFly
 * @Date: 2023-07-24 08:43:42
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-07-24 08:45:14
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool isIn(char c, string& s) {
        for (char _ : s) {
            if (c == _) {
                return true;
            }
        }
        return false;
    }
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        for (char stone : stones) {
            ans += isIn(stone, jewels);
        }
        return ans;
    }
};