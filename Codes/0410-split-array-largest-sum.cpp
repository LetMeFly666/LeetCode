/*
 * @Author: LetMeFly
 * @Date: 2024-01-21 13:16:50
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-01-21 13:26:47
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool check(vector<int>& nums, int k, int s) {
        int cnt = 0;
        for (int t : nums) {
            if (t > s) {
                return false;
            }
            if (t + cnt > s) {
                k--;
                cnt = 0;
            }
            cnt += t;
        }
        return --k >= 0;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int l = 0, r = accumulate(nums.begin(), nums.end(), 0) + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(nums, k, mid)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};

#ifdef _WIN32
/*
[7,2,5,10,8] 2

*/
int main() {
    string s;
    int t;
    while (cin >> s >> t) {
        vector<int> v = stringToVector(s);
        Solution sol;
        cout << sol.splitArray(v, t) << endl;
    }
    return 0;
}
#endif