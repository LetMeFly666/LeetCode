/*
 * @Author: LetMeFly
 * @Date: 2021-08-09 14:00:08
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-09 14:08:49
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
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        priority_queue<ll,vector<ll>,greater<ll> >q;
        unordered_set<ll>s;
        s.insert(1),q.push(1);
        ll ans=1;
        fi(i,0,n)
        {
            ans=q.top();
            q.pop();
            for(ll prime:primes)
            {
                ll thisNum=ans*prime;
                if(s.insert(thisNum).second){
                    q.push(thisNum);
                }
            }
        }
        return ans;
    }
};