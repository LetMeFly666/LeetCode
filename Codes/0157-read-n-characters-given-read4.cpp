/*
 * @Author: LetMeFly
 * @Date: 2022-05-29 13:50:32
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-29 13:55:23
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
int read4(char* s) {
    return rand() % 5;
}
#endif

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int ans = 0;
        int thisNum;
        while (thisNum = read4(buf + ans)) {
            ans += thisNum;
            if (ans >= n) {
                while (ans > n) {
                    *(buf + --ans) = '\0';
                }
                break;
            }
        }
        return ans;
    }
};