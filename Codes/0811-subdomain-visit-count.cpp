/*
 * @Author: LetMeFly
 * @Date: 2022-10-05 20:32:45
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-05 20:36:24
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> ma;
        for (string& s : cpdomains) {
            int locSpace = s.find(' ');
            int times = atoi(s.substr(0, locSpace).c_str());
            string domain = s.substr(locSpace + 1, s.size() - locSpace - 1);
            ma[domain] += times;
            for (int i = 0; i < domain.size(); i++) {
                if (domain[i] == '.') {
                    ma[domain.substr(i + 1, domain.size() - i - 1)] += times;
                }
            }
        }
        vector<string> ans;
        for (auto& [domain, times] : ma) {
            ans.push_back(to_string(times) + ' ' + domain);
        }
        return ans;
    }
};