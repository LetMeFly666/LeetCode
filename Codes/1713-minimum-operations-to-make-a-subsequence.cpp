/*
 * @Author: LetMeFly
 * @Date: 2021-07-26 09:59:11
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-07-26 10:25:51
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
int d[100010];

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

class Solution
{
public:
    int minOperations(vector<int> &target, vector<int> &nums)
    {
        map<int,int>loc;
        for(int i=0;i<target.size();i++)
        {
            loc[target[i]]=i;
        }
        int len=0;
        int i;
        for(i=0;i<nums.size();i++)
        {
            if(loc.count(nums[i]))
            {
                d[len]=loc[nums[i]];
                len++;
                break;
            }
        }
        for(i++;i<nums.size();i++)
        {
            if(loc.count(nums[i]))
            {
                int thisNum=loc[nums[i]];
                if(thisNum>d[len-1])
                {
                    d[len]=thisNum;
                    len++;
                }
                else
                {
                    int *it=lower_bound(d, d+len, thisNum);
                    *it=thisNum;
                }                
            }
        }
        return target.size()-len;
    }
};

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    vector<int>v1=stringToVector(s1);
    vector<int>v2=stringToVector(s2);
    Solution sol;
    cout<<sol.minOperations(v1, v2)<<endl;
    system("pause");
    return 0;
}