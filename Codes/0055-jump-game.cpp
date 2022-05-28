/*
 * @Author: LetMeFly
 * @Date: 2022-05-28 16:50:18
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-28 16:55:26
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;  // 当前最远可达距离
        for (int i = 0; i < nums.size(); i++) {
            if (i > farthest) {  // 到不了这一点
                return false;
            }
            farthest = max(farthest, i + nums[i]);
        }
        return farthest >= nums.size() - 1;
    }
};

#ifdef _WIN32
int main() {
    string s;
    while (cin >> s) {
        vector<int> v = stringToVector(s);
        Solution sol;
        cout << sol.canJump(v) << endl;
    }
    return 0;
}
#endif