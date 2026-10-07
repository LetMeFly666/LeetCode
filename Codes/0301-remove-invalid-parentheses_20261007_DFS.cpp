/*
 * @Author: LetMeFly
 * @Date: 2026-10-07 11:25:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-07 14:26:01
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int remove_left, remove_right;
    string now;
    vector<string> ans;

    void getInfo(const string& s) {
        remove_left = remove_right = 0;
        for (char c : s) {
            if (c == '(') {
                remove_left++;
            } else if (c == ')') {
                if (remove_left) {
                    remove_left--;
                } else {
                    remove_right++;
                }
            }
        }
    }

    void dfs(const string& s, int idx, int left, int left_removed, int right_removed) {
        if (idx == s.size()) {
            if (left == 0 && left_removed == remove_left && right_removed == remove_right) {
                ans.push_back(now);
            }
            return;
        }
        
        if (s[idx] == '(' && left_removed < remove_left) {
            dfs(s, idx + 1, left, left_removed + 1, right_removed);
        }
        if (s[idx] == ')' && right_removed < remove_right) {
            dfs(s, idx + 1, left, left_removed, right_removed + 1);
        }
        // don't remove
        left += s[idx] == '(' ? 1 : s[idx] == ')' ? -1 : 0;
        now.push_back(s[idx]);
        dfs(s, idx + 1, left, left_removed, right_removed);
    }
public:
    vector<string> removeInvalidParentheses(const string& s) {
        getInfo(s);
        now.reserve(s.size() - remove_left - remove_right);
        dfs(s, 0, 0, 0, 0);
        return ans;
    }
};
