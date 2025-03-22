/*
 * @Author: LetMeFly
 * @Date: 2025-03-22 19:14:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-22 19:25:02
 */
#include <bits/stdc++.h>
using namespace std;

inline bool isOk(char c) {
    static const string okList = "AHIMOTUVWXY";
    for (char ok : okList) {
        if (c == ok) {
            return true;
        }
    }
    return false;
}

bool isOk(string s) {
    for (char c : s) {
        if (!isOk(c)) {
            return false;
        }
    }
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

int solve(string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {  // 长度大于1
            bool thisIsOk = isOk(s.substr(i, j - i + 1));
            ans += thisIsOk;
            #ifdef _WIN32
                if (thisIsOk) {
                    printf("i = %d, j = %d, s.substr(%d, %d) = %s : OK\n", i, j, i, j, s.substr(i, j).c_str());
                }
            #endif
        }
    }
    return ans;
}

int main() {
#ifdef _WIN32
    vector<string> S = {"AHHAMTT"};
    vector<int> ANS = {3};
    for (int i = 0; i < S.size(); i++) {
        int ans = solve(S[i]);
        cout << S[i] << ": " << ans << endl;
        assert(ans == ANS[i]);
    }
#else
    string s;
    cin >> s;
    cout << solve(s) << endl;
#endif
    return 0;
}