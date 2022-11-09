/*
 * @Author: LetMeFly
 * @Date: 2022-09-27 08:39:14
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-27 08:49:54
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error  // 能和123构成回文的不只是321和21，还能是44321等
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> ma;
        for (int i = 0; i < words.size(); i++) {
            ma[words[i]] = i;
        }
        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++) {
            string reversed;
            for (char& c : words[i]) {
                reversed = c + reversed;
            }
            if (ma.count(reversed)) {
                int j = ma[reversed];
                if (i != j) {
                    ans.push_back({i, j});
                }
            }

            if (words[i].size() == 1) {
                continue;
            }

            reversed.clear();
            for (int j = 0; j < words[i].size() - 1; j++) {
                reversed = words[i][j] + reversed;
            }
            if (ma.count(reversed)) {
                int j = ma[reversed];
                if (i != j) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry  // Copy
struct Trie {
    struct node {
        int ch[26];
        int flag;
        node() {
            flag = -1;
            memset(ch, 0, sizeof(ch));
        }
    };

    vector<node> tree;

    Trie() { tree.emplace_back(); }

    void insert(string& s, int id) {
        int len = s.length(), add = 0;
        for (int i = 0; i < len; i++) {
            int x = s[i] - 'a';
            if (!tree[add].ch[x]) {
                tree.emplace_back();
                tree[add].ch[x] = tree.size() - 1;
            }
            add = tree[add].ch[x];
        }
        tree[add].flag = id;
    }

    vector<int> query(string& s) {
        int len = s.length(), add = 0;
        vector<int> ret(len + 1, -1);
        for (int i = 0; i < len; i++) {
            ret[i] = tree[add].flag;
            int x = s[i] - 'a';
            if (!tree[add].ch[x]) {
                return ret;
            }
            add = tree[add].ch[x];
        }
        ret[len] = tree[add].flag;
        return ret;
    }
};

class Solution {
public:
    vector<pair<int, int>> manacher(string& s) {
        int n = s.length();
        string tmp = "#";
        tmp += s[0];
        for (int i = 1; i < n; i++) {
            tmp += '*';
            tmp += s[i];
        }
        tmp += '!';
        int m = n * 2;
        vector<int> len(m);
        vector<pair<int, int>> ret(n);
        int p = 0, maxn = -1;
        for (int i = 1; i < m; i++) {
            len[i] = maxn >= i ? min(len[2 * p - i], maxn - i) : 0;
            while (tmp[i - len[i] - 1] == tmp[i + len[i] + 1]) {
                len[i]++;
            }
            if (i + len[i] > maxn) {
                p = i, maxn = i + len[i];
            }
            if (i - len[i] == 1) {
                ret[(i + len[i]) / 2].first = 1;
            }
            if (i + len[i] == m - 1) {
                ret[(i - len[i]) / 2].second = 1;
            }
        }
        return ret;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie trie1, trie2;

        int n = words.size();
        for (int i = 0; i < n; i++) {
            trie1.insert(words[i], i);
            string tmp = words[i];
            reverse(tmp.begin(), tmp.end());
            trie2.insert(tmp, i);
        }

        vector<vector<int>> ret;
        for (int i = 0; i < n; i++) {
            const vector<pair<int, int>>& rec = manacher(words[i]);

            const vector<int>& id1 = trie2.query(words[i]);
            reverse(words[i].begin(), words[i].end());
            const vector<int>& id2 = trie1.query(words[i]);

            int m = words[i].size();

            int all_id = id1[m];
            if (all_id != -1 && all_id != i) {
                ret.push_back({i, all_id});
            }
            for (int j = 0; j < m; j++) {
                if (rec[j].first) {
                    int left_id = id2[m - j - 1];
                    if (left_id != -1 && left_id != i) {
                        ret.push_back({left_id, i});
                    }
                }
                if (rec[j].second) {
                    int right_id = id1[j];
                    if (right_id != -1 && right_id != i) {
                        ret.push_back({i, right_id});
                    }
                }
            }
        }
        return ret;
    }
};
#endif  // FirstTry