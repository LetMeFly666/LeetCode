/*
 * @Author: LetMeFly
 * @Date: 2021-09-21 16:11:22
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-09-21 16:13:59
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
    int lengthOfLastWord(string s)
    {
        s = ' '+s+' ';
        int begin, end;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]!=' '&&s[i-1]==' ') begin = i;
            if(s[i]==' '&&s[i-1]!=' ') end = i;
        }
        return end - begin;
    }
};