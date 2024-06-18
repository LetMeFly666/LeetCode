/*
 * @Author: LetMeFly
 * @Date: 2024-06-18 18:48:46
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-18 19:08:59
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool isPrice(string& s, int l, int r) {  // [l, r)
        if (s[l] != '$') {
            return false;
        }
        if (l + 1 == r) {
            return false;
        }
        while (++l < r) {
            if (!isdigit(s[l])) {
                return false;
            }
        }
        return true;
    }

    string newPrice(string& s, int l, int r, int discount) {
        long long val = 0;
        for (; l < r; l++) {
            val = val * 10 + s[l] -'0';
        }
        val *= 100 - discount;
        return '$' + to_string(val / 100) + '.' + to_string(val / 10 % 10) + to_string(val % 10);
    }
public:
    string discountPrices(string sentence, int discount) {
        string ans;
        for (int l = 0, r = 0; l < sentence.size();) {
            while (r < sentence.size() && sentence[r] != ' ') {
                r++;
            }
            if (isPrice(sentence, l, r)) {
                ans += newPrice(sentence, l + 1, r, discount);
            }
            else {
                while (l < r) {
                    ans += sentence[l];
                    l++;
                }
            }
            if (r != sentence.size()) {
                ans += ' ';
            }
            l = r + 1;
            r++;
        }
        return ans;
    }
};