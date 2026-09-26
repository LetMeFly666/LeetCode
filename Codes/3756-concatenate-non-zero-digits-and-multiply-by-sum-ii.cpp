/*
 * @Author: LetMeFly
 * @Date: 2026-07-08 13:35:37
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-08 14:28:42
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

/*
1234567890123456 % 1000000007
1234567000000000 % 1000000007 + 890123456 % 1000000007


123456
  __

34 = 1234 - 12 * 10^2 其中2是lr之间非零数的个数
*/
#define debug_(x) { cout << #x << ": "; debug3756(x); cout << endl; }
typedef long long ll;
const int N = 100000;
const ll MOD = 1e9 + 7;
ll p[N + 1] = {1};
int _ = []{
    for (int i = 1; i <= N; i++) {
        p[i] = p[i - 1] * 10 % MOD;
    }
    return 0;
}();

template<class Type>
void debug3756(const Type& a) {
    cout << a;
}

template<class Type>
void debug3756(const vector<Type>& v) {
    cout << "[";
    for (int i = 0, n = v.size(); i < n; i++) {
        if (i) {
            cout << ", ";
        }
        debug3756(v[i]);
    }
    cout << "]";
}

class Solution {
public:
    vector<int> sumAndMultiply(string& s, vector<vector<int>>& queries) {
        vector<ll> cnt(s.size() + 1);
        vector<ll> con(s.size() + 1);
        vector<ll> num1(s.size() + 1);
        for (int i = 0, n = s.size(); i < n; i++) {
            if (s[i] == '0') {
                cnt[i + 1] = cnt[i];
                con[i + 1] = con[i];
                num1[i + 1] = num1[i];
            } else {
                int v = s[i] - '0';
                cnt[i + 1] = cnt[i] + v;
                con[i + 1] = (con[i] * 10 + v) % MOD;
                num1[i + 1] = num1[i] + 1;
            }
        }
        // debug_(cnt);
        // debug_(con);
        // debug_(num1);

        vector<int> ans;
        ans.reserve(queries.size());
        for (vector<int>& q : queries) {
            int l = q[0], r = q[1] + 1;
            ll this_cnt = cnt[r] - cnt[l];
            ll this_con = con[r] - con[l] * p[num1[r] - num1[l]] % MOD + MOD;
            ans.push_back(this_cnt * this_con % MOD);
        }
        return ans;
    }
};

#ifdef _DEBUG
/*
10203004
[[0,7],[1,3],[4,6]]

[12340,4,9]
*/
int main() {
    string a, b;
    while (cin >> a >> b) {
        vector<vector<int>> v = stringToVectorVector(b);
        Solution sol;
        vector<int> ans = sol.sumAndMultiply(a, v);
        debug_(ans);
    }
    return 0;
}
#endif
