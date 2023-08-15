/*
 * @Author: LetMeFly
 * @Date: 2023-08-15 07:51:32
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-08-15 08:14:24
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool equal(string& s, string& toCmp, int start) {  // 返回s从下标start开始，是否与toCmp匹配
        if (start + toCmp.size() > s.size()) {
            return false;
        }
        for (int i = 0; i < toCmp.size(); i++) {
            if (s[start + i] != toCmp[i]) {
                return false;
            }
        }
        return true;
    }

public:
    string findReplaceString(string& s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<tuple<int, string, string>> v;
        for (int i = 0; i < indices.size(); i++) {
            v.push_back({indices[i], sources[i], targets[i]});
        }
        sort(v.begin(), v.end(), [](tuple<int, string, string>& a, tuple<int, string, string>& b) {
            return get<0>(a) < get<0>(b);
        });
        
        string ans;
        int nowV = 0;
        for (int i = 0; i < s.size(); i++) {
            if (nowV < v.size() && get<0>(v[nowV]) == i) {
                if (equal(s, get<1>(v[nowV]), i)) {
                    ans += get<2>(v[nowV]);
                    i += get<1>(v[nowV]).size() - 1;
                }
                else {
                    ans += s[i];
                }
                nowV++;
            }
            else {
                ans += s[i];
            }
        }
        return ans;
    }
};

#ifdef _WIN32
int main() {
    string s = "abcd";
    vector<int> a = {0, 2};
    vector<string> b = {"a", "cd"}, c = {"eee", "ffff"};
    Solution sol;
    cout << sol.findReplaceString(s, a, b, c) << endl;
    return 0;
}
#endif