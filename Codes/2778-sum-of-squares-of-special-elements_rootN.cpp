/*
 * @Author: LetMeFly
 * @Date: 2026-10-11 09:11:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-11 09:21:22
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans = 0;
        size_t n = nums.size();
        size_t root = sqrt(n);
        for (int i = 1; i <= root; i++) {
            if (n % i == 0) {
                ans += nums[i - 1] * nums[i - 1] + nums[n / i - 1] * nums[n / i - 1];
            }
        }
        if (root * root == n) {
            ans -= nums[root - 1] * nums[root - 1];
        }
        return ans;
    }
};

#ifdef _DEBUG
/*
[1,2,3,4]

21
*/
int main() {
    string s;
    while (cin >> s) {
        vector<int> v = stringToVector(s);
        Solution sol;
        cout << sol.sumOfSquares(v) << endl;
    }
    return 0;
}
#endif

