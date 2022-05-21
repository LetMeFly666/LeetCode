/*
 * @Author: LetMeFly
 * @Date: 2021-08-20 08:50:34
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-20 09:11:59
 */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
void reverse_(string &s, int from, int to)
{
    // printf("from = %d, to = %d \n",from, to); //********
    for(int i=from;i<=from+(to-from)/2;i++)
    {
        // printf("swap(s[%d],s[%d])\n",i,to-i); //*************
        swap(s[i],s[from+to-i]);
        // dbg(s); //**************
    }
}
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int n=s.size();
        int from=0;
        while(from<n)
        {
            int to=min(from+k-1,n-1);
            reverse_(s,from,to);
            from=to+k+1;
        }
        return s;
    }
};

int main()
{
    string s;
    int k;
    while(cin>>s>>k)
    {
        Solution sol;
        cout<<sol.reverseStr(s,k)<<endl;
    }
    return 0;
}