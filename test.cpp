/*
 * @Author: LetMeFly
 * @Date: 2026-01-23 19:50:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-23 19:54:00
 */
#include <iostream>
using namespace std;

int test(int a, int b, int c, int d) {
    // return a > b + b > c + c > d;  // 0
    // return 0 + a > b + b > c + c > d;  // 0
    return 0 + (a > b) + (b > c) + (c > d);  // 3
}

int main() {
    cout << test(4, 3, 2, 1) << endl;
    return 0;
}