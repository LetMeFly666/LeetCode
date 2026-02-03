/*
 * @Author: LetMeFly
 * @Date: 2026-02-03 21:39:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-03 22:11:11
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll minimumCost(vector<int>& nums, int k, int dist) {
        k--;
        multiset<ll> stage(nums.begin() + 1, nums.begin() + dist + 2), candidate;
        ll ans = accumulate(nums.begin(), nums.begin() + dist + 2, 0ll);
        while (stage.size() > k) {
                int retiree = *stage.rbegin();
                stage.erase(prev(stage.end()));
                ans -= retiree;
                candidate.insert(retiree);
        }

        ll nowAns = ans;
        for (int end = dist + 2; end < nums.size(); end++) {
            int in = nums[end], out = nums[end - dist - 1];
            
            // out
            multiset<ll>::iterator it = candidate.find(out);
            if (it != candidate.end()) {
                candidate.erase(it);
            } else {
                stage.erase(stage.find(out));
                nowAns -= out;
            }

            // in
            if (in < *stage.rbegin()) {
                stage.insert(in);
                nowAns += in;
            } else {
                candidate.insert(in);
            }

            // resize
            if (stage.size() == k - 1) {
                int newActor = *candidate.begin();
                candidate.erase(candidate.begin());
                stage.insert(newActor);
                nowAns += newActor;
            } else if (stage.size() == k + 1) {
                int retiree = *stage.rbegin();
                stage.erase(prev(stage.end()));
                nowAns -= retiree;
                candidate.insert(retiree);
            }

            ans = min(ans, nowAns);
        }
        return ans;
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
[1,3,2,6,4,2]
3
3

5
*/
int main() {
    string s;
    int a, b;
    while (cin >> s >> a >> b) {
        Solution sol;
        vector<int> v = stringToVector(s);
        cout << sol.minimumCost(v, a, b) << endl;
    }
    return 0;
}
#endif