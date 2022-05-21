/*
 * @Author: LetMeFly
 * @Date: 2022-04-01 08:40:20
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-01 08:45:33
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

const int _1e5 = 1e5;

class Solution {
private:
    int bin[200010];
public:
    bool canReorderDoubled(vector<int>& arr) {
        for (int &t : arr) {
            bin[t + _1e5]++;
        }
        for (int i = 0; i < _1e5;) {
            if (bin[i + _1e5]) {
                bin[i + _1e5]--;
                if (2 * i > _1e5 || !bin[2 * i + _1e5]) {
                    return false;
                }
                bin[2 * i + _1e5]--;
            }
            else {
                i++;
            }
        }
        for (int i = -1; i >= -_1e5;) {
            if (bin[i + _1e5]) {
                bin[i + _1e5]--;
                if (i * 2 < -_1e5 || !bin[i * 2 + _1e5]) {
                    return false;
                }
                bin[i * 2 + _1e5]--;
            }
            else {
                i--;
            }
        }
        return true;
    }
};