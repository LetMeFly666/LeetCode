#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif
// x - 1的字符串
class Solution {
private:
    void invert(string& s) {
        for (char& c : s) {
            c = c == '0' ? '1' : '0';
        }
    }

    string next(string& now) {
        string ans = now + '1';
        invert(now);
        reverse(now.begin(), now.end());
        ans += now;
        return ans;
    }
public:
    char findKthBit(int n, int k) {
        string now = "0";
        for (int i = 2; i <= n; i++) {
            now = next(now);
        }
        return now[k - 1];
    }
};