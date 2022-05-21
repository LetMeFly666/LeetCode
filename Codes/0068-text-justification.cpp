/*
 * @Author: LetMeFly
 * @Date: 2021-09-09 22:28:57
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-09-09 23:48:50
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
class Solution {
private:
    string oneLine(vector<string>&s, int l,int r,int width)
    {
        printf("One Line [%d, %d]\n",l, r); //***********
        string ans;
        if(r-l+1==1)
        {
            ans=s[l];
            int toAdd=width-ans.size();
            while(toAdd--)ans += ' ';
        }
        else
        {
            int allLength=0;
            for(int i=l; i<=r;i++)
            {
                allLength+=s[i].size();
            }
            int needToSplit = width-allLength; // 需要分割的空格
            int spaceNum = r-l; // 空格的数量
            int smallSpaceNum=needToSplit/spaceNum; // 小的空格有几位
            int bigSpaceNum = smallSpaceNum + 1; // 大的空格有几位
            int bigNum = needToSplit - smallSpaceNum * spaceNum; // 大的空格的个数
            int smallNum = spaceNum - bigNum; // 小的空格的个数
            int nowSpaceNum = 0; // 现在的空格的个数
            printf("There is "); //********
            for(int i=0;i<needToSplit;i++)putchar('-'); //*********
            printf("(%d) to split into %d space in total, and have %d ",needToSplit , spaceNum, bigNum); //********
            for(int i=0;i<bigSpaceNum;i++)putchar('-'); //********
            printf("(%d) and %d ", bigSpaceNum, smallNum); //********
            for(int i=0;i<smallSpaceNum;i++)putchar('-'); //************
            printf("(%d)\n",smallSpaceNum); //************
            for(int i=l;i<r;i++)
            {
                ans+=s[i];
                int thisSpaceNum = ++nowSpaceNum <= bigNum ? bigSpaceNum : smallSpaceNum;
                while(thisSpaceNum--) ans += ' ';
            }
            ans+=s[r];
        }
        assert(ans.size() == width); //**********
        return ans;
    }

    string lastLine(vector<string>&s, int l,int r,int width)
    {
        string ans;
        dbg(l), dbg(r); //*********
        for(int i=l;i<=r;i++)
        {
            ans+=s[i];
            if(i!=r)ans+=' ';
        }
        dbg(ans); //*******
        int needToAdd = width - ans.size();
        while(needToAdd--) ans += ' ';
        return ans;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int nowL=-1;
        int lastLoc=-1;
        vector<string>ans;
        for(int i=0;i<words.size();i++)
        {
            if(nowL+words[i].size()+1<=maxWidth)
                nowL+=words[i].size()+1;
            else 
            {
                ans.push_back(oneLine(words, lastLoc+1, i-1, maxWidth));
                nowL=words[i].size(), lastLoc=i-1;
            }
        }
        dbg(lastLoc), dbg(words.size()); //**********
        if (lastLoc < int(words.size()))
        {
            puts("------"); //*****
            ans.push_back(lastLine(words, lastLoc+1, words.size()-1, maxWidth));
        }
        else
        {
            if (lastLoc < (words.size()))
            {
                puts("Shit!"); //********见鬼了
            }
            puts("************"); //*************
            printf("lastLoc = %d, words.size() = %d\n", lastLoc, words.size()); //********
            dbg((lastLoc < words.size())); //******
        }
        return ans;
    }
};

void debug(vector<string> v)
{
    for(string&s:v)
    {
        cout<<s<<endl;
    }
}

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

void newFound()
{
    string ans;
    int t=-1;
    dbg((t<ans.size()));
    dbg((t<int(ans.size())));

    for(int t=-5;t<=5;t++)
    {
        dbg(t);
        dbg((t<ans.size()));
        dbg((t<int(ans.size())));
    }

    size_t s;
    dbg(sizeof(s));
    dbg(sizeof(t));

    int i=-1;
    ll l=0;
    dbg((i<l));
}

int main()
{
    newFound(); //********

    // string s;
    // vector<string>v;
    // while(cin>>s)v.push_back(s);
    // int width;
    // cin>>width;
    // Solution sol;
    // debug(sol.fullJustify(v, width));
    // system("pause");

    string s;
    while(getline(cin,s))
    {
        if(s.size()<4)continue;
        s=s.substr(2,s.size()-2).substr(0,s.size()-4);
        vector<string>v=split(s,"\", \"");
        if(v.size()==1)v=split(s,"\",\"");
        debug(v);
        int width;
        cin>>width;
        getchar();
        Solution sol;
        debug(sol.fullJustify(v, width));
    }
    return 0;
}