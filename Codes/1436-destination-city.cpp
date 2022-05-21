/*
 * @Author: LetMeFly
 * @Date: 2021-10-01 20:44:22
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-10-01 20:50:53
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, int>ma;
        for(auto &thisP : paths) {
            ma[thisP[0]]+=2;
            ma[thisP[1]]++;
        }
        for(auto it = ma.begin(); it!=ma.end(); it++) {
            if (it->second < 2) {
                return it -> first;
            }
        }
        return "";
    }
};