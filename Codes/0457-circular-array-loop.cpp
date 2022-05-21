/*
 * @Author: LetMeFly
 * @Date: 2021-08-07 10:58:14
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-07 11:30:49
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
// bool visited[5000];
// class Solution
// {
// public:
//     bool circularArrayLoop(vector<int> &nums)
//     {
//         mem(visited);
//         int loc=0;
//         vector<int>pass;
//         while(true)
//         {
//             if(visited[loc])
//             {
//                 return
//             }
//         }
//     }
// };

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

void testForStringToVector()
{
    string s;
    while(cin>>s)
    {
        debug(stringToVector(s));
    }
    exit(0);
}
int next(int current,vector<int> &nums,int n)
{
    return (current+nums[current]%n+n)%n;
}
// 看着打的
class Solution
{
public:
    bool circularArrayLoop(vector<int> &nums)
    {
        int n=nums.size();
        // auto next=[&](int current){return (current+nums[current]%n+n)%n;};
        fi(i,0,n)
        {
            if(!nums[i])continue;
            int slow=i,fast=next(i,nums,n);
            while(nums[slow]*nums[fast]>0&&nums[slow]*nums[next(fast,nums,n)]>0)
            {
                // dbg(slow);dbg(fast); //*********
                // cout<<"slow: "<<slow<<", fast: "<<fast<<endl;//*********
                if(slow==fast)
                {
                    if(slow!=next(slow,nums,n))return true;
                    break;
                }
                slow=next(slow,nums,n),fast=next(next(fast,nums,n),nums,n);
            }
            int passed=i;
            while(nums[passed]*nums[next(passed,nums,n)]>0)
            {
                int temp=passed;
                passed=next(passed,nums,n),nums[temp]=0;
            }
        }
        return false;
    }
};

int main()
{
    string s;
    cin>>s;
    vector<int>v=stringToVector(s);
    Solution sol;
    cout<<sol.circularArrayLoop(v)<<endl;
    system("pause");
    return 0;
}