/*
 * @Author: LetMeFly
 * @Date: 2021-07-16 20:38:30
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-07-16 20:41:13
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

//----------------
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int ans = 0;
        int l=nums.size();
        for(int i=0;i<l;i++)
        {
            ans+=nums[i]==target;
        }
        return ans;
    }
};
//---------------

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>v;
    while(n--)
    {
        int t;
        cin>>t;
        v.push_back(t);
    }
    Solution sol;
    cout << sol.search(v,m) << endl;
    system("pause");
    return 0;
}