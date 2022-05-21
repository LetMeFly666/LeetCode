/*
 * @Author: LetMeFly
 * @Date: 2022-05-09 10:32:48
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-09 10:48:33
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry_Error
/*
    1994 -> MCMXCIV
    1994 = 1000 + 900 + 90 + 4
    M = 1000, CM = 900, XC = 90, IV = 4
*/
static const int jinZhi[7] = {1, 5, 10, 50, 100, 500, 1000};
static const char i2c[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
static const int lenJinZhi = 7;

static const int special[6] = {4, 9, 40, 90, 400, 900};
static const char sp2s[6][3] = {"IV", "IX", "XL", "XC", "CD", "CM"};
static const int lenSpecial = 6;

class Solution {
public:
    string intToRoman(int num) {
        string ans;
        while (num) {
            for (int i = lenSpecial - 1; i >= 0; i--) {
                if (num == special[i]) {
                    ans += sp2s[i];
                    num -= special[i];
                }
            }
            for (int i = lenJinZhi - 1; i >= 0; i--) {
                if (num >= jinZhi[i]) {
                    ans += i2c[i];
                    num -= jinZhi[i];
                    break;
                }
            }
        }
        return ans;
    }
};

#else

static int jinZhi[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
static char i2s[][3] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
static const int len = sizeof(jinZhi) / sizeof(jinZhi[0]);

class Solution {
public:
    string intToRoman(int num) {
        string ans;
        while (num) {
            for (int i = len - 1; i >= 0; i--) {
                if (num >= jinZhi[i]) {
                    ans += i2s[i];
                    num -= jinZhi[i];
                    break;
                }
            }
        }
        return ans;
    }
};

#endif