/*
 * @Author: LetMeFly
 * @Date: 2022-06-27 16:15:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-27 16:42:21
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry
// TLE
class Solution {
public:
    int numDecodings(string& s, int loc = 0) {
        if (loc == s.size()) {
            return 1;
        }
        int ans = 0;
        if (loc < s.size()) {
            if (s[loc] != '0') {
                ans += numDecodings(s, loc + 1);
            }
        }
        if (loc + 1 < s.size()) {
            int val = (s[loc] - '0') * 10 + (s[loc + 1] - '0');
            if (s[loc] != '0' && val >= 10 && val <= 26) {
                ans += numDecodings(s, loc + 2);
            }
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry  // 从后往前遍历
class Solution {
private:
    bool isNum(string& s, int loc) {
        return s[loc] != '0';
    }

    bool isNum(string& s, int l, int r) {
        if (s[l] == '0')
            return false;
        if (s[l] == '1') {
            return true;
        }
        if (s[l] == '2') {
            return s[r] < '7';
        }
        return false;
    }
public:
    int numDecodings(string& s) {
        if (s.size() == 1)
            return isNum(s, s.size() - 1);
        int last1 = isNum(s, s.size() - 1);
        int last2 = isNum(s, s.size() - 2, s.size() - 1) + isNum(s, s.size() - 2) * last1;
        for (int i = s.size() - 3; i >= 0; i--) {
            int thisNum = isNum(s, i) * last2 + isNum(s, i, i + 1) * last1;
            last1 = last2, last2 = thisNum;
        }
        return last2;
    }
};
#endif  // FirstTry

#ifdef _WIN32
int main() {
    string s;
    while (cin >> s) {
        s = s.substr(1, s.size() - 1);
        s = s.substr(0, s.size() - 1);
        Solution sol;
        cout << sol.numDecodings(s) << endl;
    }
    return 0;
}
#endif