/*
 * @Author: LetMeFly
 * @Date: 2021-10-15 17:37:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-10-15 17:37:50
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
    int peakIndexInMountainArray(vector<int>& arr) {
        int M = 0;
        int loc = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > M) {
                M = arr[i];
                loc = i;
            }
        }
        return loc;
    }
};