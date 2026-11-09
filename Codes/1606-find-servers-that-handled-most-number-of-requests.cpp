/*
 * @Author: LetMeFly
 * @Date: 2026-11-09 21:28:34
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-09 21:42:20
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available(views::iota(0, k).begin(), views::iota(0, k).end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> working;  // [<time_available, id>, ...
        int n = arrival.size();
        vector<int> cnt(k);
        for (int i = 0; i < n; i++) {
            int arrive = arrival[i];
            while (!working.empty()) {
                auto &&[time_available, id] = working.top();
                if (time_available > arrive) {
                    break;
                }
                available.insert(id);
                working.pop();
            }
            if (available.empty()) {
                continue;
            }
            set<int>::iterator it = available.lower_bound(i % k);
            if (it == available.end()) {
                it = available.begin();
            }
            int id = *it;
            available.erase(it);
            cnt[id]++;
            int cost = load[i];
            working.push({arrive + cost, id});
        }
        int max_times = *ranges::max_element(cnt);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (cnt[i] == max_times) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
