/*
 * @Author: LetMeFly
 * @Date: 2021-08-31 12:26:30
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-31 12:53:08
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

template<class Type>
void debug(vector<Type>v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<' ';
    }
    puts("");
}

vector<string> split(string toSplit, char c)  // 将字符串以字符c为间隔分开
{
    vector<string> ans;
    toSplit+=c;
    int left=0;
    for(int right=0;right<toSplit.size();right++)
    {
        if(toSplit[right]==c)  //left->right-1
        {
            ans.push_back(toSplit.substr(left,right-left));
            left=right+1;
        }
    }
    return ans;
}

vector<string> split(string toSplit, string c)  // 将字符串以字符串c为间隔分开
{
    vector<string> ans;
    toSplit+=c;
    int left=0;
    for(int right=0;right<toSplit.size()-c.size()+1;right++)
    {
        if(toSplit.substr(right,c.size())==c)  //left->right-1
        {
            ans.push_back(toSplit.substr(left,right-left));
            left=right+c.size();
        }
    }
    return ans;
}

vector<int> stringToVector(string s)  // [1,2,5]
{
    vector<int>v;
    s=s.substr(1, s.size()).substr(0, s.size()-1);
    vector<string>vs=split(s, ',');
    for(int i=0;i<vs.size();i++)
    {
        string temp=vs[i];
        int t;
        sscanf(temp.c_str(), "%d", &t);
        v.push_back(t);
    }
    return v;
}

vector<vector<int>> stringToVectorVector(string s) //[[1,2,5],[2,5,6],[5,6]]
{
    vector<vector<int>>ans;
    s.erase(s.begin());
    s.erase(s.begin());
    s.erase(--s.end());
    s.erase(--s.end());
    vector<string> temp = split(s,"],[");
    for(string&s:temp)
    {
        s='['+s+']';
        ans.push_back(stringToVector(s));
    }
    return ans;
}

void testForStringToVector()
{
    string s;
    while(cin>>s)
    {
        debug(stringToVector(s));
    }
    exit(0);
}

void testForSplitS()
{
    string s,c;
    while(cin>>s>>c)
    {
        debug(split(s,c));
    }
    exit(0);
}

class Solution
{
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        vector<int>a(n+2);
        for(vector<int>&thisBook:bookings)
        {
            a[thisBook[0]]+=thisBook[2];
            a[thisBook[1]+1]-=thisBook[2];
            // debug(a); //***************
        }
        for(int i=1;i<=n;i++)
        {
            a[i]+=a[i-1];
        }
        a.erase(a.begin());
        a.erase(--a.end());
        return a;
    }
};

int main()
{
    // testForSplitS(); //*******
    string s;
    int n;
    while(cin>>s>>n)
    {
        vector<vector<int>>v=stringToVectorVector(s);
        for(vector<int>v2:v)debug(v2);
        Solution sol;
        debug(sol.corpFlightBookings(v,n));
    }
    return 0;
}