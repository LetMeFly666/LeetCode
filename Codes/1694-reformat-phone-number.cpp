/*
 * @Author: LetMeFly
 * @Date: 2022-10-01 08:48:46
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-01 09:02:22
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string reformatNumber(string& number) {
        string num;
        for (char& c : number) {
            if (c >= '0' && c <= '9') {
                num += c;
            }
        }
        string ans;
        for (int i = 0; i < num.size(); i++) {
            if (i % 3 == 0 && num.size() - i <= 4) {
                int remain = num.size() - i;
                if (remain == 2) {
                    ans += num[i];
                    ans += num[i + 1];
                }
                else if (remain == 3) {
                    ans += num[i];
                    ans += num[i + 1];
                    ans += num[i + 2];
                }
                else {
                    ans += num[i];
                    ans += num[i + 1];
                    ans += '-';
                    ans += num[i + 2];
                    ans += num[i + 3];
                }
                break;
            }
            ans += num[i];
            if (i % 3 == 2) {
                ans += '-';
            }
        }
        return ans;
    }
};