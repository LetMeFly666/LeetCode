/*
 * @Author: LetMeFly
 * @Date: 2022-07-28 10:42:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-28 10:46:31
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
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> toSort = arr;
        sort(toSort.begin(), toSort.end());
        unordered_map<int, int> ma;
        int th = 0;
        int last = -1e9 - 1;
        for (int i = 0; i < toSort.size(); i++) {
            if (toSort[i] == last)
                continue;
            ma[toSort[i]] = ++th;
            last = toSort[i];
        }
        for (int& t : arr) {
            t = ma[t];
        }
        return arr;
    }
};