/*
 * @Author: LetMeFly
 * @Date: 2025-08-11 18:41:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-11 18:55:02
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> pows;
        int th = 0;
        while (n) {
            if (n & 1) {
                pows.push_back(1 << th);
            }
            n >>= 1;
            th++;
        }
        vector<ll> perfix(pows.size() + 1);
        perfix[0] = 1;  // query是相乘不是相加
        for (int i = 0; i < pows.size(); i++) {
            perfix[i + 1] = perfix[i] * pows[i];
        }
        // debug(pows);
        // debug(perfix);
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = perfix[queries[i][1] + 1] / perfix[queries[i][0]];
        }
        return ans;
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
15
[[0,1],[2,2],[0,3]]

[2,4,64]
*/
int main() {
    int n;
    string s;
    while (cin >> n >> s) {
        vector<vector<int>> q = stringToVectorVector(s);
        Solution sol;
        debug(sol.productQueries(n, q));
    }
    return 0;
}
#endif