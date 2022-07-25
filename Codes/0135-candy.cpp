/*
 * @Author: LetMeFly
 * @Date: 2022-07-25 15:01:56
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-25 15:36:00
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
    int candy(vector<int>& ratings) {
        vector<int> mins;
        vector<int> candies(ratings.size());
        for (int i = 0; i < ratings.size(); i++) {
            if ((i - 1 >= 0 && ratings[i - 1] < ratings[i]) || (i + 1 < ratings.size() && ratings[i + 1] < ratings[i])) {
                continue;
            }
            mins.push_back(i);
        }
        for (int thisMin : mins) {
            int thisCandy = 1;
            int i = thisMin;
            while (true) {
                candies[i] = thisCandy;
                thisCandy++;
                if (i - 1 >= 0 && ratings[i - 1] > ratings[i]) {
                    i--;
                }
                else {
                    break;
                }
            }
            i = thisMin;
            thisCandy = 1;
            while (true) {
                candies[i] = thisCandy;
                thisCandy++;
                if (i + 1 < ratings.size() && ratings[i + 1] > ratings[i]) {
                    i++;
                }
                else {
                    break;
                }
            }
        }
        // debug(candies);  //************
        for (int i = 1; i < candies.size(); i++) {
            if (ratings[i - 1] > ratings[i] && candies[i - 1] <= candies[i]) {
                candies[i - 1] = candies[i] + 1;
            }
            if (ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        // debug(mins);  //************
        // debug(candies);  //************
        int ans = 0;
        for (int& t : candies)
            ans += t;
        return ans;
    }
};

// [1,0,2]
#ifdef _WIN32
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        vector<int> v = stringToVector(s);
        cout << sol.candy(v) << endl;
    }
    return 0;
}
#endif