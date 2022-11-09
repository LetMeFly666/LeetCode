/*
 * @Author: LetMeFly
 * @Date: 2022-08-07 11:42:50
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-07 14:15:36
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
#define dbg(x) cout << #x << " = " << x << endl
#endif

struct proc {
    int num;
    int timeStamp;
    bool isBegin;
};

bool cmp(const proc& a, const proc& b) {
    if (a.timeStamp == b.timeStamp) {  // 如果这一刻同时有开始和结束，那么就先处理结束的
        return !a.isBegin;
    }
    return a.timeStamp < b.timeStamp;
}

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n);
        vector<proc> v;
        for (string& s : logs) {
            proc thisP;
            vector<int> twoColons;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == ':')
                    twoColons.push_back(i);
            }
            thisP.num = atoi(s.substr(0, twoColons[0]).c_str());
            thisP.isBegin = s[twoColons[0] + 1] == 's';
            thisP.timeStamp = atoi(s.substr(twoColons[1] + 1, s.size() - twoColons[1] - 1).c_str());
            v.push_back(thisP);
            // dbg(thisP.num);
            // dbg(thisP.isBegin);
            // dbg(thisP.timeStamp);
        }
        // sort(v.begin(), v.end(), cmp);  // 题解中都不sort
        stack<int> executing;
        int lastTime;
        for (int i = 0; i < v.size(); i++) {
            // dbg(executing.size());  //*************
            if (v[i].isBegin) {
                if (executing.size()) {
                    int lastNum = executing.top();
                    ans[lastNum] += v[i].timeStamp - lastTime;
                    // printf("lastNum = %d, v[i].timeStamp = %d, lastTime = %d\n", lastNum, v[i].timeStamp, lastTime);  //**************
                }
                executing.push(v[i].num);
                lastTime = v[i].timeStamp;
            }
            else {
                int lastNum = executing.top();
                ans[lastNum] += v[i].timeStamp - lastTime + 1;
                // printf("lastNum = %d, v[i].timeStamp = %d, lastTime = %d, +1\n", lastNum, v[i].timeStamp, lastTime);  //**************
                executing.pop();
                lastTime = v[i].timeStamp + 1;
            }
        }
        return ans;
    }
};


/*
2
["0:start:0","1:start:2","1:end:5","0:end:6"]

3 4
*/
/*
1
["0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"]


*/
#ifdef _WIN32
int main() {
    int n;
    string s;
    while (cin >> n >> s) {
        Solution sol;
        vector<string> v = stringToVectorStringWithQuots(s);
        debug(sol.exclusiveTime(n, v));
    }
    return 0;
}
#endif