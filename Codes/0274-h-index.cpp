/*
 * @Author: LetMeFly
 * @Date: 2021-07-11 13:31:02
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-07-11 13:37:41
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

//Begin: ----------------------------
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end(), greater<int>());
        int l=citations.size();
        for (int i=0;i<l;i++)
        {
            if (citations[i] < i + 1)
                return i;
        }
        return l;
    }
};
//End: ------------------------------

int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        v.push_back(t);
    }
    Solution sol;
    cout << sol.hIndex(v) << endl;
    system("pause");
    return 0;
}