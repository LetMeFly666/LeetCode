/*
 * @Author: LetMeFly
 * @Date: 2022-05-07 10:00:39
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-31 09:37:51
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // [2022-05-07 10:00:39, 2022-05-07 10:05:05]
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
#else  // FirstTry
#ifdef SecondTry  // 20221031  // 按字符串处理
class Solution {
public:
    bool isPalindrome(int x) {
        string s1 = to_string(x);
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        return s1 == s2;
    }
};
#else  // SecondTry
// ThirdTry
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int reversed = 0, original = x;
        while (x) {
            if (INT_MAX / 10 < reversed)
                return false;
            reversed = reversed * 10 + (x % 10);
            x /= 10;
        }
        return reversed == original;
    }
};
#endif  // SecondTry
#endif  // FirstTry

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