/*
 * @Author: LetMeFly
 * @Date: 2021-11-06 16:04:51
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-11-06 16:06:02
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
    int missingNumber(vector<int>& nums) {
        set<int> se;
        for (int i = nums.size(); i >= 0; i--) {
            se.insert(i);
        }
        for (int &t : nums) {
            se.erase(se.find(t));
        }
        return *se.begin();
    }
};