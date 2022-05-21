/*
 * @Author: LetMeFly
 * @Date: 2022-01-18 08:19:12
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-01-18 08:26:42
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
template<class Type>
void debug(vector<Type>v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<' ';
    }
    puts("");
}
#endif

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // debug(timePoints);//********
        vector<int> mins/*(timePoints.size())*/;
        for (string& s : timePoints) {
            mins.push_back((s[0] - '0') * 600 + (s[1] - '0') * 60 + (s[3] - '0') * 10 + (s[4] - '0'));
        }
        sort(mins.begin(), mins.end());
        mins.push_back(mins[0] + 60 * 24);
        int m = 60 * 24;
        for (int i = 1; i < mins.size(); i++) {
            m = min(m, mins[i] - mins[i - 1]);
            // printf("i = %d, m = %d\n", i, m);
        }
        return m;
    }
};