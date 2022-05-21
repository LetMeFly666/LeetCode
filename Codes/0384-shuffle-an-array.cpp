/*
 * @Author: LetMeFly
 * @Date: 2021-11-22 10:21:54
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-11-22 10:33:54
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
class Solution {
private:
    vector<int> nums;
    int length;
public:
    Solution(vector<int>& nums) : nums(nums), length(nums.size()) {
        srand(time(nullptr));
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        vector<int> ans;
        vector<int> se = nums;
        while (se.size()) {
            int remain = se.size();
            int th = rand() % remain;
            ans.push_back(se[th]);
            se.erase(se.begin() + th);
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */