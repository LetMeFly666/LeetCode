/*
 * @Author: LetMeFly
 * @Date: 2026-01-21 23:27:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-21 23:39:44
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

/*
111
11 | 100

10111 (1+2+4+16=23)
10011 | 10100   (10011:1+2+16=19)

101
100 | 101

110
101 | 110 X

10
1 | 10 X
*/
class Solution {
private:
    int get(int n) {
        if (!(n & 1)) {
            return -1;
        }
        int now = 1;
        while (n & now) {
            now <<= 1;
            // printf("now = %d\n", now);
        }
        return n ^ (now >> 1);
    }
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = get(nums[i]);  // 是nums[i]!!! 刚开始又写成i了
        }
        return ans;
    }

    int test_get(int n) {
        return get(n);
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
23

*/
int main() {
    int n;
    while (cin >> n) {
        Solution sol;
        cout << sol.test_get(n) << endl;
    }
    return 0;
}
#endif