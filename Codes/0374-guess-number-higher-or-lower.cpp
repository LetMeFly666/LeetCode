/*
 * @Author: LetMeFly
 * @Date: 2021-06-14 09:24:03
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-06-14 09:37:55
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
int pick;
int guess(int num)
{
    if(pick<num)return -1;
    else if(pick>num)return 1;
    else return 0;
}
// Begin
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        unsigned int l=1,r=(unsigned int)n+1;
        while(1)
        {
            int mid=(l+r)>>1;
            int t=guess(mid);
            if(!t)return mid;
            if(t==1)l=mid+1;
            else r=mid;
        }
    }
};
// End
int main()
{
    int n;
    cin>>n>>pick;
    Solution sol;
    cout<<sol.guessNumber(n)<<endl;
    system("pause");
    return 0;
}