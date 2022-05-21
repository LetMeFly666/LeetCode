/*
 * @Author: LetMeFly
 * @Date: 2021-08-25 13:59:55
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-25 14:19:23
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
const int mod = 1000000007;
class Solution
{
public:
    int purchasePlans(vector<int> &nums, int target)
    {
        sort(nums.begin(),nums.end());
        ll ans=0;
        int n=nums.size();
        for(int i=0;i+1<n;i++) // 1 2 2 9
        {
            vector<int>::iterator it=lower_bound(nums.begin()+i+1,nums.end(),target-nums[i]+1);
            ans = (ans + it-nums.begin()-i-1) % mod;
        }
        return ans;
    }
};

void debug(vector<int>v)
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

vector<int> stringToVector(string s)
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

int main()
{
    string s;
    int target;
    while(cin>>s>>target)
    {
        vector<int>v=stringToVector(s);
        Solution sol;
        cout << sol.purchasePlans(v,target)<<endl;
    }
    return 0;
}