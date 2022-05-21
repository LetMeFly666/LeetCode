/*
 * @Author: LetMeFly
 * @Date: 2021-08-04 11:17:20
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-04 12:50:11
 */
// /*
//  * @Author: LetMeFly
//  * @Date: 2021-08-04 11:17:20
//  * @LastEditors: LetMeFly
//  * @LastEditTime: 2021-08-04 11:29:54
//  */
// #include <bits/stdc++.h>
// using namespace std;
// #define mem(a) memset(a, 0, sizeof(a))
// #define dbg(x) cout << #x << " = " << x << endl
// #define fi(i, l, r) for (int i = l; i < r; i++)
// #define cd(a) scanf("%d", &a)
// typedef long long ll;
// int getNum(int a[], int m, int M)
// {
//     M=min(M,1000);
//     m=max(m,1);
//     return max(a[M]-a[0],a[1000]-a[m-1]);
// }
// class Solution
// {
// public:
//     int triangleNumber(vector<int> &nums)
//     {
//         int a[1010]={0};
//         for(int i=0;i<nums.size();i++)
//         {
//             a[nums[i]]++;
//         }
//         a[0]=0; // 数组里有长度为0的数，直接舍去即可。
//         fi(i,1,1001)a[i]+=a[i-1];
//         int ans=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             for(int j=i+1;j<nums.size();j++)
//             {
//                 int M=a[i]+a[j];
//                 int m=abs(a[i]-a[j]);
//                 ans+=getNum(a,m,M);
//             }
//         }
//         return ans;
//     }
// };

/*
 * @Author: LetMeFly
 * @Date: 2021-08-04 11:17:20
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-04 11:29:54
 */
// #include <bits/stdc++.h>
// using namespace std;
// #define mem(a) memset(a, 0, sizeof(a))
// #define dbg(x) cout << #x << " = " << x << endl
// #define fi(i, l, r) for (int i = l; i < r; i++)
// #define cd(a) scanf("%d", &a)
// typedef long long ll;

// void debug(vector<int>v)
// {
//     for(int i=0;i<v.size();i++)
//     {
//         cout<<v[i]<<' ';
//     }
//     puts("");
// }

// vector<string> split(string toSplit, char c)  // 将字符串以字符c为间隔分开
// {
//     vector<string> ans;
//     toSplit+=c;
//     int left=0;
//     for(int right=0;right<toSplit.size();right++)
//     {
//         if(toSplit[right]==c)  //left->right-1
//         {
//             ans.push_back(toSplit.substr(left,right-left));
//             left=right+1;
//         }
//     }
//     return ans;
// }

// vector<int> stringToVector(string s)
// {
//     vector<int>v;
//     s=s.substr(1, s.size()).substr(0, s.size()-1);
//     vector<string>vs=split(s, ',');
//     for(int i=0;i<vs.size();i++)
//     {
//         string temp=vs[i];
//         int t;
//         sscanf(temp.c_str(), "%d", &t);
//         v.push_back(t);
//     }
//     return v;
// }

// void testForStringToVector()
// {
//     string s;
//     while(cin>>s)
//     {
//         debug(stringToVector(s));
//     }
//     exit(0);
// }

// int getNum(int a[], int from, int M)
// {
//     M=min(M,1000);
//     return a[M]-a[from-1];
// }
// void debug(int a[], int n)
// {
//     for(int i=0;i<n;i++)
//         cout<<a[i]<<' ';
//     puts("");
// }
// class Solution
// {
// public:
//     int triangleNumber(vector<int> &nums)
//     {
//         int a[1010]={0};
//         for(int i=0;i<nums.size();i++)
//         {
//             a[nums[i]]++;
//         }
//         a[0]=0; // 数组里有长度为0的数，直接舍去即可。
//         fi(i,1,1001)a[i]+=a[i-1];
//         int ans=0;
//         sort(nums.begin(),nums.end());
//         debug(a,1001);
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i]==0)continue;
//             for(int j=i+1;j<nums.size();j++)
//             {
//                 if(nums[j]==0)continue;
//                 int M=a[i]+a[j]-1;
//                 ans+=getNum(a,j,M);
//             }
//         }
//         return ans;
//     }
// };

// int main()
// {
//     string s;
//     cin>>s;
//     vector<int>v=stringToVector(s);
//     Solution sol;
//     cout<<sol.triangleNumber(v)<<endl;
//     system("pause");
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

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

void debug(int a[], int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    puts("");
}
class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)continue;
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]==0)continue;
                int M=nums[i]+nums[j]-1;
                int toAdd = upper_bound(nums.begin()+j+1,nums.end(),M)-nums.begin()-j-1;
                ans+=toAdd;
            }
        }
        return ans;
    }
};

int main()
{
    string s;
    cin>>s;
    vector<int>v=stringToVector(s);
    Solution sol;
    cout<<sol.triangleNumber(v)<<endl;
    system("pause");
    return 0;
}