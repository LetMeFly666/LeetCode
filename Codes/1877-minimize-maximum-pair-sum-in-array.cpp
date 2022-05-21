/*
 * @Author: LetMeFly
 * @Date: 2021-07-20 17:51:52
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-07-20 17:54:04
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

//------------
class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int l=nums.size();
        int M=0;
        for(int i=0;i<l/2;i++)
            M=max(M, nums[i]+nums[l-i-1]);
        return M;
    }
};
//------------

int main()
{
    Solution sol;
    int n;
    cin >> n;
    vector<int> v;
    fi(i, 0, n)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    cout << sol.minPairSum(v) << endl;
    system("pause");
    return 0;
}