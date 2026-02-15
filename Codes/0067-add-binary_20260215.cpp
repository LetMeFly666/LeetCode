/*
 * @Author: LetMeFly
 * @Date: 2026-02-15 12:27:51
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-15 12:35:40
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

// THIS CANNOT BE ACCEPTED(maybe)
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ans;
        int cnt = 0;
        for (int i = 0, to = max(a.size(), b.size()); i < to; i++) {
            cnt += i < a.size() ? a[i] - '0' : 0;
            cnt += i < b.size() ? b[i] - '0' : 0;
            ans.push_back('0' + (cnt % 2));
            cnt >>= 1;
        }
        if (cnt) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

#if defined(_WIN32) || defined(__APPLE__)
int main() {
    vector<tuple<string, string, string>> tests = {
        {"11", "1", "110"},
        {"1010", "1011", "10101"}
    };
    for (auto [a, b, should] : tests) {
        Solution sol;
        string ans = sol.addBinary(a, b);
        assert(ans == should);
    } 
    return 0;
}
#endif