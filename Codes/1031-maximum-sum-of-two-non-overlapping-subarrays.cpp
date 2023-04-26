/*
 * @Author: LetMeFly
 * @Date: 2023-04-26 12:39:36
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-04-26 12:52:34
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int calculate1(vector<int>& a, int ll, int lr) {  // a, len l, len r
        int sl = accumulate(a.begin(), a.begin() + ll, 0);  // sum l
        int sr = accumulate(a.begin() + ll, a.begin() + ll + lr, 0);  // sum r
        int ml = sl, ans = sl + sr;  // max l, ans
        for (int l = ll, r = ll + lr; r < a.size(); l++, r++) {
            sl = sl + a[l] - a[l - ll];
            sr = sr + a[r] - a[r - lr];
            ml = max(ml, sl);
            ans = max(ans, ml + sr);
        }
        return ans;
    }
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(calculate1(nums, firstLen, secondLen), calculate1(nums, secondLen, firstLen));
    }
};

#ifdef _WIN32
/*
[0,6,5,2,2,5,1,9,4]
1
2

*/
int main() {
    string s;
    int a, b;
    while (cin >> s >> a >> b) {
        vector<int> v = stringToVector(s);
        Solution sol;
        cout << sol.maxSumTwoNoOverlap(v, a, b) << endl;
    }
    return 0;
}
#endif