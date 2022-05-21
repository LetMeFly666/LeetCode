/*
 * @Author: LetMeFly
 * @Date: 2021-09-12 19:37:17
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-09-12 19:51:49
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

/*
"(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())"

"(((((*(((*********)((*(((((****"

*/

class Solution
{
// private:
//     bool could(string s)
//     {
        
//     }
public:
    bool checkValidString(string s)
    {
        int left=0, var=0;
        for(char &c:s)
        {
            if(c=='(')left++;
            else if(c=='*')var++;
            else left--;
            if(left<0)
            {
                if(var>0)
                {
                    var--;
                    left++;
                }
                else
                {
                    return false;
                }
            }
        }
        if(left>var)return false;
        int right=0;
        var=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            char c=s[i];
            if(c==')')right++;
            else if(c=='*')var++;
            else right--;
            if(right<0)
                if(var>0)
                    var--,right++;
                else return false;
        }
        return right<=var;
    }
};