/*
 * @Author: LetMeFly
 * @Date: 2022-09-28 12:22:52
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-28 12:26:27
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int getKthMagicNumber(int k) {
        int loc3 = 0, loc5 = 0, loc7 = 0;
        vector<int> v = {1};
        while (--k) {
            int result3 = v[loc3] * 3;
            int result5 = v[loc5] * 5;
            int result7 = v[loc7] * 7;
            int m = min(result3, min(result5, result7));
            v.push_back(m);
            if (result3 == m) {
                loc3++;
            }
            if (result5 == m) {
                loc5++;
            }
            if (result7 == m) {
                loc7++;
            }
        }
        return v.back();
    }
};