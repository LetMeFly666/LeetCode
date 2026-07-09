/*
 * @Author: LetMeFly
 * @Date: 2026-07-08 13:35:37
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-08 14:18:15
 */
#include <bits/stdc++.h>
using namespace std;

/*
这个文件的前面几个 split、stringToVector、stringToVectorVector函数copy自"_[1,2]toVector.h"
*/

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

/*
1234567890123456 % 1000000007
1234567000000000 % 1000000007 + 890123456 % 1000000007


123456
  __

34 = 1234 - 12 * 10^2 其中2是lr之间非零数的个数
*/
#define debug_(x) { cout << #x << ": "; debug3756(x); cout << endl; }
typedef long long ll;
const int N = 100000;
const ll MOD = 139 + 7;
ll p[N + 1] = {1};
int _ = []{
    for (int i = 1; i <= N; i++) {
        p[i] = p[i - 1] * 10 % MOD;
    }
    return 0;
}();

template<class Type>
void debug3756(const vector<Type>& v) {
    cout << "[";
    for (int i = 0, n = v.size(); i < n; i++) {
        if (i) {
            cout << ", ";
        }
        debug3756(v[i]);
    }
    cout << "]";
}

template<class Type>
void debug3756(const Type& a) {
    cout << a;
}

class Solution {
public:
    vector<int> sumAndMultiply(string& s, vector<vector<int>>& queries) {
        vector<ll> cnt(N + 1);
        vector<ll> con(N + 1);
        vector<ll> num1(N + 1);
        for (int i = 0, n = s.size(); i < n; i++) {
            if (s[i] == '0') {
                cnt[i + 1] = cnt[i];
                con[i + 1] = con[i];
                num1[i + 1] = num1[i];
            } else {
                int v = s[i] - '0';
                cnt[i + 1] = cnt[i] + v;
                con[i + 1] = (con[i] * 10 + v) % MOD;
                num1[i + 1] = num1[i] + 1;
            }
        }
        debug_(cnt);
        debug_(con);
        debug_(num1);

        vector<int> ans;
        ans.reserve(queries.size());
        for (vector<int>& q : queries) {
            int l = q[0], r = q[1] + 1;
            ll this_cnt = cnt[r] - cnt[l];
            ll this_con = con[r] - con[l] * p[num1[r] - num1[l]] % MOD + MOD;
            ans.push_back(this_cnt * this_con % MOD);
        }
        return ans;
    }
};

/*
10203004
[[0,7],[1,3],[4,6]]

[12340,4,9]
*/
int main() {
    string a, b;
    while (cin >> a >> b) {
        vector<vector<int>> v = stringToVectorVector(b);
        Solution sol;
        debug_(sol.sumAndMultiply(a, v));
    }
    return 0;
}
