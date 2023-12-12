/*
 * @Author: LetMeFly
 * @Date: 2023-12-12 20:35:48
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-12 20:47:06
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        stack<int> st1, st2;
        vector<int> ans(nums.size(), -1);
        for (int i = 0; i < nums.size(); i++) {
            while (st2.size() && nums[st2.top()] < nums[i]) {
                ans[st2.top()] = nums[i];
                st2.pop();
            }
            stack<int> temp;
            while (st1.size() && nums[st1.top()] < nums[i]) {
                temp.push(st1.top());
                st1.pop();
            }
            st1.push(i);
            while (temp.size()) {
                st2.push(temp.top());
                temp.pop();
            }
        }
        return ans;
    }
};

#ifdef _WIN32
/*
[2,4,0,9,6]

*/
/*
[11,13,15,12,0,15,12,11,9]

*/
int main() {
    string s;
    Solution sol;
    while (cin >> s) {
        vector<int> v = stringToVector(s);
        debug(sol.secondGreaterElement(v));
    }
    return 0;
}
#endif