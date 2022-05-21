/*
 * @Author: LetMeFly
 * @Date: 2021-10-19 23:38:56
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-10-19 23:43:55
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ma;
        for (int i = 0; i < nums.size(); i++) {
            ma[nums[i]] = i + 1;
        }
        for (int i = 0; i < nums.size(); i++) {
            int index = ma[target - nums[i]];
            if (index && index != i + 1) {
                vector<int> ans;
                ans.push_back(i);
                ans.push_back(index - 1);
                return ans;
            }
        }
        vector<int> MoDeBiYaoDeDongXi;
        return MoDeBiYaoDeDongXi;
    }
};