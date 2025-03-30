/*
 * @Author: LetMeFly
 * @Date: 2025-03-30 16:55:26
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-30 17:01:33
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

int main() {
    time_t start = clock();
    _sleep(1000);
    time_t end = clock();
    puts("");
    cout << end - start << endl;
    puts("");
    return 0;
}