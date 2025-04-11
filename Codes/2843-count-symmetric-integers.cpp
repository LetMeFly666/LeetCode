/*
 * @Author: LetMeFly
 * @Date: 2025-04-11 21:02:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-11 21:06:39
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool isOk(int n) {
        string temp = to_string(n);
        if (temp.size() % 2) {
            return false;
        }
        int cnt = 0;
        for (int i = 0; i < temp.size() / 2; i++) {
            cnt += temp[i] - temp[temp.size() - i - 1];  // 不用转为对应的数字就行
        }
        return cnt == 0;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; i++) {
            ans += isOk(i);
        }
        return ans;
    }
};