/*
 * @Author: LetMeFly
 * @Date: 2021-12-05 13:58:40
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-12-05 14:11:57
 */
#include "_[1,2]toVector.h"

typedef long long ll;
class Solution {
private:
    static const int mod = 1337;
    int P(ll a, int p) {
        int ans = 1;
        while (p--) {
            ans = (ans * a) % mod;
        }
        return ans;
    }
public:
    int superPow(int a, vector<int>& b) {
        int ans = 1;
        for (int& t: b) {
            ans = P(ans, 10);
            // dbg(ans);
            ans = ans * P(a, t) % mod;
            // dbg(ans);
        }
        return ans;
    }
};

int main() {
    int a;
    string b;
    while (cin >> a >> b) {
        vector<int> v = stringToVector(b);
        Solution sol;
        cout << sol.superPow(a, v) << endl;
    }
    return 0;
}

/*
2 [3]

8
*/

/*
2 [1,0]

1024
*/

/*
1 [4,3,3,8,5,2]

1
*/

/*
2147483647 [2,0,0]

1198
*/