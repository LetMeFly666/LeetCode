/*
 * @Author: LetMeFly
 * @Date: 2026-06-20 10:09:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-20 11:17:44
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

/*
从左到右限制一遍再从右到左限制一遍是不是就可以了呢？是不是不需要由较低的高度往两边限制呢？
*/
class Solution {
private:
    int cal(int a, int ha, int b, int hb) {
        if (ha > hb) {
            swap(ha, hb);
        }
        return hb + (b - a - (hb - ha)) / 2;
    }
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, INT_MAX});
        sort(restrictions.begin(), restrictions.end());
        for (int i = 1; i < restrictions.size(); i++) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + restrictions[i][0] - restrictions[i - 1][0]);
        }
        for (int i = restrictions.size() - 2; i >= 0; i--) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + restrictions[i + 1][0] - restrictions[i][0]);
        }
        
        int ans = 0;
        for (int i = 1; i < restrictions.size(); i++) {
            ans = max(ans, cal(restrictions[i - 1][0], restrictions[i - 1][1], restrictions[i][0], restrictions[i][1]));
        }
        return ans;
    }

    void testCal() {
        assert(cal(7, 3, 10, 4) == 5);
        assert(cal(7, 4, 10, 3) == 5);
    }
};

#ifdef _DEBUG
/*
10
[[5,3],[2,5],[7,4],[10,3]]

5
*/
int main() {
    int a;
    string s;
    Solution sol;
    sol.testCal();
    while (cin >> a >> s) {
        vector<vector<int>> v = stringToVectorVector(s);
        Solution sol;
        cout << sol.maxBuilding(a, v) << endl;
    }
    return 0;
}
#endif
