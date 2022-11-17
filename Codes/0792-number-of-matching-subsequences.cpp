/*
 * @Author: LetMeFly
 * @Date: 2022-11-17 09:26:22
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-17 11:16:09
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
#define dbg(x) cout << #x << " = " << x << endl
#endif

#ifdef FirstTry  // 二分查找
class Solution {
public:
    int numMatchingSubseq(string& s, vector<string>& words) {
        vector<int> a[26];
        for (int i = 0; i < s.size(); i++)
            a[s[i] - 'a'].push_back(i);
        int ans = 0;
        for (string& word : words) {
            bool ok = true;
            int loc = -1;
            for (char c : word) {
                vector<int>::iterator it = lower_bound(a[c - 'a'].begin(), a[c - 'a'].end(), loc + 1);
                if (it == a[c - 'a'].end()) {
                    ok = false;
                    break;
                }
                loc = *it;
            }
            ans += ok;
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry  // 多指针
class Solution {
public:
    int numMatchingSubseq(string& s, vector<string>& words) {
        queue<int> q[26];  // q[0]: 下一个是'a'的word在words中的index
        for (int index = 0; index < words.size(); index++)
            q[words[index][0] - 'a'].push(index);
        vector<int> loc(words.size(), 0);  // loc[0]: words[0]该匹配哪个单词了
        int ans = 0;
        for (char c : s) {
            for (int i = q[c - 'a'].size(); i > 0; i--) {
                int index = q[c - 'a'].front();
                q[c - 'a'].pop();
                loc[index]++;
                if (loc[index] == words[index].size()) {
                    ans++;
                    continue;
                }
                // dbg(index);  //**********
                // dbg(words[index]);  //********
                // dbg(loc[index]);  //*********
                // dbg(words[index][loc[index]]);  //**************
                // dbg(words[index][loc[index]] - 'a');  //*********
                q[words[index][loc[index]] - 'a'].push(index);
            }
        }
        return ans;
    }
};
#endif  // FirstTry