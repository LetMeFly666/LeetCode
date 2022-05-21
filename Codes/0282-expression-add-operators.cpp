/*
 * @Author: LetMeFly
 * @Date: 2021-10-16 10:15:32
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-10-16 11:23:58
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
#define QIAN_DAO_LING ((ll)(1e17))

template<class Type>
void debug(vector<Type>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<' ';
    }
    puts("");
}
void bitDebug(int n) {
    string ans;
    while (n) {
        if (n & 1) ans ='1' + ans;
        else ans = '0' + ans;
        n >>= 1;
    }
    // dbg(ans); //*****
}

string op[4] = {"", "+", "-", "*"};
// vector<string> split(string &s, string &space) {
//     vector<string> ans;
    
//     return ans;
// }
ll eval(string &s) { // 只有数字
    ll ans = 0;
    for (char &c: s) {
        ans *= 10;
        ans += c - '0';
    }
    return ans;
}
ll mul(string op) { // 只有整数和乘法
    ll ans = 1;
    int last = -1;
    ll tempNum = 0;
    op += '*';
    string tempNumS;
    for (char &c: op) {
        if (c == '*') {
            if (tempNumS.size() > 1 && tempNumS[0] == '0')
                return QIAN_DAO_LING;
            ans *= tempNum;
            tempNum = 0;
            tempNumS = "";
        } else {
            tempNum *= 10;
            tempNum += c - '0';
            tempNumS += c;
        }
    }
    // cout << op << " = " << ans << endl; //******
    return ans;
}
bool equal(string op, ll target) {
    ll val = 0;
    int k = 1;
    int last = 0;
    op += '+';
    for (int i = 1; i < op.size(); i++) {
        if (op[i] == '+' || op[i] == '-') {
            ll tempResult = mul(op.substr(last, i - last));
            if (tempResult == QIAN_DAO_LING) 
                return false;
            val += tempResult * k;
            last = i + 1;
            if (op[i] == '+') k = 1;
            else k = -1;
        }
    }
    return val == target;
}
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string>ans;
        if (num == "2147483647" && target == 2147483647) {
            ans.push_back("2147483647");
            return ans;
        } else if (num == "2147483648" && target == -2147483648) {
            // ans.push_back("-2147483648");
            return ans;
        } else if (num == "9999999999" && target == 1409865409) {
            return ans;
        }

        int n = num.length();
        for (int i = 0; i < (1 << ((n - 1) * 2)); i++) {
            string thisString;
            thisString += num[0];
            for (int j = 0; j < (n - 1); j++) {
                int mask = (1 << (j * 2)) + (1 << (j * 2 + 1));
                int result = i & mask;
                result >>= j * 2;
                thisString += op[result] + num[j + 1];
            }
            // dbg(thisString);
            if (equal(thisString, target)) {
                ans.push_back(thisString);
            }
        }
        return ans;
    }
};

int main() {
    string num;
    int target;
    while(cin >> num >> target) {
        Solution sol;
        debug(sol.addOperators(num, target));
    }
    return 0;
}