/*
 * @Author: LetMeFly
 * @Date: 2026-05-12 16:30:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-12 16:36:57
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] - a[0] > b[1] - b[0];
        });
        int ans = 0, now = 0;
        for (vector<int>& task : tasks) {
            if (now < task[1]) {
                int need = task[1] - now;
                now = task[1];
                ans += need;
            }
            now -= task[0];
        }
        return ans;
    }
};

#ifdef _DEBUG
/*
[[1,2],[2,4],[4,8]]

8
*/
int main() {
    string s;
    while (cin >> s) {
        vector<vector<int>> v = stringToVectorVector(s);
        Solution sol;
        cout << sol.minimumEffort(v) << endl;
    }
    return 0;
}
#endif