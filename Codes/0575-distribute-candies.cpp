/*
 * @Author: LetMeFly
 * @Date: 2021-11-01 15:31:23
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-11-01 15:32:27
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
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> se;
        for (int &t : candyType) {
            se.insert(t);
        }
        return min(candyType.size() / 2, se.size());
    }
};