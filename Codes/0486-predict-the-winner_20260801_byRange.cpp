/*
 * @Author: LetMeFly
 * @Date: 2026-08-01 18:34:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-01 19:00:00
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int play(vector<int>& nums, int l, int r) {
        if (l == r) {
            return nums[l];
        }
        return max(nums[l] - play(nums, l + 1, r), nums[r] - play(nums, l, r + 1));
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        return play(nums, 0, nums.size() - 1) >= 0;
    }
};

#ifdef _DEBUG
/*
[1,567,1,1,99,100]

true
*/
int main() {
    string s;
    while (cin >> s) {
        vector<int> v = stringToVector(s);
        Solution sol;
        cout << sol.predictTheWinner(v) << endl;
    }
    return 0;
}
#endif
