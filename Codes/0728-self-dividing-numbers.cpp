/*
 * @Author: LetMeFly
 * @Date: 2022-03-31 09:00:54
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-03-31 09:04:41
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

bool isOk(int n) {
    int t = n;
    while (n) {
        if (n % 10 == 0)
            return false;
        if (t % (n % 10))
            return false;
        n /= 10;
    }
    return true;
}

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            if (isOk(i))
                ans.push_back(i);
        }
        return ans;
    }
};