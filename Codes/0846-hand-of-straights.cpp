/*
 * @Author: LetMeFly
 * @Date: 2021-12-30 08:43:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-12-30 08:53:34
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
[1,2,3,6,2,3,4,7,8]
3

*/

/*
[1,2,2,3,3,4,6,7,8]
3

*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> ma;
        for (int& t : hand)
            ma[t]++;
        int remain = hand.size();
        while (remain) {
            int first = ma.begin()->first;
            for (int i = 0; i < groupSize; i++) {
                if (!ma[first]) {
                    return false;
                }
                ma[first]--;
                // if (!ma[first]) 
                //     ma.erase(first);
                first++, remain--;
            }
        }
        return true;
    }
};

#ifdef _WIN32
int main() {
    string s;
    int t;
    while (cin >> s >> t) {
        Solution sol;
        vector<int> v = stringToVector(s);
        cout << sol.isNStraightHand(v, t) << endl;
    }
    return 0;
}
#endif