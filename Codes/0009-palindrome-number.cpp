/*
 * @Author: LetMeFly
 * @Date: 2022-05-07 10:00:39
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-07 10:05:05
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int n = 0, input = x;
        while (x) {
            if (INT_MAX / 10 < n)
                return false;  // 不然n可能会超INT_MAX
            n *= 10;
            n += x % 10;
            x /= 10;
        }
        return n == input;
    }
};

#ifdef _WIN32
int main() {
    int x;
    while (cin >> x) {
        Solution sol;
        cout << sol.isPalindrome(x) << endl;
    }
    return 0;
}
#endif