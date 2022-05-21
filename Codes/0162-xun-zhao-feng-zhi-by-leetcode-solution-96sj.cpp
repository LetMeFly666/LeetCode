/*
 * @Author: LetMeFly
 * @Date: 2021-09-15 18:46:08
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-09-15 18:49:46
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
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        if(nums[0]>nums[1])return 0;
        if(nums[n-1]>nums[n-2])return n-1;
        for(int i=1;i<n-1;i++) {
            if(nums[i]>nums[i-1]&&nums[i]>nums[i+1]) {
                return i;
            }
        }
        return -1;
    }
};