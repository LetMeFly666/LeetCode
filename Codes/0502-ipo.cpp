/*
 * @Author: LetMeFly
 * @Date: 2021-09-08 12:13:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-09-08 12:59:25
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

// typedef pair<int,int>pii;
struct pii{
    int first, second;
    pii(int a,int b){first=a,second=b;}
};

bool operator<(pii&a, int b)
{
    return a.first<b;
}
bool operator<(pii&a, pii&b)
{
    return a.first==b.first?a.second<b.second:a.first<b.first;
}
// pii p[100010];

void debug(vector<pii>p)
{
    for(pii&thisP:p)
    {
        printf("[%d, %d], ", thisP.first, thisP.second);
    }
    printf("\b\b  \n");
}
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pii>p;
        for(int i=0;i<n;i++)
        {
            // p[i]=pii(capital[i], profits[i]);
            p.emplace_back(capital[i], profits[i]);
        }
        sort(p.begin(),p.end());
        k = min(k, int(p.size()));
        while(k--)
        {
            debug(p); //*******************
            printf("w = %d\n", w); //************
            vector<pii>::iterator it=lower_bound(p.begin(), p.end(), w+1);
            printf("*it: %d --> ",it-p.begin()); //*****************
            it--;
            printf("%d\n",it-p.begin()); //***************
            if(it < p.begin()) break;
            if ((*it).first > w) break;
            w += (*it).second;
            p.erase(it);
        }
        return w;
    }
};

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

int main()
{
    int k,w;
    while(cin>>k>>w)
    {
        string s1,s2;
        cin>>s1>>s2;
        vector<int> v1=stringToVector(s1);
        vector<int> v2=stringToVector(s2);
        Solution sol;
        cout<<sol.findMaximizedCapital(k,w,v1,v2)<<endl;
    }
    return 0;
}

/*
// FWb
typedef pair<int,int> pii;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        int curr = 0;
        priority_queue<int, vector<int>, less<int>> pq;
        vector<pii> arr;

        for (int i = 0; i < n; ++i) {
            arr.push_back({capital[i], profits[i]});
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < k; ++i) {
            while (curr < n && arr[curr].first <= w) {
                pq.push(arr[curr].second);
                curr++;
            }
            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            } else {
                break;
            }
        }

        return w;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/ipo/solution/ipo-by-leetcode-solution-89zm/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/