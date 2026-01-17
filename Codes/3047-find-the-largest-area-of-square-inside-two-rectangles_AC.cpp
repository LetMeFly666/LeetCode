/*
 * @Author: LetMeFly
 * @Date: 2026-01-17 19:45:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-17 19:55:20
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;

class Solution {
private:
    // a->b VS c->d
    ll getDiff(int a, int b, int c, int d) {
        if (a > c) {
            swap(a, c);
            swap(b, d);
        }
        if (c > b) {
            return 0;
        }
        return min(b, d) - c;
    }
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        ll ans = 0;
        for (int i = 0; i < bottomLeft.size(); i++) {
            for (int j = i + 1; j < bottomLeft.size(); j++) {
                ll dx = getDiff(bottomLeft[i][0], topRight[i][0], bottomLeft[j][0], topRight[j][0]);
                ll dy = getDiff(bottomLeft[i][1], topRight[i][1], bottomLeft[j][1], topRight[j][1]);
                ans = max(ans, min(dx, dy) * min(dx, dy));
            }
        }
        return ans;
    }
};


#if defined(_WIN32) || defined(__APPLE__)
/*
[[1,1],[2,2],[3,1]]
[[3,3],[4,4],[6,6]]

1
*/
int main() {
    string a, b;
    while (cin >> a >> b) {
        vector<vector<int>> va = stringToVectorVector(a);
        vector<vector<int>> vb = stringToVectorVector(b);
        Solution sol;
        cout << sol.largestSquareArea(va, vb) << endl;
    }
    return 0;
}
#endif