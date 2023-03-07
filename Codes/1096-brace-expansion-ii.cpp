/*
 * @Author: LetMeFly
 * @Date: 2023-03-07 15:11:03
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-07 16:20:51
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Half
vector<string> operator*(vector<string>& a, vector<string>& b) {
    vector<string> ans;
    for (string& sa : a) {
        for (string& sb : b) {
            ans.push_back(sa + sb);
        }
    }
    return ans;
}

class Solution {
public:
    vector<string> braceExpansionII(string& expression) {
        set<string> se;
        int lastLoc = 0;
        vector<string> v;
        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == ',') {
                v.push_back(expression.substr(lastLoc, i - lastLoc));
                lastLoc = i + 1;
            }
        }
        for (string& s : v) {
            se.insert(s);
        }
        vector<string> ans;
        for (const string& s : se) {
            ans.push_back(s);
        }
        return ans;
    }
};
#else  // FirstTry
#ifdef SecondTry  // Half
vector<string> operator*(vector<string> a, vector<string> b) {
    vector<string> ans;
    for (string& sa : a) {
        for (string& sb : b) {
            ans.push_back(sa + sb);
        }
    }
    return ans;
}

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        // split by {}
        vector<int> splitLocations;
        int leftHalf = 0;
        int startFrom = 0;
        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == '{') {
                if (!leftHalf) {  // 非{中{
                    if (startFrom != i) {
                        splitLocations.push_back(i);
                    }
                }
                leftHalf++;
            }
            else if (expression[i] == '}') {
                leftHalf--;
            }

        }
    }
};
#else  // SecondTry
// ThirdTry  // Error
vector<string> operator*(vector<string> a, vector<string> b) {
    vector<string> ans;
    for (string& sa : a) {
        for (string& sb : b) {
            ans.push_back(sa + sb);
        }
    }
    return ans;
}

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        stack<vector<string>> st;
        st.push({});
        int fromLoc = 0;
        for (int i = 0; i <= expression.size(); i++) {
            if (i == expression.size() || expression[i] == ',') {
                st.top().push_back(expression.substr(fromLoc, i - fromLoc));
                fromLoc = i + 1;
            }
            else if (expression[i] == '{') {
                if (i > fromLoc) {
                    st.top().push_back(expression.substr(fromLoc, i - fromLoc));
                }
                st.push({});
                fromLoc = i + 1;
            }
            else if (expression[i] == '}') {
                st.top().push_back(expression.substr(fromLoc, i - fromLoc));
                fromLoc = i + 1;
                vector<string> top1 = st.top();
                st.pop();
                vector<string> top2 = st.top();
                st.pop();
                st.push(top1 * top2);
            }
        }
        // return
        // vector<string> ans;
        // while (st.size()) {
        //     ans.insert(ans.end(), st.top().begin(), st.top().end());
        //     st.pop();
        // }
        vector<string> ans = st.top();
        sort(ans.begin(), ans.end());
        unique(ans.begin(), ans.end());
        return ans;
    }
};
#endif  // SecondTry
#endif  // FirstTry

#ifdef _WIN32
/*
{a,b}{c,{d,e}}

*/
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        debug(sol.braceExpansionII(s));
    }
    return 0;
}
#endif