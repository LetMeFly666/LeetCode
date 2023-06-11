/*
 * @Author: LetMeFly
 * @Date: 2023-06-10 17:54:46
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-06-10 18:03:41
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int string2num(string& s) {
        char mc = s[0];
        for (char c : s) {
            mc = min(mc, c);
        }
        return count(s.begin(), s.end(), mc);
    }

public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> times(words.size());
        for (int i = 0; i < words.size(); i++) {
            times[i] = string2num(words[i]);
        }
        sort(times.begin(), times.end());
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = times.end() - upper_bound(times.begin(), times.end(), string2num(queries[i]));
        }
        return ans;
    }
};