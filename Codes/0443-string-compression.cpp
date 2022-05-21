/*
 * @Author: LetMeFly
 * @Date: 2021-08-21 08:43:22
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-21 09:19:59
 */
// /*
//  * @Author: LetMeFly
//  * @Date: 2021-08-21 08:43:22
//  * @LastEditors: LetMeFly
//  * @LastEditTime: 2021-08-21 08:50:58
//  */
// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;
// #define mem(a) memset(a, 0, sizeof(a))
// #define dbg(x) cout << #x << " = " << x << endl
// #define fi(i, l, r) for (int i = l; i < r; i++)
// #define cd(a) scanf("%d", &a)
// typedef long long ll;
// int itoi(int n)
// {
//     // if(!n)return 1;
//     int ans=0;
//     while(n)
//     {
//         n/=10;
//         ans++;
//     }
//     return ans;
// }
// class Solution
// {
// public:
//     int compress(vector<char> &chars)
//     {
//         int ans=0;
//         int lastChar=chars[0];
//         int lastLoc=-1;
//         chars.push_back(chars[chars.size()-1]=='a'?'b':'a');
//         for(int i=1;i<chars.size();i++)
//             if(chars[i]!=lastChar)
//                 ans+=1+itoi(i-lastLoc),lastLoc=i;
//         return ans;
//     }
// };

#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
string itos(int n) // n>0
{
    string ans;
    if(n==1)return ans;
    while(n)
    {
        char thisBit=n%10+'0';
        ans=thisBit+ans;
        n/=10;
    }
    return ans;
}
void debug(vector<char>&v)
{
    printf("len=%d :",v.size());
    for(char &c:v)
        putchar(c);
    puts("");
}
class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int writeToLoc=0;
        int lastCharLoc=0;
        chars.push_back(chars[chars.size()-1]=='a'?'b':'a');
        // debug(chars); //******
        for(int i=1;i<chars.size();i++)
        {
            // dbg(i); //****************
            if(chars[i]!=chars[i-1])
            {
                chars[writeToLoc++]=chars[lastCharLoc];
                for(auto &c:itos(i-lastCharLoc))
                    chars[writeToLoc++]=c;
                // debug(chars); //*************
                lastCharLoc=i;
            }
        }
        while(chars.size()>writeToLoc)
            chars.erase(--chars.end());
        // debug(chars); //*************
        // return chars.size();
        return writeToLoc;
    }
};

int main()
{
    string s;
    while(cin>>s)
    {
        vector<char>v;
        for(char &c:s)
            v.push_back(c);
        Solution sol;
        cout<<sol.compress(v)<<endl;
        for(char &c:v)
            putchar(c);
        puts("");
    }
    return 0;
}