/*
 * @Author: LetMeFly
 * @Date: 2023-10-13 09:27:50
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-13 09:36:44
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_set<int> whichRained;
        vector<int> todolist;
        int cnt0 = 0;
        for (int t : rains) {
            if (!t) {
                cnt0++;
                continue;
            }
            if (whichRained.count(t)) {
                if (cnt0 <= 0) {
                    return {};
                }
                todolist.push_back(t);
                cnt0--;
            }
            else {
                whichRained.insert(t);
            }
        }
        vector<int> ans(rains.size());
        int dotowho = 0;
        for (int i = 0; i < rains.size(); i++) {
            if (rains[i]) {
                ans[i] = -1;
            }
            else {
                if (dotowho >= todolist.size()) {
                    ans[i] = 1;  // 随便选一个抽水就行
                }
                else {
                    ans[i] = todolist[dotowho++];
                }
            }
        }
        return ans;
    }
};