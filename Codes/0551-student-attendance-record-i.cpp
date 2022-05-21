/*
 * @Author: LetMeFly
 * @Date: 2021-08-17 08:30:58
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-17 08:33:31
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
    bool checkRecord(string s)
    {
        int sA=0;
        int n=s.size();
        fi(i,0,n)
        {
            sA+=s[i]=='A';
        }
        if(sA>1)return false;
        fi(i,2,n)
        {
            if(s[i]=='L'&&s[i-1]=='L'&&s[i-2]=='L')
            {
                return false;
            }
        }
        return true;
    }
};