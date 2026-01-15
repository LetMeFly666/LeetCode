/*
 * @Author: LetMeFly
 * @Date: 2026-01-15 10:07:02
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-15 10:20:39
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int getMaxDiff(vector<int>& v) {
        int last = 1, cnt = 1, ans = 1;
        for (int t : v) {
            if (t == last + 1) {
                cnt++;
                last++;
            } else {
                ans = max(ans, cnt);
                cnt = 2;
                last = t;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int side = min(getMaxDiff(hBars), getMaxDiff(vBars));
        return side * side;
    }

    int testGetMaxDiff(vector<int>& v) {
        return getMaxDiff(v);
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
[2]
[3]
[2,3,4,5]
*/
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        vector<int> v = stringToVector(s);
        cout << sol.testGetMaxDiff(v) << endl;
    }
    return 0;
}
#endif