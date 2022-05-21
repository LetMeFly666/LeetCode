/*
 * @Author: LetMeFly
 * @Date: 2021-08-19 18:39:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-19 18:44:43
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
int a[300010];
char yuan[]={"aeiouAEIOU"};
bool isYuanYin(char c)
{
    for(int i=0;i<10;i++)
        if(yuan[i]==c)
            return true;
    return false;
}

class Solution
{
public:
    string reverseVowels(string s)
    {
        int nYuan=0;
        int n=s.size();
        fi(i,0,n)
            if(isYuanYin(s[i]))
                a[nYuan++]=i;
        for(int i=0;i<nYuan/2;i++)
            swap(s[a[i]],s[a[nYuan-i-1]]);
        return s;
    }
};

int main()
{
    string s;
    while(cin>>s)
    {
        Solution sol;
        cout<<sol.reverseVowels(s)<<endl;
    }
    return 0;
}