/*
 * @Author: LetMeFly
 * @Date: 2022-07-27 10:45:34
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-27 11:03:21
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif


typedef pair<int, int> pii;
class Solution {
private:
    pii string2fraction(string s) {
        pii ans;
        if (s[0] == '-') {
            ans.first = -1;
        }
        int l = 0;
        if (s[0] == '-' || s[0] == '+') {
            l++;
        }
        int r = l;
        while (s[r] != '/')
            r++;
        ans.first *= atoi(s.substr(l, r - l).c_str());
        ans.second = atoi(s.substr(r + 1, s.size() - r - 1).c_str());
        return ans;
    }

    pii add(pii p1, pii p2) {
        pii ans;
        ans.second = p1.second * p2.second / __gcd(p1.second, p2.second);
        ans.first = p1.first * (ans.second / p1.second) + p2.first * (ans.second / p2.second);
        int gcd = __gcd(ans.first, ans.second);
        ans.first /= gcd, ans.second /= gcd;
        return ans;
    }

    string fraction2string(pii f) {
        return to_string(f.first) + "/" + to_string(f.second);
    }
public:
    string fractionAddition(string expression) {
        pii ans = {0, 1};
        int last = 0;
        for (int i = 1; i < expression.size(); i++) {
            if (i == '+' || i == '-') {
                ans = add(ans, string2fraction(expression.substr(last, i - last)));
                last = i;
            }
        }
        ans = add(ans, string2fraction(expression.substr(last, expression.size() - last)));
        return fraction2string(ans);
    }
};