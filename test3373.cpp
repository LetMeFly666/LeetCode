/*
 * @Author: LetMeFly
 * @Date: 2025-05-29 22:41:41
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-29 22:43:38
 */
#include <iostream>

int main() {
    std::pair<int, int> p;
    std::cout << p.first << std::endl;  // 0
    p.first++;
    std::cout << p.first << std::endl;  // 1
    return 0;
}