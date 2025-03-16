/*
 * @Author: LetMeFly
 * @Date: 2025-03-16 20:53:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-16 20:53:46
 */
#include <iostream>
using namespace std;
typedef long long ll;

/*
1100100
4 + 32 + 64 = 100


*/

/*
100 -> 1100100
*/
string itos(ll a) {
    string s;
    while (a) {
        s = char('0' + a % 2) + s;
        a >>= 1;
    }
    return s;
}

/*
0111 -> 7
*/
string _422(string s) {
    ll n = 0;
    for (char c : s) {
        n = n * 2 + c - '0';
    }
    // cout << "n: " << n << endl;
    string ans;
    if (n < 10) {
        ans = string(1, char('0' + n));
    } else {
        ans = string(1, char('A' + n - 10));
    }
    // cout << ans << endl;
    return ans;
}

/*
11100111 -> 0XE7
*/
string stos(string s) {
    // cout << s << endl;
    if (s.size() < 8) {
        s = string(8 - s.size(), '0') + s;
    }
    // cout << "stos: " << s << endl;
    return "0X" + _422(s.substr(0, 4)) + _422(s.substr(4, 4));
}

string fi(ll a) {
    string s = itos(a);
    // cout << s << endl;
    string ans = "";
    while (s.size() > 7) {
        string thisStr = '1' + s.substr(s.size() - 7, 7);
        s = s.substr(0, s.size() - 7);
        ans += stos(thisStr);
    }
    ans += stos(s);
    return ans;
}

ll c2i(char c) {
    if (c <= '9') {
        return c - '0';
    }
    return 10 + c - 'A';
}

string c2s(char c) {
    ll n = c2i(c);
    string temp = itos(n);
    if (temp.size() < 4) {
        temp = string(4 - temp.size(), '0') + temp;
    }
    return temp;
}

/*
0XE7 -> 1100111(丢掉最高位)
*/
string _16_2(string s) {
    // cout << "_16_2: " << s << endl;
    return (c2s(s[2]) + c2s(s[3])).substr(1, 7);
}

/*
二进制->10进制
*/
ll _2_10(string s) {
    ll ans = 0;
    for (char c : s) {
        ans = ans * 2 + c - '0';
    }
    return ans;
}

ll fs(string s) {
    string bin;
    for (ll i = 0; i < s.size(); i += 4) {
        bin = _16_2(s.substr(i, 4)) + bin;
    }
    return _2_10(bin);
}

int main() {
    ll a;
    string s;
    cin >> a >> s;
    cout << fi(a) << endl;
    cout << fs(s) << endl;
}
// 64 位输出请用 prllf("%lld")