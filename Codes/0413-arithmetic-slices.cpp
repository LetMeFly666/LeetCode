/*
 * @Author: LetMeFly
 * @Date: 2021-08-10 11:11:34
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-10 11:14:20
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
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int ans=0;
        for(int i=0;i+2<nums.size();i++)
        {
            int diff=nums[i+1]-nums[i];
            for(int j=i+2;j<nums.size();j++)
            {
                if(nums[j]-nums[j-1]==diff)ans++;
                else break;
            }
        }
        return ans;
    }
};