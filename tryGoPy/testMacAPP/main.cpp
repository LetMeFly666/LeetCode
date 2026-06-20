/*
 * @Author: LetMeFly
 * @Date: 2026-06-20 14:59:23
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-20 15:10:35
 */
// #include <iostream>

// int main() {
//     std::cout << "Hello World" << std::endl;
//     getchar();
//     return 0;
// }


#include <cstdlib>

int main() {
    system("osascript -e 'tell application \"Terminal\" to activate'");
    system("osascript -e 'tell application \"Terminal\" to do script \"echo Hello from C++ App; read\"'");
    return 0;
}

