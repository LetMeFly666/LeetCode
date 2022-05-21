/*
 * @Author: LetMeFly
 * @Date: 2021-08-22 14:40:30
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-22 14:47:17
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
class Solution
{
private:
    vector<int> v;
    int distance(vector<int> &a) { return abs(a[0] - v[0]) + abs(a[1] - v[1]); }

public:
    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target){
        v = target;
        int dis = abs(target[0]) + abs(target[1]);
        for (vector<int>&v : ghosts){
            if(distance(v)<=dis)
                return false;
        }
        return true;
    }
};