/*
 * @Author: LetMeFly
 * @Date: 2021-07-15 10:32:58
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-07-15 10:38:00
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

//-----------------------
class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int M=0;
        int l=arr.size();
        for(int i=0;i<arr.size();i++)
        {
            M++;
            M=min(M, arr[i]);
        }
        return M;
    }
};
//-----------------------

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    while (n--)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    Solution sol;
    cout << sol.maximumElementAfterDecrementingAndRearranging(v) << endl;
    system("pause");
    return 0;
}