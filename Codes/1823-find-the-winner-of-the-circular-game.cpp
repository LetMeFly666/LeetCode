/*
 * @Author: LetMeFly
 * @Date: 2022-05-04 08:43:31
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-04 08:58:26
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
#define dbg(x) cout << #x << " : " << x << endl
#endif

class Solution {
public:
    int findTheWinner(int n, int k) {
        int remain = n;
        vector<bool> visited(n, false);
        int loc = 0;
        while (remain > 1) {
            int thisCnt = 0;
            while (true) {
                if (!visited[loc])
                    thisCnt++;
                if (thisCnt == k) {
                    visited[loc] = true;
                    break;
                }
                loc = (loc + 1) % n;
            }
            remain--;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return i + 1;
            }
        }
        return -1;  // Fake Return
    }
};

#ifdef _WIN32
int main() {
    int n, k;
    while (cin >> n >> k) {
        Solution sol;
        cout << sol.findTheWinner(n, k) << endl;
    }
    return 0;
}
#endif