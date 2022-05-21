/*
 * @Author: LetMeFly
 * @Date: 2022-03-28 12:42:46
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-03-28 12:49:50
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool last = n & 1;
        while (n >>= 1) {
            if (last == (n & 1))
                return false;
            last = !last;
        }
        return true;
    }
};

#ifdef _WIN32
int main() {
    Solution sol;
    int n;
    while (cin >> n) {
        cout << sol.hasAlternatingBits(n) << endl;
    }
    return 0;
}
#endif