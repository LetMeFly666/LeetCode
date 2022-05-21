/*
 * @Author: LetMeFly
 * @Date: 2022-01-09 07:58:13
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-01-09 08:14:07
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifndef _WIN32
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
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        // debug(releaseTimes); //*****
        int M = releaseTimes[0];
        char Mc = keysPressed[0];
        for (int i = 1; i < releaseTimes.size(); i++) {
            int diff = releaseTimes[i] - releaseTimes[i - 1];
            if (diff == M) {
                Mc = max(Mc, keysPressed[i]);
            }
            else if (diff > M) {
                M = diff;
                Mc = keysPressed[i];
            }
            // printf("i = %d, M = %d, Mc = %c\n", i, M, Mc); //****
        }
        return Mc;
    }
};

#ifdef _WIN32
int main() {
    string s;
    string s2;
    while (cin >> s >> s2) {
        Solution sol;
        vector<int> v = stringToVector(s);
        cout << sol.slowestKey(v, s2) << endl;
    }
    return 0;
}
#endif