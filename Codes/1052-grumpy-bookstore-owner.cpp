/*
 * @Author: LetMeFly
 * @Date: 2024-04-23 11:57:19
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-23 12:33:40
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int thisAns = 0;
        for (int i = 0; i < minutes; i++) {
            thisAns += customers[i];
        }
        for (int i = minutes; i < customers.size(); i++) {
            if (!grumpy[i]) {
                thisAns += customers[i];
            }
        }
        int ans = thisAns;
        for (int r = minutes; r < customers.size(); r++) {
            if (grumpy[r]) {  // 1 -> 0
                thisAns += customers[r];
            }
            if (grumpy[r - minutes]) {  // 0 -> 1
                thisAns -= customers[r - minutes];
            }
            ans = max(ans, thisAns);
            // printf("[%d -> %d] -> %d\n", r - minutes + 1, r, thisAns);  //*************
        }
        return ans;
    }
};

#ifdef _WIN32
/*
[1,0,1,2,1,1,7,5]
[0,1,0,1,0,1,0,1]
3

*/
int main() {
    string a, b;
    int c;
    while (cin >> a >> b >> c) {
        vector<int> va = stringToVector(a), vb = stringToVector(b);
        Solution sol;
        cout << sol.maxSatisfied(va, vb, c) << endl;
    }
    return 0;
}
#endif