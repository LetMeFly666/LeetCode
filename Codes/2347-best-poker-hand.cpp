/*
 * @Author: LetMeFly
 * @Date: 2023-02-20 07:55:51
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-02-20 08:03:36
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        if (suits[0] == suits[1] && suits[1] == suits[2] && suits[2] == suits[3] && suits[3] == suits[4])
            return "Flush";
        sort(ranks.begin(), ranks.end());
        int maxSame = 1, theSame = 1;
        for (int i = 1; i < 5; i++) {
            if (ranks[i] == ranks[i - 1]) {
                theSame++;
                maxSame = max(maxSame, theSame);
            }
            else {
                theSame = 1;  // 自成一派
            }
        }
        if (maxSame >= 3)  // 不是theSame
            return "Three of a Kind";  // 注意K是大写
        if (maxSame == 2)
            return "Pair";
        return "High Card";
    }
};

#ifdef _WIN32
/*
[10,10,2,12,9]
["a","b","c","a","d"]

*/
int main() {
    string a, b;
    while (cin >> a >> b) {
        vector<int> va = stringToVector(a);
        vector<char> vb = stringToVectorC(b);
        Solution sol;
        cout << sol.bestHand(va, vb) << endl;
    }
    return 0;
}
#endif