/*
 * @Author: LetMeFly
 * @Date: 2022-06-08 11:27:58
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-08 11:33:09
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string addBinary(string& a, string& b) {
        bool JinWei = false;
        if (a.size() < b.size())
            swap(a, b);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for (int i = 0; i < a.size(); i++) {
            int cnt = JinWei;
            cnt += a[i] - '0';
            if (i < b.size())
                cnt += b[i] - '0';
            a[i] = (cnt % 2) + '0';
            JinWei = cnt / 2;
        }
        if (JinWei)
            a += '1';
        reverse(a.begin(), a.end());
        return a;
    }
};