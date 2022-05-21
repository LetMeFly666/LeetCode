/*
 * @Author: LetMeFly
 * @Date: 2021-08-29 13:47:03
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-29 13:52:25
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
int findFirst(string&s, int l,int r, char c) // [l,r)
{
    for(int i=l;i<r;i++)
        if(s[i]==c)
            return i;
    return -1;
}
int findLast(string &s, int r, int l, char c) // [r->l]
{
    for(int i=r;i>=l;i--)
        if(s[i]==c)
            return i;
    return -1;
}
int main()
{
    string s;
    int n;
    cin>>n>>s;
    int begin=findFirst(s,findFirst(s,0,n,'M')+1,n,'T')+1;
    int end=findLast(s,findLast(s,n-1,0,'T')-1,0,'M')-1;
    for(int i=begin;i<=end;i++)
        putchar(s[i]);
    puts("");
    return 0;
}