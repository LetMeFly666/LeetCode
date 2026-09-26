/*
 * @Author: LetMeFly
 * @Date: 2026-07-12 10:03:34
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-12 10:23:22
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef long long ll;

const ll MOD = 1e9 + 7;
const int N = 100000;
ll p[N + 1];
int _ = []{
    p[0] = 1;
    for (int i = 1; i <= N; i++) {
        p[i] = p[i - 1] * 10 % MOD;
    }
    return 0;
}();

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> sum(n + 1);
        vector<ll> con(n + 1);
        vector<int> cnt1(n + 1);
        for (int i = 0; i < n; i++) {
            int t = s[i] - '0';
            if (!t) {
                sum[i + 1] = sum[i];
                con[i + 1] = con[i];
                cnt1[i + 1] = cnt1[i];
            } else {
                sum[i + 1] = sum[i] + t;
                con[i + 1] = (con[i] * 10 + t) % MOD;
                cnt1[i + 1] = cnt1[i] + 1;
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (vector<int>& q : queries) {
            int l = q[0], r = q[1] + 1;
            int su = sum[r] - sum[l];
            ll co = (con[r] - con[l] * p[cnt1[r] - cnt1[l]]) % MOD + MOD;
            ans.push_back(su * co % MOD);
        }
        return ans;
    }
};
