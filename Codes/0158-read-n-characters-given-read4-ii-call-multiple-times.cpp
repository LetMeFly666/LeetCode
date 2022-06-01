/*
 * @Author: LetMeFly
 * @Date: 2022-06-01 10:58:37
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-01 15:30:35
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
private:
    char buf4[5];
    int locBuf = 0;
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int already = 0;
        // 从buf4中读入
        int readFromBuf4 = min(n - already, locBuf);
        for (int i = 0; i < readFromBuf4; i++) {
            buf[already++] = buf4[i];
        }
        for (int i = readFromBuf4; i < locBuf; i++) {
            buf4[i - readFromBuf4] = buf4[i];
        }
        locBuf -= readFromBuf4;

        if (already == n) {
            return n;
        }

        // 从文件中读入
        while (true) {
            locBuf = read4(buf4);
            if (!locBuf) {
                break;
            }
            int need = min(n - already, locBuf);
            for (int i = 0; i < need; i++) {
                buf[already++] = buf4[i];
            }
            for (int i = need; i < locBuf; i++) {
                buf4[i - need] = buf4[i];
            }
            locBuf -= need;
            if (locBuf)
                break;
        }
        return already;
    }
};