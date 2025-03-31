/*
 * @Author: LetMeFly
 * @Date: 2025-03-30 16:55:26
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-31 14:20:25
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

// g++ Codes\2109-adding-spaces-to-a-string_TestForTimeConsume.cpp -o temp.exe; ./temp.exe
// ./temp.exe
int main() {
    string s(100000, '0');
    time_t start = clock();
    for (int i = 0; i < 100000; i++) {
        s.insert(s.begin() + rand() % 10, rand() % 20);
    }
    time_t end = clock();
    cout << end - start << endl;  // 基本上280-290ms

    start = end;
    for (int i = 0; i < 100000; i++) {
        s[rand() % 10] = rand() % 20;  // 基本上3ms
    }
    end = clock();
    cout << end - start << endl;

    start = end;
    for (int i = 0; i < 100000; i++) {
        s += rand() % 20;    // 基本上2ms
    }
    end = clock();
    cout << end - start << endl;
    return 0;
}