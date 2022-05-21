/*
 * @Author: LetMeFly
 * @Date: 2021-10-11 21:30:28
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-10-11 22:22:37
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

const char _0_19[][20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"}; // _0_19[5]: 5
const char _20_90[][20] = {"And", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"}; // _20_90[5]: 50
const char _1e2[20] = {"Hundred"};
const char _1e3[20] = {"Thousand"};
const char _1e6[20] = {"Million"};
const char _1e9[20] = {"Billion"};

string _0_999(int num) {
    if (num < 20) return _0_19[num];
    int _100 = num / 100;
    string ans;
    if (_100) ans = ans + _0_19[_100]+" "+_1e2; // Two Hundred
    num %= 100;
    if (num) {
        if (ans.size()) ans += " ";
        if (num < 20) ans += _0_19[num];
        else {
            int _10 = num / 10;
            ans += _20_90[_10];
            num %= 10;
            if (num) {
                ans += " ";
                ans += _0_19[num];
            }
        }
    }
    return ans;
}
class Solution {
public:
    string numberToWords(int num) {
        string ans;
        int _1e9_ = num / int(1e9);
        if (_1e9_) ans = _0_999(_1e9_) + " " + _1e9;
        num %= int(1e9);
        int _1e6_ = num / int(1e6);
        if (_1e6_) {
            if (ans.size()) ans += " ";
            ans += _0_999(_1e6_) + " " + _1e6;
        }
        num %= int(1e6);
        int _1e3_ = num / int(1e3);
        if (_1e3_) {
            if (ans.size()) ans += " ";
            ans += _0_999(_1e3_) + " " + _1e3;
        }
        num %= int(1e3);
        if (num || ans.empty()) {
            if (ans.size()) ans += " ";
            ans += _0_999(num);
        }
        return ans;
    }
};

int main() {
    int n;
    while(cin>>n) {
        Solution sol;
        cout << sol.numberToWords(n) << endl;
    }
    return 0;
}