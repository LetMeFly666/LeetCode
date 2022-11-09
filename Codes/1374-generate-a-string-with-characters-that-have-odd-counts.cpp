/*
 * @Author: LetMeFly
 * @Date: 2022-08-01 08:16:45
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-01 08:18:32
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry
class Solution {
public:
    string generateTheString(int n) {
        if (n % 2)
            return string(n, 'a');
        string ans(n - 1, 'a');
        ans.push_back('b');
        return ans;
    }
};
#else  // FirstTry
class Solution {
public:
    string generateTheString(int n) {
        return n % 2 ? string(n, 'a') : string(n - 1, 'a') + 'b';
    }
};
#endif  // FirstTry