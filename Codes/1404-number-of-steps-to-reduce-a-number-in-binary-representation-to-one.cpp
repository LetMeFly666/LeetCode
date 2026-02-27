/*
 * @Author: LetMeFly
 * @Date: 2026-02-26 22:06:13
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-27 21:50:19
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

/*
1101
1110
111
1000
100
10
1
*/

class LetsNum {
private:
    // 低位->高位
    deque<char> num;
public:
    // From binary string
    LetsNum(string& s) {
        for (char c : s) {
            *this <<= 1;
            *this += c;
        }
    }

    LetsNum& operator++(int) {
        int carry = 1;
        for (deque<char>::iterator it = num.begin(); it != num.end(); it++) {
            carry += *it - '0';
            *it = carry % 10 + '0';
            carry /= 10;
        }
        if (carry) {
            num.push_back(carry + '0');
        }
        return *this;
    }

    // only 0/1 supported
    LetsNum& operator+=(const int& n) {
        if (!n) {
            return *this;
        }
        (*this)++;
        return *this;
    }

    // only 0/1 supported
    LetsNum& operator+=(const char& c) {
        *this += c - '0';
        return *this;
    }

    // only <<1 supported
    LetsNum& operator<<=(const int&) {
        int carry = 0;
        for (deque<char>::iterator it = num.begin(); it != num.end(); it++) {
            carry += (*it - '0') * 2;
            *it = carry % 10 + '0';
            carry /= 10;
        }
        if (carry) {
            num.push_back(carry + '0');
        }
        return *this;
    }

    // only >>1 supported
    LetsNum& operator>>=(const int&) {
        num.erase(num.begin());
        return *this;
    }

    // only 1 supported
    bool operator!=(const int&) {
        return num.size() != 1 || *num.begin() != '1';
    }

    bool isOdd() {
        return (*num.begin() - '0') % 2;
    }

    void print() {
        for (deque<char>::reverse_iterator it = num.rbegin(); it != num.rend(); it++) {
            putchar(*it);
        }
        puts("");
    }
};

class Solution {
public:
    int numSteps(string s) {
        LetsNum num(s);
        int ans = 0;
        while (num != 1) {
            if (num.isOdd()) {
                num += 1;
            } else {
                num >>= 1;
            }
            ans++;
        }
        return ans;
    }
};


#if defined(_WIN32) || defined(__APPLE__)
/*
1101
*/
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        cout << sol.numSteps(s) << endl;
    }
    return 0;
}
#endif
