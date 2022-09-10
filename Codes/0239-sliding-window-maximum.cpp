/*
 * @Author: LetMeFly
 * @Date: 2022-09-10 11:18:30
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-10 11:41:47
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> se;
        vector<int> ans(nums.size() - k + 1);
        int toLoc = 0;
        for (; toLoc < k; toLoc++) {
            se.insert(nums[toLoc]);
        }
        ans[0] = *se.rbegin();
        int fromLoc = 0;
        for (; toLoc < nums.size(); toLoc++) {
            se.erase(se.find(nums[fromLoc++]));
            se.insert(nums[toLoc]);
            ans[fromLoc] = *se.rbegin();
        }
        return ans;
    }
};

#ifdef _WIN32
int main() {
    multiset<int> mu;
    dbg(mu.size());
    mu.insert(1);
    dbg(mu.size());
    mu.insert(2);
    dbg(mu.size());
    mu.insert(1);
    dbg(mu.size());

    mu.erase(1);
    dbg(mu.size());

    mu.insert(9);
    dbg(mu.size());
    mu.insert(9);
    dbg(mu.size());
    mu.erase(mu.find(9));
    dbg(mu.size());

    system("pause");
    return 0;
}
#endif