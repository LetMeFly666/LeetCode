/*
 * @Author: LetMeFly
 * @Date: 2024-01-23 21:58:59
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-01-23 22:21:13
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int get1(vector<int>& nums, int oddLoc=1) {
        int evenLoc = -oddLoc;
        int ans = 1;
        int cnt = 1;
        for (int i = 0; i < nums.size(); i++) {
            int shouldAdd = i % 2 ? oddLoc : evenLoc;
            if (i + 1 == nums.size() || nums[i + 1] != nums[i] + shouldAdd || cnt == 1 && shouldAdd == -1) {
                ans = max(ans, cnt);
                cnt = 1;
            }
            else {
                cnt++;
            }
        }
        return ans;
    }
public:
    int alternatingSubarray(vector<int>& nums) {
        int ans = max(get1(nums), get1(nums, -1));
        return ans < 2 ? -1 : ans;
    }
};

#ifdef _WIN32
/*
[2,3,4,3,4]

4
*/
int main() {
    string s;
    while (cin >> s) {
        vector<int> v = stringToVector(s);
        Solution sol;
        cout << sol.alternatingSubarray(v) << endl;
    }
    return 0;
}
#endif