/*
 * @Author: LetMeFly
 * @Date: 2022-01-30 10:50:08
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-01-30 10:52:20
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
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
#endif

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string, int> ma;
        for (string s: split(s1, ' ')) ma[s]++;
        for (string s: split(s2, ' ')) ma[s]++;
        vector<string> ans;
        for (auto it : ma) {
            if (it.second == 1) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};