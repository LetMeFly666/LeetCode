/*
 * @Author: LetMeFly
 * @Date: 2021-12-03 08:18:01
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-12-03 08:23:31
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
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int loc = 0;
        while (k > 0 && loc < nums.size()) {
            if (nums[loc] < 0) {
                nums[loc++] = -nums[loc];
                k--;
            }
            else {
                break;
            }
        }
        int ans = 0;
        for (int& t : nums)
            ans += t;
        dbg(ans); //**********
        if (k % 2 == 1) {
            int m = 1000;
            for (int& t : nums) {
                m = min(m, t);
            }
            ans -= m * 2;
        }
        dbg(ans); //*********
        return ans;
    }
};