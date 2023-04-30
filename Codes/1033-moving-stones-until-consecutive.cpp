/*
 * @Author: LetMeFly
 * @Date: 2023-04-30 09:53:53
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-04-30 10:11:04
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        // sort(a, b, c)
        if (a > b) {
            swap(a, b);
        }
        if (b > c) {
            swap(b, c);
        }
        if (a > b) {
            swap(a, b);
        }
        // calculate
        if (a + 1 == b && b + 1 == c) {  // 直接相连
            return {0, 0};
        }
        if (a + 1 == b || b + 1 == c || a + 2 == b || b + 2 == c) {  // 有两个相连 或 有两个间隔为2
            return {1, c - a - 2};
        }
        else {  // 三个各不相连
            return {2, c - a - 2};
        }
    }
};

#ifdef _WIN32
int main() {
    int a, b, c;
    while (cin >> a >> b >> c) {
        Solution sol;
        debug(sol.numMovesStones(a, b, c));
    }
    return 0;
}
#endif