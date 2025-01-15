/*
 * @Author: LetMeFly
 * @Date: 2025-01-15 13:38:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-15 13:58:45
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        make_heap(nums.begin(), nums.end(), greater<>());
        while (nums[0] < k) {
            int x = nums[0];
            pop_heap(nums.begin(), nums.end() - ans, greater<>());
            int y = nums[0];
            pop_heap(nums.begin(), nums.end() - (ans + 1), greater<>());
            nums[nums.size() - ans - 2] = min((unsigned)k, (unsigned)x + (unsigned)y + (unsigned)min(x, y));
            push_heap(nums.begin(), nums.end() - (ans + 1), greater<>());
            ans++;
            #ifdef _WIN32
            dbg(x);
            dbg(y);
            debug(nums);
            #endif
        }
        return ans;
    }
};

#ifdef _WIN32
/*
[2,11,10,1,3]
10

2
*/
int main() {
    string s;
    int k;
    Solution sol;
    while (cin >> s >> k) {
        vector<int> v = stringToVector(s);
        cout << sol.minOperations(v, k) << endl;
    }
    return 0;
}
#endif